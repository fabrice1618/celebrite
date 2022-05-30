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

int celebrites_create( char *nom, char *prenom, char *genre );
int celebrites_read(int celeb_id, char *nom, char *prenom, char *genre);
int celebrites_update(int celeb_id, char *nom, char *prenom, char *genre);
int celebrites_delete(int celeb_id);
int celebrites_existe(int celeb_id);

#endif