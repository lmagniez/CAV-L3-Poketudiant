#include <stdlib.h>
#include <stdio.h>

#include "../lib/joueur.h"


Joueur initJoueur(){
	Joueur j;
	j.inv=initinv();
	return j;
}
