#ifndef _ATTAQUE_H
#define _ATTAQUE_H

#define NB_ATTACK 12
#define N_ATTACK 2 

#include "type.h"

typedef struct attaque{
	char * nom;
	type t;
	int puissance;
}attaque;

//retourne un tab de 2 attaque pour le pokemon
attaque * recup_attaque(type t); 

//renvoie les dommages d'une attaque 
int dommage_attaque(float k,int att_attack,int def_defender,int power);

#endif
