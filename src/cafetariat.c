#include <stdlib.h>
#include <stdio.h>

#include "../lib/cafetariat.h"

#define ERR_FULLCAF "La Cafetaria est pleine\n"
#define ERR_IDCAF "La table %d est pleine \n"


//Retourne si la cafet est pleine
int cafet_pleine(Cafetariat * c){
	return NB_TOTAL==c->cur;
}

//Retourne si une table de la cafet est pleine
int table_pleine(Cafetariat *c, int table){
	for (int i=table*NB_CHAISE; i<table*NB_CHAISE+NB_CHAISE; i++)
	{
		if(c->p[i]==NULL)
			return 0;
	}
	return 1;
}

//initialise la cafet
Cafetariat * init_caf(){
	Cafetariat * c=(Cafetariat *)malloc(sizeof(Cafetariat));
	for(int i=0;i<NB_TABLE*NB_CHAISE;i++)
		c->p[i]=NULL;
	c->cur=0;
	return c;
}

//ajoute un pokemon a la cafet au prochain indice de disponible
//true si l'ajout s'est bien passé
int ajout_cafe(Cafetariat * c,Poketudiant * p){
	if(cafet_pleine(c)){
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
	if(table_pleine(c,table))
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


//Lance l'affichage d'une table de la cafet
void show_revision(Cafetariat * c,int table){
	for(int i=(table*NB_CHAISE);i<(table*NB_CHAISE)+NB_CHAISE;i++){
		printf("----------------------------------\n                  \
TABLE %d INDICE %d                  \
\n----------------------------------\n",table,i);
		if(c->p[i]!=NULL){
			printf("CC\n");
			affiche_poketudiant(c->p[i]);
		}
		else{
			printf("VIDE\n");
		}
	}
}

//lance l'affichage de toute la cafet
void show_cafetaria(Cafetariat * c){
	for(int i=0;i<NB_TABLE;i++){
		show_revision(c,i);
	}
}



//relache le poketudiant a l'indice i (on a déjà vérifié que c->p[indice]!=NULL
void release_caf(Cafetariat * c,int indice){
	
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


void free_cafeteria(Cafetariat *c)
{
	for(int i=0; i<NB_TOTAL; i++)
	{
		if(c->p[i])
			free_poketudiant(c->p[i]);
	}
	
	free(c);
}

