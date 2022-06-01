#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "database.h"
#include "celebrites_modele.h"

void print_celebrite(int id, char *nom, char *prenom, char *genre );

int main(int argc, char **argv)
{
    MYSQL *cnx = NULL;
    int id_cree;
    char nom[51];
    char prenom[51];
    char genre[20];
    bool query_exec;

    cnx = database_open(cnx);

    strcpy(nom, "Musk");
    strcpy(prenom, "Elon");
    strcpy(genre, "masculin");

    print_celebrite( 0, nom, prenom, genre );

    id_cree = celebrites_create( cnx, nom, prenom, genre );
    printf("Id cree = %d\n", id_cree);

    strcpy(nom, "");
    strcpy(prenom, "");
    strcpy(genre, "");
    print_celebrite( 0, nom, prenom, genre );

    int lecture = celebrites_read(cnx, id_cree, nom, prenom, genre);
    print_celebrite( id_cree, nom, prenom, genre );

    database_close(cnx);
    exit(0);
}

void print_celebrite(int id, char *nom, char *prenom, char *genre )
{
    printf("celebrite: %d %s %s %s\n", id, nom, prenom, genre);
}