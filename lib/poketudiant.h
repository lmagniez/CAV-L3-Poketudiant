#ifndef _POKETUDIANT_H
#define _POKETUDIANT_H

#include "poke.h"
#include "attaque.h"

#define CONST_LEVEL 500
#define B_COEF_MIN 9
#define B_COEF_MAX 11
#define NB_COEF 3

#define LVL_FIVE 5
#define LVL_FOUR 4
#define LVL_THREE 3

#define POURC_THREE 200
#define POURC_FOUR 375
#define POURC_MAX 1000

#define POURC_LEVELUP 10

typedef struct Poketudiant{
	Poke poke;
		
	int id;
	
	float coef[NB_COEF];
	
	statistique stat_cur;
	
	attaque * base;

	int lvl;
		
	int pv_cur;

	
	int experience_cur;
	int experience_niveau_sup;
	
}Poketudiant;

//creer un poketudiant entre 2 niveau
Poketudiant * new_poketudiant_random(int borne1, int borne2);

//creer un poketudiant entre en fonction du type
Poketudiant * new_poketudiant_type(variete t, int borne1, int borne2);

void init(Poketudiant * p, int lvl);

//calcul l'exp pour le niveau suivant
int xp_next(int lvl);

void soigne_poketudiant(Poketudiant * p);

//echange les poketudiants
void swap_poketudiant(Poketudiant * a , Poketudiant * b);

void affiche_poketudiant(Poketudiant * p);

int calcul_exp(int lvl);

void free_poketudiant(Poketudiant *p);

int doit_evoluer(int lvl);

void lvl_up(Poketudiant *p);

void calcul_stat_lvl_up(Poketudiant * p, int lvlUp);

//gestion lors de la monter de niveau
void gestion_lvl_up(Poketudiant * p,int xp_add);

//fait evoluer le poketudiant
void evolution(Poketudiant *p);

#endif
