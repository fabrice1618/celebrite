#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "database.h"
#include "database_config.h"

int database_query(MYSQL *cnx, char *query_format, ...)
{
    va_list ap;
    char *src;
    char car;
    int param_int;
    char param_int_str[20];
    char *param_str;
    char query[QUERY_MAX_SIZE];
    char *dest;
    char *p;
    int query_size = 0;
    static int query_size_max = 0;

    src = query_format;
    dest = query;

    va_start(ap, query_format);
    while (*src != '\0') {
        car = *src++;
        //printf(">%c\n", car);

        if (car == '%') {
            switch (*src++)
            {
            case 's': // string 
                param_str = va_arg(ap, char *);
                //printf("string %s\n", param_str);
                p = param_str;
                break;
            case 'd': // int 
                param_int = va_arg(ap, int);
                sprintf( param_int_str, "%d", param_int);
                p = param_int_str;
                //printf("int %d\n", param_int);
                break;
            }

            while (*p != '\0') {
                *dest++ = *p++;
                query_size++;
            }
            
        } else {
            *dest++ = car;
            query_size++;
        }

    }
    *dest++ = '\0';
    va_end(ap);

    if (query_size > query_size_max) {
        query_size_max = query_size;
    }
    printf("query: %s\n", query);
    printf("query size max: %d\n", query_size_max);

    // Execution de la requete
    if ( mysql_query(cnx, query) ) {
        database_exit_error(cnx);
    }
    return(0);
}

MYSQL *database_open(MYSQL *cnx)
{
    cnx = mysql_init(NULL);

    if (cnx == NULL)
    {
        database_exit_error(cnx);
    }

    if (mysql_real_connect(cnx, DB_HOST, DB_USER, DB_PWD, DB_DB, 0, NULL, 0) == NULL)
    {
        database_exit_error(cnx);
    }

    return (cnx);
}

void database_close(MYSQL *cnx)
{
    mysql_close(cnx);
}

void database_exit_error(MYSQL *cnx)
{
    fprintf(stderr, "%s\n", mysql_error(cnx));

    if (cnx != NULL)
    {
        mysql_close(cnx);
    }

    exit(EXIT_FAILURE);
}
