#include <stdio.h>
#include <string.h>
#include <mysql/mysql.h>

#include "database.h"
#include "metiers_modele.h"

#define QUERY_INSERT "INSERT INTO metiers(metier) VALUES('%s')"
#define QUERY_READ "SELECT * FROM metiers WHERE metier_id = %d"
#define QUERY_UPDATE "UPDATE metiers SET metier = '%s' WHERE metier_id = %d"
#define QUERY_DELETE "DELETE FROM metiers WHERE metier_id = %d"
#define QUERY_EXISTS "SELECT * FROM metiers WHERE metier_id = %d)"

int metiers_create(MYSQL *cnx, char *metier)
{
    char query[250];

    sprintf(query, QUERY_INSERT, metier);
    printf("Query: %s\n", query);

    if (mysql_query(cnx, query))
    {
        database_exit_error(cnx);
    }

    int id = mysql_insert_id(cnx);

    return (id);
}

int metiers_read(MYSQL *cnx, int metier_id, char *metier)
{
    char query[250];

    sprintf(query, QUERY_READ, metier_id);
    printf("Query: %s\n", query);

    if (mysql_query(cnx, query))
    {
        database_exit_error(cnx);
    }

    MYSQL_RES *result = mysql_store_result(cnx);
    if (result == NULL)
    {
        database_exit_error(cnx);
    }

    //    int num_fields = mysql_num_fields(result);

    MYSQL_ROW row;
    row = mysql_fetch_row(result);
    strcpy(metier, row[1] ? row[1] : "");

    mysql_free_result(result);

    return (row[0] ? 0 : 1);
}

int metiers_update(MYSQL *cnx, int metier_id, char *metier)
{
    char query[250];

    sprintf(query, QUERY_UPDATE, metier, metier_id);
    printf("Query: %s\n", query);

    if (mysql_query(cnx, query))
    {
        database_exit_error(cnx);
    }

//    int id = mysql_insert_id(cnx);

    return (0);
}

int metiers_delete(MYSQL *cnx, int metier_id)
{
    char query[250];

    sprintf(query, QUERY_DELETE, metier_id);
    printf("Query: %s\n", query);

    if (mysql_query(cnx, query))
    {
        database_exit_error(cnx);
    }

//    int id = mysql_insert_id(cnx);

    return (0);
}

int metiers_existe( MYSQL *cnx, int metier_id, char *metier)
{
    char query[250];

    sprintf(query, QUERY_EXISTS, metier_id);
    printf("Query: %s\n", query);

    if (mysql_query(cnx, query)) {
        database_exit_error(cnx);
    }

    MYSQL_RES *result = mysql_store_result(cnx);
    if (result == NULL) {
        database_exit_error(cnx);
    }

//    MYSQL_ROW row;
//    row = mysql_fetch_row(result);
//    // strcpy(metier_id, row[1] ? row[1] : "");
//    strcpy(metier, row[2] ? row[2] : "");

    int existe = mysql_num_rows(result) == 0 ? 1 : 0;

    mysql_free_result(result);
/*    
    int existe = mysql_num_rows(result);

    if (existe == 0) {
        return(1);
    }
*/
    return(existe);
}