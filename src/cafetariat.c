#include <stdlib.h>
#include <stdio.h>

#include "../lib/cafetariat.h"

#define ERR_FULLCAF "La Cafetaria est pleine\n"
#define ERR_IDCAF "La table %d est pleine \n"

//Retourne si la cafet est pleine
int cafetPleine(Cafetariat * c){
	return NB_TOTAL==c->cur;
}

//Retourne si une table de la cafet est pleine
int tablePleine(Cafetariat *c, int table){
	for (int i=table*NB_CHAISE; i<table*NB_CHAISE+NB_CHAISE; i++)
	{
		if(c->p[i]==NULL)
			return 0;
	}
	return 1;
}

//initialise la cafet
Cafetariat * initcaf(){
	Cafetariat * c=(Cafetariat *)malloc(sizeof(Cafetariat));
	c->cur=0;
	//for(int i=0;i<NB_TOTAL;i++)
	//	c->p[i]=(Poketudiant *)malloc(sizeof(Poketudiant));
	return c;
}

//ajoute un pokemon a la cafet au prochain indice de disponible
//true si l'ajout s'est bien passé
int ajout_cafe(Cafetariat * c,Poketudiant * p){
	if(cafetPleine(c)){
		printf("La Cafetaria est pleine\n");
		return 0;
	}
	for(int i=0; i<NB_TOTAL; i++){
		if(c->p[i]==NULL){	
			c->p[i]=p;
			c->cur++;
			printf("Ajout du poketudiant à l'emplacement %d (table %d)\n",i,i/NB_TABLE);
			return 1;
		}
	}
	printf("ERREUR, la cafet est censé ne pas être pleine?\n");
	exit(1);
}

//Tente d'ajouter un Poketudiant dans la cafeteriat
//true si l'ajout s'est bien passé
int ajout_cafe_id(Cafetariat *c, Poketudiant *p, int table)
{
	if(tablePleine(c,table))
		return 0;
	for(int i=table*NB_CHAISE; i<table*NB_CHAISE+NB_CHAISE; i++){
		if(c->p[i]==NULL){
			c->p[i]=p;
			c->cur++;
			printf("Ajout du poketudiant à l'emplacement %d (table %d)\n",i,i/NB_TABLE);
			return 1;
		}
	}
	printf("ERREUR, la table est censé ne pas être pleine?\n"); 
	exit(1);
	
}	

//lance l'affichage de toute la cafet
void showCafetaria(Cafetariat * c){
	for(int i=0;i<NB_TABLE;i++){
		showRevision(c,i);
	}
}

//Lance l'affichage d'une table de la cafet
void showRevision(Cafetariat * c,int table){
	for(int i=(table*NB_CHAISE);i<(table*NB_CHAISE)+NB_CHAISE;i++){
		printf("----------------------------------\n                  \
TABLE %d INDICE %d                  \
\n----------------------------------\n",table,i);
		if(c->p[i]!=NULL)
			affichePoketudiant(c->p[i]);
		else
			printf("VIDE\n");
			//printf("%d\n",c->p[i]);
	}
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

