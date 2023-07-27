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

#include "abstract_common_channel_properties.h"

#include "jsonconfig/channel/hvac_config.h"
#include "proto.h"

using std::vector;

supla_abstract_common_channel_properties::
    supla_abstract_common_channel_properties(void) {}

supla_abstract_common_channel_properties::
    ~supla_abstract_common_channel_properties(void) {}

void supla_abstract_common_channel_properties::add_relation(
    std::vector<supla_channel_relation> *relations, int channel_id,
    int parent_id, short relation_type) {
  if (!channel_id || !parent_id || !relation_type) {
    return;
  }

  for (auto it = relations->begin(); it != relations->end(); ++it) {
    if (((it->get_id() == channel_id && it->get_parent_id() == parent_id) ||
         (it->get_id() == parent_id && it->get_parent_id() == channel_id)) &&
        it->get_relation_type() == relation_type) {
      return;
    }
  }

  relations->push_back(
      supla_channel_relation(channel_id, parent_id, relation_type));
}

void supla_abstract_common_channel_properties::get_channel_relations(
    vector<supla_channel_relation> *relations, e_relation_kind kind) {
  if (!relations) {
    return;
  }

  if (kind == relation_any || kind == relation_with_sub_channel) {
    switch (get_func()) {
      case SUPLA_CHANNELFNC_CONTROLLINGTHEGATEWAYLOCK:
      case SUPLA_CHANNELFNC_CONTROLLINGTHEGATE:
      case SUPLA_CHANNELFNC_CONTROLLINGTHEGARAGEDOOR:
      case SUPLA_CHANNELFNC_CONTROLLINGTHEDOORLOCK:
        add_relation(relations, get_param2(), get_id(),
                     CHANNEL_RELATION_TYPE_OPENING_SENSOR);

        add_relation(relations, get_param3(), get_id(),
                     CHANNEL_RELATION_TYPE_PARTIAL_OPENING_SENSOR);
        break;
      case SUPLA_CHANNELFNC_CONTROLLINGTHEROLLERSHUTTER:
      case SUPLA_CHANNELFNC_CONTROLLINGTHEROOFWINDOW:
        add_relation(relations, get_param2(), get_id(),
                     CHANNEL_RELATION_TYPE_OPENING_SENSOR);
        break;

      case SUPLA_CHANNELFNC_POWERSWITCH:
      case SUPLA_CHANNELFNC_LIGHTSWITCH: {
        add_relation(relations, get_param1(), get_id(),
                     CHANNEL_RELATION_TYPE_METER);
      } break;

      case SUPLA_CHANNELFNC_STAIRCASETIMER:
        add_relation(relations, get_param2(), get_id(),
                     CHANNEL_RELATION_TYPE_METER);
        break;

      case SUPLA_CHANNELFNC_HVAC_THERMOSTAT_HEAT:
      case SUPLA_CHANNELFNC_HVAC_THERMOSTAT_COOL:
      case SUPLA_CHANNELFNC_HVAC_THERMOSTAT_AUTO: {
        channel_json_config *json_config = get_json_config();
        if (json_config) {
          hvac_config config(json_config);
          TChannelConfig_HVAC hvac = {};
          if (config.get_config(&hvac)) {
            int device_id = get_device_id();

            bool find_main =
                hvac.MainThermometerChannelNo != get_channel_number();
            bool find_aux = hvac.AuxThermometerType >=
                                SUPLA_HVAC_AUX_THERMOMETER_TYPE_FLOOR &&
                            hvac.AuxThermometerType <=
                                SUPLA_HVAC_AUX_THERMOMETER_TYPE_GENERIC_COOLER;

            for_each([&](supla_abstract_common_channel_properties *props,
                         bool *will_continue) -> void {
              if (device_id == props->get_device_id()) {
                if (find_main && hvac.MainThermometerChannelNo ==
                                     props->get_channel_number()) {
                  add_relation(relations, props->get_id(), get_id(),
                               CHANNEL_RELATION_TYPE_MAIN_TERMOMETER);
                  find_main = false;
                }

                if (find_aux && hvac.AuxThermometerChannelNo ==
                                    props->get_channel_number()) {
                  add_relation(relations, props->get_id(), get_id(),
                               hvac.AuxThermometerType + 3);
                  find_aux = false;
                }
              }

              *will_continue = find_main || find_aux;
            });
          }
          delete json_config;
        }
      } break;
    }
  }

  if (kind == relation_any || kind == relation_with_parent_channel) {
    switch (get_func()) {
      case SUPLA_CHANNELFNC_OPENINGSENSOR_GATEWAY:
      case SUPLA_CHANNELFNC_OPENINGSENSOR_GATE:
      case SUPLA_CHANNELFNC_OPENINGSENSOR_GARAGEDOOR:
      case SUPLA_CHANNELFNC_OPENINGSENSOR_DOOR:
      case SUPLA_CHANNELFNC_OPENINGSENSOR_ROLLERSHUTTER:
      case SUPLA_CHANNELFNC_OPENINGSENSOR_ROOFWINDOW:
        add_relation(relations, get_id(), get_param1(),
                     CHANNEL_RELATION_TYPE_OPENING_SENSOR);

        add_relation(relations, get_id(), get_param2(),
                     CHANNEL_RELATION_TYPE_PARTIAL_OPENING_SENSOR);
        break;
      case SUPLA_CHANNELFNC_ELECTRICITY_METER:
      case SUPLA_CHANNELFNC_IC_ELECTRICITY_METER:
      case SUPLA_CHANNELFNC_IC_GAS_METER:
      case SUPLA_CHANNELFNC_IC_WATER_METER:
      case SUPLA_CHANNELFNC_IC_HEAT_METER:
        add_relation(relations, get_id(), get_param4(),
                     CHANNEL_RELATION_TYPE_METER);
        break;
      case SUPLA_CHANNELFNC_THERMOMETER:
      case SUPLA_CHANNELFNC_HUMIDITYANDTEMPERATURE: {
        int device_id = get_device_id();

        for_each([&](supla_abstract_common_channel_properties *props,
                     bool *will_continue) -> void {
          if (props->get_device_id() != device_id) {
            return;
          }
          switch (props->get_func()) {
            case SUPLA_CHANNELFNC_HVAC_THERMOSTAT_HEAT:
            case SUPLA_CHANNELFNC_HVAC_THERMOSTAT_COOL:
            case SUPLA_CHANNELFNC_HVAC_THERMOSTAT_AUTO:

              channel_json_config *json_config = props->get_json_config();
              if (json_config) {
                hvac_config config(json_config);
                TChannelConfig_HVAC hvac = {};
                if (config.get_config(&hvac)) {
                  if (hvac.MainThermometerChannelNo == get_channel_number()) {
                    add_relation(relations, get_id(), props->get_id(),
                                 CHANNEL_RELATION_TYPE_MAIN_TERMOMETER);
                  }

                  if (hvac.AuxThermometerType >=
                          SUPLA_HVAC_AUX_THERMOMETER_TYPE_FLOOR &&
                      hvac.AuxThermometerType <=
                          SUPLA_HVAC_AUX_THERMOMETER_TYPE_GENERIC_COOLER &&
                      hvac.AuxThermometerChannelNo == get_channel_number()) {
                    add_relation(relations, get_id(), props->get_id(),
                                 hvac.AuxThermometerType + 3);
                  }
                }
                delete json_config;
              }

              break;
          }
        });
      }

      break;
    }
  }
}

vector<supla_channel_relation>
supla_abstract_common_channel_properties::get_channel_relations(
    e_relation_kind kind) {
  vector<supla_channel_relation> result;
  get_channel_relations(&result, kind);
  return result;
}
