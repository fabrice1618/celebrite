#ifndef METIER_MODELE_H
#define METIER_MODELE_H

int metiers_create(MYSQL *cnx, char *metier);
int metiers_read(MYSQL *cnx, int metier_id, char *metier);
int metiers_update(MYSQL *cnx, int metier_id, char *metier);
int metiers_delete(MYSQL *cnx, int metier_id);
int metiers_existe(MYSQL *cnx, int metier_id, char *metier);

#endif