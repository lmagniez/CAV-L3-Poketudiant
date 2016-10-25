#ifndef _SAC_H
#define _SAC_H

#define TAILLE_SAC 6
#include "poketudiant.h"

typedef struct Sac{
	Poketudiant p[TAILLE_SAC];
	int cpt;
}Sac;

void ajout_sac(Sac * s);

void changerPrem(Sac * s);

void recupPremier(Sac * s);

void supprimierPoke_sac(Sac * s);


#endif
