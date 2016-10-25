#ifndef _ATTAQUE_H
#define _ATTAQUE_H

#define NB_ATTACK 12 

#include "type.h"

typedef struct attaque{
	char * nom;
	type t;
	int puissance;
}attaque;

attaque * recupAttaque(type t); //retourne un tab de 2 attaque pour le pokemon

#endif
