#ifndef _INVENTAIRE_H
#define _INVENTAIRE_H

#include "poketudiant.h"
#include "cafetariat.h"
#include "sac.h"

typedef struct Joueur{
	Sac * s;
	Cafetariat * c;
}Joueur;

//initialise l'inventaire
Joueur init_joueur(int lvl);

//init inventaire pour rival
Joueur init_rival(int lvl_min, int lvl_max);


//soigne tous les poketudiants du sac
void soigne_sac(Joueur * j);

//soigne tous les poketudiants de la cafet
void soigne_caf(Joueur * j);

//depose le poketudiant de l'equipe vers la cafet
void drop_pokemon(Joueur * j,int indice);

//depose le poketudiant de l'equipe vers la cafet (table)
void drop_pokemon_table(Joueur * j,int indice, int table);

//depose le poketudiant de la cafet vers l'equipe
void pick_pokemon(Joueur * j,int indice);

//ajoute le pokemon soit dans la cafet soit dans le sac
void ajout_inv(Joueur * j,Poketudiant * p);


Poketudiant* get_by_id(Joueur *j, int id);

void free_joueur(Joueur j);

#endif


