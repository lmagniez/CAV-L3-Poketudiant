#include <stdlib.h>
#include <stdio.h>

#include "../lib/cafetaria.h"

//ajout un pokemon a la cafet
void ajout_cafe(Cafetariat * s,Poketudiant p){
	if(s->cur==NB_TOTAL){
		printf("La Cafetaria est pleine\n");
		return;
	}
	*(s->p[s->cur])=p;
	s->cur++;
}

//lance l'affichage de toutes la cafet
void showCafetaria(Cafetariat * s){
	for(int i=0;i<NB_TABLE;i++){
		showRevision(s,i);
	}
}

//Lance l'affichage d'une table de la cafet
void showRevision(Cafetariat * s,int table){
	for(int i=(table*NB_CHAISE)-NB_CHAISE;i<(table*NB_CHAISE);i++){
		//affichePoketudiant(*(s->p[i])); ---------------------------------------
	}
}

//Retourne si la cafet est plaine ou pas
int remplisCafet(Cafetariat  * caf){
	return NB_TOTAL==caf->cur;
}

//relache le poketudiant a l'indice i
void release(Cafetariat * caf,int indice){
	caf->p[indice]=NULL;
	
	if(indice == NB_TOTAL){
		caf->cur--;
		return;
	}
	
	int car=indice+1;
	
	for(int i=indice;car<caf->cur;car++,i++){
		//swap_poketudiant(caf->p[i],caf->p[car]); ---------------------------------------
	}
	
	caf->cur--;
}

