#include <stdlib.h>
#include <stdio.h>

#include "../lib/cafetariat.h"

//initialise la cafet
Cafetariat * initcaf(){
	Cafetariat * c=(Cafetariat *)malloc(sizeof(Cafetariat));
	c->cur=0;
	for(int i=0;i<NB_TOTAL;i++)
		c->p[i]=(Poketudiant *)malloc(sizeof(Poketudiant));
	return c;
}

//ajout un pokemon a la cafet
void ajout_cafe(Cafetariat * c,Poketudiant * p){
	if(c->cur==NB_TOTAL){
		printf("La Cafetaria est pleine\n");
		return;
	}
	c->p[c->cur]=p;
	c->cur++;
}

//lance l'affichage de toutes la cafet
void showCafetaria(Cafetariat * c){
	for(int i=0;i<NB_TABLE;i++){
		showRevision(c,i);
	}
}

//Lance l'affichage d'une table de la cafet
void showRevision(Cafetariat * c,int table){
	for(int i=(table*NB_CHAISE)-NB_CHAISE;i<(table*NB_CHAISE);i++){
		printf("----------------------------------\n                  TABLE %d INDICE %d                  \n----------------------------------\n",table,i);
		affichePoketudiant(c->p[i]);
	}
}

//Retourne si la cafet est plaine ou pas
int remplisCafet(Cafetariat * c){
	return NB_TOTAL==c->cur;
}

//relache le poketudiant a l'indice i
void release(Cafetariat * c,int indice){
	int car=0;
	c->p[indice]=NULL;
	
	if(indice == NB_TOTAL){
		c->cur--;
		return;
	}

	for(int i=indice,car=indice+1;car<c->cur;car++,i++){
		swap_poketudiant(c->p[i],c->p[car]);
	}
	c->cur--;
}

