#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "database.h"
#include "metiers_modele.h"

void print_celebrite(char *metier);

int main(int argc, char **argv)
{
    MYSQL *cnx;
    int id_cree;
    char metier[51];

    cnx = database_open(cnx);

    strcpy(metier, "SysAdmin");
    print_celebrite(metier);

    id_cree = 19;

    id_cree = metiers_create(cnx, metier);
    printf("Id cree = %d\n", id_cree);

    strcpy(metier, "");
    print_celebrite(metier);

    int lecture = metiers_read(cnx, id_cree, metier);
    print_celebrite(metier);

    database_close(cnx);
    exit(0);
}

void print_celebrite(char *metier)
{
    printf("celebrite: %s\n", metier);
}