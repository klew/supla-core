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

#ifndef PUSH_NOTIFICATION_DELIVERY_TASK_H_
#define PUSH_NOTIFICATION_DELIVERY_TASK_H_

#include <string>

#include "http/asynctask_http_request.h"
#include "push/pn_gateway_access_token_provider.h"
#include "push/push_notification.h"

class supla_pn_delivery_task : public supla_asynctask_http_request {
 private:
  supla_push_notification *push;
  supla_pn_gateway_access_token_provider *token_provider;

 protected:
  virtual bool make_request(supla_abstract_curl_adapter *curl_adapter);
  virtual std::string get_name(void);

 public:
  supla_pn_delivery_task(
      int user_id, supla_asynctask_queue *queue,
      supla_abstract_asynctask_thread_pool *pool, supla_push_notification *push,
      supla_pn_gateway_access_token_provider *token_provider);
  virtual ~supla_pn_delivery_task(void);
  virtual bool will_use_database(void);
};

#endif /* PUSH_NOTIFICATION_DELIVERY_TASK_H_ */