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

#ifndef SUPLA_CH_ABSTRACT_REGISTER_DEVICE_H_
#define SUPLA_CH_ABSTRACT_REGISTER_DEVICE_H_

#include "conn/call_handler/abstract_register_object.h"
#include "db/abstract_db_access_provider.h"
#include "device/abstract_device_dao.h"
#include "proto.h"
#include "srpc/abstract_srpc_adapter.h"

class supla_user;
class supla_ch_abstract_register_device
    : protected supla_ch_abstract_register_object {
 private:
  char *guid;
  char *authkey;
  char *name;
  char *softver;
  unsigned char channel_count;
  TDS_SuplaRegisterDevice_C *register_device_c;
  TDS_SuplaRegisterDevice_E *register_device_e;
  int location_id;
  int device_flags;
  short manufacturer_id;
  short product_id;
  int flags;
  int device_id;

  int user_id;
  bool location_enabled;
  bool new_device;
  bool device_enabled;
  bool channels_added;
  int _location_id;
  int _original_location_id;

  bool should_rollback;

  supla_abstract_srpc_adapter *srpc_adapter;
  supla_abstract_db_access_provider *dba;
  supla_abstract_device_dao *dao;
  int client_sd;
  int client_ipv4;
  unsigned char activity_timeout;

  void send_result(int resultcode);
  bool device_auth(void);
  bool add_device(void);
  bool add_channels(void);

 protected:
  __useconds_t hold_time_on_failure_usec;
  void register_device(TDS_SuplaRegisterDevice_C *register_device_c,
                       TDS_SuplaRegisterDevice_E *register_device_e,
                       supla_abstract_srpc_adapter *srpc_adapter,
                       supla_abstract_db_access_provider *dba,
                       supla_abstract_device_dao *dao, int client_sd,
                       int client_ipv4, unsigned char activity_timeout);

  virtual void on_registraction_success(int device_id, bool channels_added) = 0;

 public:
  supla_ch_abstract_register_device(void);
  virtual ~supla_ch_abstract_register_device();
  __useconds_t get_hold_time_on_failure_usec(void);
};

#endif /* SUPLA_CH_ABSTRACT_REGISTER_DEVICE_H_*/