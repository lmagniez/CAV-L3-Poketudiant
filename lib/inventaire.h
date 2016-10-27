#ifndef _INVENTAIRE_H
#define _INVENTAIRE_H


#include "poketudiant.h"
#include "sac.h"
#include "cafetaria.h"

typedef struct Inventaire{
	Sac s;
	Cafetariat c;
}Inventaire;

//echange la position des poketudiants dans le sac
void echanger(Sac  * inv, int indicesac);

//soigne tous les poketudiants du sac
void soigne(Sac * inv);

#endif
