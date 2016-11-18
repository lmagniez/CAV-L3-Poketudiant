#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "../lib/joueur.h"
#include "../lib/combat.h"
#include "../lib/commande.h"
#include "../lib/parsecommande.h"

int main(){
	
	Poketudiant * tmp1=new_poketudiant_random(1,5);
	Poketudiant * tmp2=new_poketudiant_type(PROCRASTINO,1,5);

	Poketudiant * tmp3=new_poketudiant_random(1,5);
	
	Joueur j=init_joueur(5);
	Joueur j2=init_joueur(2);
	printf("ok\n");
	
	ajout_sac(j.s,tmp1);


	while(1){
		lire_commande(&j);
	}

	srand(time(NULL));//debut de code pour la bonne generation aleatoire
	
	
	catch(&j,5);
	catch(&j2,5);
	
	combat_rival(&j,&j2);
	

	return 0;
}
