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

#include "conn/call_handler/get_user_localtime.h"

#include <stdlib.h>
#include <string.h>

#include <memory>

#include "conn/connection_dao.h"
#include "log.h"
#include "proto.h"

using std::shared_ptr;

supla_ch_get_user_localtime::supla_ch_get_user_localtime(void)
    : supla_abstract_srpc_call_handler() {}

supla_ch_get_user_localtime::~supla_ch_get_user_localtime() {}

bool supla_ch_get_user_localtime::handle_call(
    shared_ptr<supla_abstract_connection_object> object,
    supla_abstract_srpc_adapter* srpc_adapter, TsrpcReceivedData* rd,
    unsigned int call_id, unsigned char proto_version) {
  if (call_id != SUPLA_DCS_CALL_GET_USER_LOCALTIME) {
    return CH_UNHANDLED;
  }

  if (object->is_registered()) {
    TSDC_UserLocalTimeResult result = {};

    supla_connection_dao dao;

    if (!dao.get_user_localtime(object->get_user_id(), &result)) {
      memset(&result, 0, sizeof(TSDC_UserLocalTimeResult));
    }

    srpc_adapter->sdc_async_get_user_localtime_result(&result);
  }

  return CH_HANDLED;
}
