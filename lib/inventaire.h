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
Inventaire initinv(int lvl);

//init inventaire pour rival
Inventaire init_inv_rival(int lvl_min, int lvl_max);


//soigne tous les poketudiants du sac
void soigne_sac(Inventaire * inv);

//soigne tous les poketudiants de la cafet
void soigne_caf(Inventaire * inv);

//depose le poketudiant de l'equipe vers la cafet
void drop_pokemon(Inventaire * inv,int indice);

//depose le poketudiant de l'equipe vers la cafet (table)
void drop_pokemon_table(Inventaire * inv,int indice, int table);

//depose le poketudiant de la cafet vers l'equipe
void pick_pokemon(Inventaire * inv,int indice);

//ajoute le pokemon soit dans la cafet soit dans le sac
void ajout_inv(Inventaire * inv,Poketudiant * p);


Poketudiant* get_by_id(Inventaire *inv, int id);

#endif


