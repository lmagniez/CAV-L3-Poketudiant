#include <stdlib.h>
#include <stdio.h>

#include "poke.h"
#include "poketudiant.h"

	
Poketudiant newPoketudiant(variete v,int lvl){
	Poketudiant new;
	Poke newP=newPoke(v);
	new.pokemon=newP;
	return new;
}
