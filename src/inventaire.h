#ifndef _INVENTAIRE_H
#define _INVENTAIRE_H

#include "sac.h"
#include "cafetaria.h"

typedef struct Inventaire{
	Sac s;
	Cafetariat c;
}Inventaire;

void echanger(Inventaire  * inv);

#endif
