#ifndef DATABASE_H
#define DATABASE_H

#include <mysql.h>


MYSQL * database_open(MYSQL *cnx);
void database_close(MYSQL *cnx);
void database_exit_error(MYSQL *cnx);

#endif