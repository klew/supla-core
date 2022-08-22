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

#ifndef SRPC_ADAPTER_MOCK_H_
#define SRPC_ADAPTER_MOCK_H_

#include <gmock/gmock.h>

#include "srpc/abstract_srpc_adapter.h"

namespace testing {

class SrpcAdapterMock : public supla_abstract_srpc_adapter {
 private:
 protected:
 public:
  explicit SrpcAdapterMock(void *srpc);
  virtual ~SrpcAdapterMock(void);
  MOCK_METHOD1(set_proto_version, void(unsigned char version));
  MOCK_METHOD0(get_proto_version, unsigned char(void));

  MOCK_METHOD0(sdc_async_ping_server_result, _supla_int_t(void));

  MOCK_METHOD1(dcs_async_set_activity_timeout_result,
               _supla_int_t(TSDC_SuplaSetActivityTimeoutResult *result));

  MOCK_METHOD1(sdc_async_get_registration_enabled_result,
               _supla_int_t(TSDC_RegistrationEnabled *reg_enabled));

  MOCK_METHOD1(sc_async_scene_pack_update,
               _supla_int_t(TSC_SuplaScenePack *scene_pack));
  MOCK_METHOD1(sc_async_scene_state_pack_update,
               _supla_int_t(TSC_SuplaSceneStatePack *scene_status_pack));

  MOCK_METHOD1(sd_async_get_firmware_update_url_result,
               _supla_int_t(TSD_FirmwareUpdate_UrlResult *result));
};

} /* namespace testing */

#endif /* SRPC_ADAPTER_MOCK_H_ */
