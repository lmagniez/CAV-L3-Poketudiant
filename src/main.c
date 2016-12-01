#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "../lib/map.h"
#include "../lib/joueur.h"
#include "../lib/combat.h"
#include "../lib/commande.h"
#include "../lib/parsecommande.h"

int main(){
	
	srand(time(NULL));//debut de code pour la bonne generation aleatoire
	
	initMap();
	
	Joueur j=init_joueur(5);
	//ajout_sac(j.s,tmp1);

	while(1){
		lire_commande(&j);
		afficheMap();
	}

	return 0;
}
