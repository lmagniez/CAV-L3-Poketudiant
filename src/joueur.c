#include <stdlib.h>
#include <stdio.h>

#include "../lib/joueur.h"


Joueur initJoueur(int lvl){
	Joueur j;
	j.inv=initinv(lvl);
	return j;
}
