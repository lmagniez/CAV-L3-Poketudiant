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
Sac * initsac(int lvl);

Sac * init_sac_rival(int lvl_min,int lvl_max);

//ajout un pokemon dans le sac
void ajout_sac(Sac * s,Poketudiant * p);

//inverse les positions de deux poketudiant dans le tab
void switch_sac(Sac * s,int i,int j);

//renvoie si le sac est remplis 
int sacPlein(Sac * sac);

void afficheSac(Sac * sac);

int verifvie(Sac * sac);


//change la valeur de p1 en combat
void changerPrem(Sac *j, int indice);

//recup le premier poketudiant 
Poketudiant* recupPremier(Sac * s);

//supprime  poketudiant a l'indice i
Poketudiant* supprimerPoke_sac(Sac * s,int i);

#endif
