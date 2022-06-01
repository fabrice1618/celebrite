#ifndef DATABASE_H
#define DATABASE_H

#include <mysql/mysql.h>

#define QUERY_MAX_SIZE 512

MYSQL *database_open(MYSQL *cnx);
void database_close(MYSQL *cnx);
void database_exit_error(MYSQL *cnx);
int database_query(MYSQL *cnx, char *query, ...);

#endif