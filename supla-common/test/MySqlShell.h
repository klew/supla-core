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

#ifndef MYSQLSHELL_H_
#define MYSQLSHELL_H_

#include <string>

namespace testing {

class MySqlShell {
 public:
  static void runSqlScript(const char *sql_dir, const char *db_host,
                           const char *db_user, const char *db_name,
                           const char *script);
  static void sqlQuery(const char *sql_dir, const char *db_host,
                       const char *db_user, const char *db_name,
                       const char *query, std::string *result);

  static void initTestDatabase(const char *sql_dir, const char *db_host,
                               const char *db_user, const char *db_name);
};

}  // namespace testing

#endif /*MYSQLSHELL_*/
