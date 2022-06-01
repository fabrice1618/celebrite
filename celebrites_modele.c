#include <stdio.h>
#include <string.h>
#include <mysql/mysql.h>

#include "database.h"
#include "celebrites_modele.h"


#define QUERY_INSERT "INSERT INTO celebrites(nom, prenom, genre) VALUES('%s', '%s', '%s')"
#define QUERY_READ "SELECT * FROM celebrites WHERE celeb_id = %d"

int celebrites_create( MYSQL *cnx, char *nom, char *prenom, char *genre )
{
    database_query(cnx, QUERY_INSERT, nom, prenom, genre);
    int id = mysql_insert_id(cnx);

    return(id);
}

int celebrites_read(MYSQL *cnx, int celeb_id, char *nom, char *prenom, char *genre)
{

    database_query(cnx, QUERY_READ, celeb_id);
    MYSQL_RES *result = mysql_store_result(cnx);
    if (result == NULL) {
        database_exit_error(cnx);
    }

//    int num_fields = mysql_num_fields(result);

    MYSQL_ROW row;
    row = mysql_fetch_row(result);
    strcpy(nom, row[1] ? row[1] : "");
    strcpy(prenom, row[2] ? row[2] : "");
    strcpy(genre, row[3] ? row[3] : "");

    mysql_free_result(result);

    return(row[0] ? 0 : 1);
}

//enum('masculin','feminin','autre','')
int valid_genre(char *genre)
{

}