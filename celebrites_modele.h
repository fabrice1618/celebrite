// Moussa, Sofiene


//char nom[51];
// int id_cree;
//id_cree = celebrites_create(nom, prenom, genre);

/*
ajoute(int *a, int *b)
{
 *a = 12;
 *b = 25;
}
*/

// Leo, Mathis
// Sara

#ifndef CELEBRITES_MODELE_H
#define CELEBRITES_MODELE_H

int celebrites_create( MYSQL *cnx, char *nom, char *prenom, char *genre );
int celebrites_read(MYSQL *cnx, int celeb_id, char *nom, char *prenom, char *genre);
int celebrites_update(MYSQL *cnx, int celeb_id, char *nom, char *prenom, char *genre);
int celebrites_delete(MYSQL *cnx, int celeb_id);
int celebrites_existe(MYSQL *cnx, int celeb_id);

#endif