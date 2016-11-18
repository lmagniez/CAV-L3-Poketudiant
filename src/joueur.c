#include <stdlib.h>
#include <stdio.h>

#include "../lib/joueur.h"


Joueur initJoueur(int lvl){
	Joueur j;
	j.inv=initinv(lvl);
	return j;
}

Joueur initRival(int lvl_min, int lvl_max)
{
	Joueur j;
	j.inv=init_inv_rival(lvl_min,lvl_max);
	return j;
}
