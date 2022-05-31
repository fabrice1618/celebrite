#include <stdio.h>
#include <stdlib.h>

#include "database.h"
#include "database_config.h"

MYSQL * database_open(MYSQL *cnx)
{
    cnx = mysql_init(NULL);

    if (cnx == NULL) {
        database_exit_error(cnx);
    }

    if (mysql_real_connect(cnx, DB_HOST, DB_USER, DB_PWD, DB_DB, 0, NULL, 0) == NULL) {
        database_exit_error(cnx);
    }

    return(cnx);
}

void database_close(MYSQL *cnx)
{
    mysql_close(cnx);
}

void database_exit_error(MYSQL *cnx)
{
    fprintf(stderr, "%s\n", mysql_error(cnx));

    if (cnx != NULL) {
        mysql_close(cnx);
    }
    
    exit(EXIT_FAILURE);
}
