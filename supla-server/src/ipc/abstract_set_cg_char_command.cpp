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

#include "ipc/abstract_set_cg_char_command.h"

supla_abstract_set_cg_char_command::supla_abstract_set_cg_char_command(
    supla_abstract_ipc_socket_adapter *socket_adapter)
    : supla_abstract_ipc_command(socket_adapter),
      command_name("SET-CG-CHAR-VALUE:") {}

const char *supla_abstract_set_cg_char_command::get_command_name(void) {
  return command_name.c_str();
}

void supla_abstract_set_cg_char_command::on_command_match(const char *params) {
  int user_id = 0;
  int group_id = 0;
  int value = 0;

  if (params) {
    sscanf(params, "%i,%i,%i", &user_id, &group_id, &value);

    supla_user *user = NULL;

    if (user_id && group_id &&
        (user = supla_user::find(user_id, false)) != NULL) {
      if (value < 0 || value > 255) {
        send_result("VALUE OUT OF RANGE");
        return;
      }

      if (set_cg_char_value(user, group_id, value)) {
        send_result("OK:", group_id);
      } else {
        send_result("FAIL:", group_id);
      }
      return;
    }
  }
  send_result("UNKNOWN:", group_id);
}
