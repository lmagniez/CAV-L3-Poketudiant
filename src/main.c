#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "../lib/joueur.h"
#include "../lib/combat.h"
#include "../lib/commande.h"

int main(){
	Poketudiant * tmp1=newPoketudiant_random(1,5);
	Poketudiant * tmp2=newPoketudiant_type(PROCRASTINO);

	Poketudiant * tmp3=newPoketudiant_random(1,5);
	
	Joueur j=initJoeur();
	ajout_sac(j.inv.s,tmp1);
	ajout_sac(j.inv.s,tmp2);

	combatSauvage(j,tmp3);

	return 0;
}
