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

#ifndef CONNECTION_OBJECTS_H_
#define CONNECTION_OBJECTS_H_

#include <functional>
#include <memory>
#include <vector>

#include "conn/connection_object.h"
#include "safearray.h"

class supla_connection_objects {
 private:
  void *lck;
  std::vector<std::shared_ptr<supla_connection_object> > objects;

 protected:
  void lock(void);
  void unlock(void);
  void for_each(
      std::function<bool(std::shared_ptr<supla_connection_object> obj)>
          on_object);
  std::vector<std::shared_ptr<supla_connection_object> > get_all(void);
  bool exists(std::shared_ptr<supla_connection_object> obj);
  bool add(std::shared_ptr<supla_connection_object> obj);
  std::shared_ptr<supla_connection_object> find_by_id(int id);
  std::shared_ptr<supla_connection_object> find_by_guid(
      const char guid[SUPLA_GUID_SIZE]);

 public:
  supla_connection_objects();
  virtual ~supla_connection_objects();
  int count(void);
  bool terminate_all(void);
  bool terminate(int id);

  //  void releasePtr(supla_connection_object *cd);
  //
  //  void moveAllToTrash();
  //  void moveToTrash(supla_connection_object *cd);
  //  bool emptyTrash(void);
  //  bool emptyTrash(unsigned char timeout_sec);
  //  bool deleteAll(unsigned char timeout_sec);
  //  supla_connection_object *get(int idx);
};

#endif /* CONNECTION_OBJECTS_H_ */
