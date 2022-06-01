#ifndef PAYS_MODELE_H
#define PAYS_MODELE_H

#include <mysql/mysql.h>

int pays_create(MYSQL *cnx, char *nom_pays);
int pays_read(MYSQL *cnx, int pays_id, char *nom_pays);
int pays_update(MYSQL *cnx, int pays_id, char *nom_pays);
int pays_delete(MYSQL *cnx, int pays_id);
int pays_existe(MYSQL *cnx, int pays_id);

#endif