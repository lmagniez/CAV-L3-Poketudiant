#ifndef _CAFETARIA_H
#define _CAFETARIA_H


#define NB_TABLE 3
#define NB_CHAISE 4


typedef struct Cafetariat{
	Poketudiant p[NB_TABLE*NB_CHAISE];
}Cafetariat;

//ajout un pokemon a la cafet
void ajout_cafe(Cafetariat * s,Poketudiant p);

//lance l'affichage de toutes la cafet
void showCafetaria(Cafetariat * s);

//Lace l'affichage d'une table de la cafet
void showRevision(Cafetariat * s,int table);

//Retourne si la cafet est plaine ou pas
int remplisCafet(Cafetariat  * inv);

//retourne si la table est pleine 
int remplisTable(Cafetariat  * inv,int table);

#endif
