#ifndef _POKETUDIANT_H
#define _POKETUDIANT_H

#include "poke.h"

typedef struct Poketudiant{
	Poke pokemon;
	statistique stat_cur;

	int experience;
	
}Poketudiant;

Poketudiant newPoketudiant(int lvl);

#endif
