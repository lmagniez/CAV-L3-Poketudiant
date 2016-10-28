#ifndef _SAC_H
#define _SAC_H

#define TAILLE_SAC 6

#include "poketudiant.h"

typedef struct Sac{
	Poketudiant * p[TAILLE_SAC];
	int p1; //indice du poketudiant 1
	int cur; //nb poketudiant dans le sac
}Sac;

//ajout un pokemon dans le sac
void ajout_sac(Sac * s,Poketudiant p);

//change la valeur de cur en combat
void changerPrem(Sac * s);

//recup le premier poketudiant 
Poketudiant recupPremier(Sac * s);

//supprime  poketudiant a l'indice i
void supprimierPoke_sac(Sac * s,int i);

//inverse les positions de deux poketudiant dans le tab
void switch_sac(Sac * s,int i,int j);

//renvoie si le sac est remplis 
int remplisSac(Sac sac);

#endif
