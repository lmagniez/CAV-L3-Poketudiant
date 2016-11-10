#ifndef _JOUEUR_H
#define _JOUEUR_H

#include "poketudiant.h"
#include "inventaire.h"

typedef struct Joueur{
	//Poketudiant * enseignant;
	Inventaire inv;
	//int p1;//actif au combat
}Joueur;

Joueur initJoueur();
//void afficheEnseignant(Joueur *j);



#endif
