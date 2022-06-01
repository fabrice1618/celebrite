#include <stdio.h>
#include <string.h>
#include <mysql/mysql.h>

#include "database.h"
//#include "celebrites_modele.h"

#define QUERY_INSERT "INSERT INTO pays(nom_pays) VALUES('%s')"
#define QUERY_READ "SELECT * FROM pays WHERE pays_id = %d"
#define QUERY_UPDATE "UPDATE pays SET nom_pays = '%s' WHERE pays_id = %d"
#define QUERY_DELETE "DELETE FROM pays WHERE pays_id = %d"
#define QUERY_EXISTS "SELECT * FROM pays WHERE pays_id = %d"

int pays_create( MYSQL *cnx, int *pays_id, char *nom_pays)
{
    char query[250];

    sprintf(query, QUERY_INSERT, nom_pays);
    printf("Query: %s\n", query);

    if ( mysql_query(cnx, query) ) {
        database_exit_error(cnx);
    }

    int id = mysql_insert_id(cnx);

    return(id);
}

int pays_read(MYSQL *cnx, int pays_id, char *nom_pays)
{
    char query[250];

    sprintf(query, QUERY_READ, pays_id);
    printf("Query: %s\n", query);

    if (mysql_query(cnx, query)) {
        database_exit_error(cnx);
    }

    MYSQL_RES *result = mysql_store_result(cnx);
    if (result == NULL) {
        database_exit_error(cnx);
    }

//    int num_fields = mysql_num_fields(result);

    MYSQL_ROW row;
    row = mysql_fetch_row(result);
//    strcpy(pays_id, row[1] ? row[1] : "");
    strcpy(nom_pays, row[1] ? row[1] : "");

    mysql_free_result(result);

    return(row[0] ? 0 : 1);
}

int pays_update( MYSQL *cnx, int pays_id, char *nom_pays)
{
    char query[250];

    sprintf(query, QUERY_UPDATE, nom_pays, pays_id);
    printf("Query: %s\n", query);

    if ( mysql_query(cnx, query) ) {
        database_exit_error(cnx);
    }

    return(0);
}

int pays_delete( MYSQL *cnx, int pays_id)
{
    char query[250];

    sprintf(query, QUERY_DELETE, pays_id);
    printf("Query: %s\n", query);

    if ( mysql_query(cnx, query) ) {
        database_exit_error(cnx);
    }

    return(0);
}

int pays_existe( MYSQL *cnx, int pays_id)
{
    char query[250];
    int existe;

    sprintf(query, QUERY_EXISTS, pays_id);
    printf("Query: %s\n", query);

    if (mysql_query(cnx, query)) {
        database_exit_error(cnx);
    }

    MYSQL_RES *result = mysql_store_result(cnx);
    if (result == NULL) {
        database_exit_error(cnx);
    }

//    int num_fields = mysql_num_fields(result);

//    MYSQL_ROW row;
//    row = mysql_fetch_row(result);
//    strcpy(pays_id, row[1] ? row[1] : "");
//    strcpy(nom_pays, row[2] ? row[2] : "");

    existe = mysql_num_rows(result) == 0 ? 1 : 0;

    mysql_free_result(result);

//    if (existe == 0) {
//        return(1);
//    }

    return(existe);
}