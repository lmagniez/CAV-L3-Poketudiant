#ifndef _INVENTAIRE_H
#define _INVENTAIRE_H

#include "poketudiant.h"
#include "cafetariat.h"
#include "sac.h"

typedef struct Inventaire{
	Sac * s;
	Cafetariat * c;
}Inventaire;

//initialise l'inventaire
Inventaire initinv();

//soigne tous les poketudiants du sac
void soigne_sac(Inventaire * inv);

//soigne tous les poketudiants de la cafet
void soigne_caf(Inventaire * inv);

//depose le poketudiant de l'equipe vers la cafet
void drop_pokemon(Inventaire * inv,int indice);

//depose le poketudiant de la cafet vers l'equipe
void pick_pokemon(Inventaire * inv,int indice);

//ajoute le pokemon soit dans la cafet soit dans le sac
void ajout_inv(Inventaire * inv,Poketudiant * p);
#endif
