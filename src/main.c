#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "../lib/inventaire.h"
#include "../lib/combat.h"

int main(){
	Poketudiant * tmp=newPoketudiant_random(1,5);
	if(tmp->pokemon.evolution!=NO_EVOLUTION){
		evolution(tmp);
	}
	//affichePoketudiant(tmp);

	Poketudiant * tmp2=newPoketudiant_type(2);
	if(tmp->pokemon.evolution!=NO_EVOLUTION){
		evolution(tmp2);
	}
	//affichePoketudiant(tmp2);
	
	combatSauvage(tmp,tmp2);
	freePoketudiant(tmp);
	freePoketudiant(tmp2);
	return 0;
}
