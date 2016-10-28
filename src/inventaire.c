#include <stdlib.h>
#include <stdio.h>


#include "../lib/inventaire.h"

//initialise l'inventaire
Inventaire initinv();

//soigne tous les poketudiants du sac
void soigne_sac(Inventaire * inv){
	for(int i=0;i<inv->s.cur;i++){
		soigne_Poketudiant(inv->c.p[i]);
	}
}

//soigne tous les poketudiants de la cafet
void soigne_caf(Inventaire * inv){
	for(int i=0;i<inv->c.cur;i++){
		soigne_Poketudiant(inv->c.p[i]);
	}
}

//depose le poketudiant de l'equipe vers la cafet
void drop_pokemon(Inventaire * inv,int indice){
	
}

//depose le poketudiant de la cafet vers l'equipe
void pick_pokemon(Inventaire * inv,int indice){
	if(0){
		printf("Impossible l'equipe est pleine\n");
		return;
	}
	if(inv->c.p[indice]==NULL){
		printf("Il n'y a pas de poketudiants a cette place\n");
		return;
	}
	
}

