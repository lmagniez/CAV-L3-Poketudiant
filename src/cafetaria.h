#ifndef _CAFETARIA_H
#define _CAFETARIA_H

#include "poketudiant.h"

typedef struct Cafetariat{
	Poketudiant p;
	Poketudiant * next;
	
}Cafetariat;

void ajout_cafe(Cafetariat * s);

void supprmierPoke_cafe(Cafetariat * s);

#endif
