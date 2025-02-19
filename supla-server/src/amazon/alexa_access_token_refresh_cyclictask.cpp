/*
 Copyright (C) AC SOFTWARE SP. Z O.O.

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 2
 of the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

#include "alexa_access_token_refresh_cyclictask.h"

#include <memory>
#include <string>

#include "alexa_client.h"
#include "alexa_credentials_dao.h"
#include "db/abstract_db_access_provider.h"
#include "http/curl_adapter.h"
#include "user/user.h"

using std::string;
using std::vector;

supla_alexa_access_token_refresh_cyclictask::
    supla_alexa_access_token_refresh_cyclictask()
    : supla_abstract_cyclictask() {
  // Load all users who have credentials. If all user devices are offline and
  // the server is restarted, there is a risk that the token will not refresh in
  // time.

  supla_db_access_provider dba;
  supla_amazon_alexa_credentials_dao dao(&dba);

  vector<int> users = dao.get_users_with_credentials();
  for (auto it = users.cbegin(); it != users.cend(); ++it) {
    supla_user::find(*it, true);
  }
}

supla_alexa_access_token_refresh_cyclictask::
    ~supla_alexa_access_token_refresh_cyclictask() {}

unsigned int supla_alexa_access_token_refresh_cyclictask::task_interval_sec(
    void) {
  return 60;
}
bool supla_alexa_access_token_refresh_cyclictask::user_access_needed(void) {
  return true;
}

int supla_alexa_access_token_refresh_cyclictask::get_attempt_count(
    int user_id) {
  auto it = attempts.find(user_id);
  if (it != attempts.end()) {
    return it->second;
  }

  return 0;
}

void supla_alexa_access_token_refresh_cyclictask::inc_attempts(int user_id) {
  auto it = attempts.find(user_id);
  if (it == attempts.end()) {
    attempts[user_id] = 1;
  } else {
    it->second = it->second + 1;
  }
}

void supla_alexa_access_token_refresh_cyclictask::erase_attempts(int user_id) {
  auto it = attempts.find(user_id);
  if (it != attempts.end()) {
    attempts.erase(it);
  }
}

void supla_alexa_access_token_refresh_cyclictask::run(
    const vector<supla_user *> *users, supla_abstract_db_access_provider *dba) {
  supla_curl_adapter curl_adapter;

  for (auto uit = users->cbegin(); uit != users->cend(); ++uit) {
    int expires_in = (*uit)->amazonAlexaCredentials()->expires_in();
    int user_id = (*uit)->getUserID();
    string previous = (*uit)->amazonAlexaCredentials()->get_access_token();

    if (expires_in <= 300 &&
        (*uit)->amazonAlexaCredentials()->is_access_token_exists()) {
      supla_alexa_client client(0, &curl_adapter,
                                (*uit)->amazonAlexaCredentials(), "", "", "");
      client.refresh_token();

      inc_attempts(user_id);

      if (previous == (*uit)->amazonAlexaCredentials()->get_access_token()) {
        if (get_attempt_count(user_id) >= 10) {
          (*uit)->amazonAlexaCredentials()->remove();
          erase_attempts(user_id);
        }
      } else {
        erase_attempts(user_id);
      }
    }
  }
}
