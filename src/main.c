#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "../lib/inventaire.h"

int main(){
	Poketudiant * tmp=newPoketudiant_random(1,5);
	affichePoketudiant(tmp);
	if(tmp->pokemon.evolution!=NO_EVOLUTION){
		printf("Evolution\n");
		evolution(tmp);
		affichePoketudiant(tmp);
	}
	freePoketudiant(tmp);
	return 0;
}
