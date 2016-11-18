#ifndef _SAC_H
#define _SAC_H

#define TAILLE_SAC 3

#include "poketudiant.h"

typedef struct Sac{
	Poketudiant * p[TAILLE_SAC];
	int p1; //indice du poketudiant 1
	int cur; //nb poketudiant dans le sac
}Sac;

//Initialise le sac
Sac * init_sac(int lvl);

Sac * init_sac_rival(int lvl_min,int lvl_max);

//ajout un pokemon dans le sac
void ajout_sac(Sac * s,Poketudiant * p);

//inverse les positions de deux poketudiant dans le tab
void switch_sac(Sac * s,int i,int j);

//renvoie si le sac est remplis 
int sac_plein(Sac * sac);

void affiche_sac(Sac * sac);

int verif_vie(Sac * sac);


//change la valeur de p1 en combat
void changer_premier(Sac *j, int indice);

//recup le premier poketudiant 
Poketudiant* recup_premier(Sac * s);

//supprime  poketudiant a l'indice i
Poketudiant* supprimer_poke_sac(Sac * s,int i);

void free_sac(Sac *s);

#endif
