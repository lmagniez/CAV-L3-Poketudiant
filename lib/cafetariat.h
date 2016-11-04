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

//ajout un pokemon a la cafet
void ajout_cafe(Cafetariat * c,Poketudiant * p);

//lance l'affichage de toutes la cafet
void showCafetaria(Cafetariat * c);

//Lance l'affichage d'une table de la cafet
void showRevision(Cafetariat * c,int table);

//Retourne si la cafet est plaine ou pas
int remplisCafet(Cafetariat * c);

//relache le poketudiant a l'indice i
void release(Cafetariat * caf,int indice);

#endif
