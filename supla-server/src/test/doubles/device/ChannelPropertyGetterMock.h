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

#ifndef VALUE_GETTER_MOCK_H_
#define VALUE_GETTER_MOCK_H_

#include <gmock/gmock.h>

#include "device/abstract_channel_property_getter.h"

namespace testing {

class ChannelPropertyGetterMock
    : public supla_abstract_channel_property_getter {
 protected:
 public:
  ChannelPropertyGetterMock(void);
  virtual ~ChannelPropertyGetterMock(void);

  MOCK_METHOD5(_get_value,
               supla_channel_value *(int user_id, int device_id, int channel_id,
                                     int *func, bool *online));
};

} /* namespace testing */

#endif /* VALUE_GETTER_MOCK_H_ */