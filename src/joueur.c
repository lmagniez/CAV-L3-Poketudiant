#include <stdlib.h>
#include <stdio.h>

#include "../lib/joueur.h"

Joueur initJoeur(){
	Joueur j;
	j.p=newPoketudiant_type(ENSEIGNANT_DRESSEUR);
	j.inv=initinv();
	return j;
}