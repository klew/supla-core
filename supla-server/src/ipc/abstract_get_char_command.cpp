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

#include "ipc/abstract_get_char_command.h"

supla_abstract_get_char_command::supla_abstract_get_char_command(
    supla_abstract_ipc_response_agent *response_agent, char *buffer,
    unsigned int buffer_size)
    : supla_abstract_ipc_command(response_agent, buffer, buffer_size),
      command_name("GET-CHAR-VALUE:") {}

const char *supla_abstract_get_char_command::get_command_name(void) {
  return command_name.c_str();
}

void supla_abstract_get_char_command::on_command_match(const char *params) {
  int user_id = 0;
  int device_id = 0;
  int channel_id = 0;
  char value = 0;

  sscanf(params, "%i,%i,%i", &user_id, &device_id, &channel_id);

  if (user_id && device_id && channel_id) {
    bool r = get_channel_char_value(user_id, device_id, channel_id, &value);

    if (r) {
      send_result("VALUE:", (int)value);
      return;
    }
  }

  send_result("UNKNOWN:", channel_id);
}
