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

#ifndef MQTT_CLIENTLIBRARYADAPTER_MOCK_H_
#define MQTT_CLIENTLIBRARYADAPTER_MOCK_H_

#include <list>
#include <string>
#include "mqtt_client_library_adapter.h"

typedef struct {
  char *topic_name;
  char *message;
  size_t message_size;
} _mqtt_test_message_t;

class MqttClientLibraryAdapterMock : public supla_mqtt_client_library_adapter {
 private:
  supla_mqtt_client *supla_client_instance;
  bool connected;
  void *lck;
  std::list<_mqtt_test_message_t> published_messages;
  std::list<std::string> subscribed_messages;
  std::list<std::string> unsubscribed_messages;

 public:
  explicit MqttClientLibraryAdapterMock(supla_mqtt_client_settings *settings);
  ~MqttClientLibraryAdapterMock(void);
  virtual void client_connect(supla_mqtt_client *supla_client_instance);
  virtual bool is_connected(void);
  virtual void iterate(void);
  virtual void disconnect(void);
  virtual void cleanup(void);
  virtual void raise_event(void);
  virtual bool subscribe(const char *topic_name, QOS_Level max_qos_level);
  virtual bool unsubscribe(const char *topic_name);
  virtual bool publish(const char *topic_name, const void *message,
                       size_t message_size, QOS_Level qos_level, bool retain);
  void published_clear(void);
  int published_count(void);
  _mqtt_test_message_t published_pop(void);

  void subscribed_clear(void);
  int subscribed_count(void);
  std::string subscribed_pop(void);

  void unsubscribed_clear(void);
  int unsubscribed_count(void);
  std::string unsubscribed_pop(void);

  void on_message_received(const char *topic_name, const char *message);
};

#endif /* MQTT_CLIENTLIBRARYADAPTER_MOCK_H_ */
