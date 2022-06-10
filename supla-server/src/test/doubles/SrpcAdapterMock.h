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

#include "abstract_srpc_adapter.h"

namespace testing {

class SrpcAdapterMock : public supla_abstract_srpc_adapter {
 private:
 protected:
 public:
  explicit SrpcAdapterMock(void *srpc);
  virtual ~SrpcAdapterMock(void);
  MOCK_METHOD0(get_proto_version, char(void));
  MOCK_METHOD1(sc_async_scene_pack_update,
               _supla_int_t(TSC_SuplaScenePack *scene_pack));
  MOCK_METHOD1(sc_async_scene_status_pack_update,
               _supla_int_t(TSC_SuplaSceneStatusPack *scene_status_pack));
};

} /* namespace testing */

#endif /* SRPC_ADAPTER_MOCK_H_ */