#ifndef _POKE_H
#define _POKE_H

#define NB_VARIETE 10

#include "type.h"
#include "variete.h"
#include "statistique.h"

typedef struct Poke{
	variete nom;
	type spe;
	int capturable;
	variete evolution;
	statistique stat_base;
}Poke;

Poke recup_poke(variete v);

Poke new_poke_rand();
#endif
