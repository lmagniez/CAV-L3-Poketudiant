#ifndef _JOUEUR_H
#define _JOUEUR_H

#include "Poketudiant.h"
#include "Inventaire.h"

typedef struct Joueur{
	Poketudiant * p;
	Inventaire inv;
}Joueur;

Joueur initJoeur();
#endif
