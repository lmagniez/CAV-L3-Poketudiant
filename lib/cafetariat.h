#ifndef _CAFETARIA_H
#define _CAFETARIA_H

#define NB_TABLE 3
#define NB_CHAISE 4
#define NB_TOTAL NB_TABLE*NB_CHAISE

#include "poketudiant.h"

typedef struct Cafetariat{
	Poketudiant * p[NB_TOTAL];
	int cur; //nb poketudiant dans le sac
}Cafetariat;

//initialise la cafet
Cafetariat * initcaf();

//ajoute un pokemon a la cafet au prochain indice de disponible
//true si l'ajout s'est bien passé
int ajout_cafe(Cafetariat * c,Poketudiant * p);

//Tente d'ajouter un Poketudiant dans la cafeteriat
//true si l'ajout s'est bien passé
int ajout_cafe_id(Cafetariat *c, Poketudiant *p, int table);

//lance l'affichage de toutes la cafet
void showCafetaria(Cafetariat * c);

//Lance l'affichage d'une table de la cafet
void showRevision(Cafetariat * c,int table);

//Retourne si la cafet est pleine
int cafetPleine(Cafetariat * c);

//Retourne si une table de la cafet est pleine
int tablePleine(Cafetariat *c, int table);

//relache le poketudiant a l'indice i
void release(Cafetariat * caf,int indice);

#endif
