#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "../lib/joueur.h"
#include "../lib/combat.h"
#include "../lib/commande.h"

int main(){
	
	srand(time(NULL));//debut de code pour la bonne generation aleatoire
	
	Poketudiant * tmp1=newPoketudiant_random(1,5);
	Poketudiant * tmp2=newPoketudiant_type(PROCRASTINO);

	Poketudiant * tmp3=newPoketudiant_random(1,5);
	
	Joueur j=initJoueur();
	
	ajout_sac(j.inv.s,tmp1);
	ajout_sac(j.inv.s,tmp2);

	combatSauvage(&j,tmp3);
	
	show_team(j);
	show_cafet(j);
	
	
	combatSauvage(&j,tmp3);
	
	show_team(j);
	show_cafet(j);
	

	combatSauvage(&j,tmp3);
	
	show_team(j);
	show_cafet(j);
	
	
	combatSauvage(&j,tmp3);
	
	show_team(j);
	show_cafet(j);
	
	
	
	combatSauvage(&j,tmp3);
	
	show_team(j);
	show_cafet(j);
	
	
	
	combatSauvage(&j,tmp3);
	
	show_team(j);
	show_cafet(j);
	


	return 0;
}
