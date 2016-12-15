#include <stdlib.h>
#include <stdio.h>

#include "../lib/joueur.h"

#define ERR_TEAMFULL "Impossible l'equipe est pleine\n"
#define ERR_NOPKTD "Il n'y a pas de poketudiants a cette place\n"
#define ERR_BOTHFULL "Le sac et La cafetaria sont pleins\n"


//initialise l'inventaire
Joueur init_joueur(int lvl){
	Joueur j;
	j.nb_point=1;
	j.s=init_sac(lvl);
	j.c=init_caf();
	return j;
}

Joueur init_rival(int lvl_min, int lvl_max){
	Joueur j;
	j.nb_point=1;
	j.s=init_sac_rival(lvl_min,lvl_max);
	j.c=init_caf();
	return j;
}

Joueur init_rival_precis(int lvl_min,int lvl_max){
	Joueur j;
	j.nb_point=1;
	j.s=init_sac_rival_precis(lvl_min,lvl_max);
	j.c=init_caf();
	return j;
}

//soigne tous les poketudiants du sac
void soigne_sac(Joueur * j){
	for(int i=0;i<j->s->cur;i++){
		soigne_poketudiant(j->c->p[i]);
	}
}

//soigne tous les poketudiants de la cafet
void soigne_caf(Joueur * j){
	for(int i=0;i<j->c->cur;i++){
		soigne_poketudiant(j->c->p[i]);
	}
}

//depose le poketudiant de l'equipe vers la cafet
void drop_pokemon(Joueur * j,int indice){
	Poketudiant *p=supprimer_poke_sac(j->s,indice);
	ajout_cafe(j->c,p);
}

//depose le poketudiant de l'equipe vers la cafet (en fonction table)
void drop_pokemon_table(Joueur * j,int indice, int table){
	Poketudiant *p=supprimer_poke_sac(j->s,indice);
	ajout_cafe_id(j->c,p,table);
}

//depose le poketudiant de la cafet vers l'equipe
void pick_pokemon(Joueur * j,int indice){
	if(sac_plein(j->s)){
		printf(ERR_TEAMFULL);
		return;
	}
	if(j->c->p[indice]==NULL){
		printf(ERR_NOPKTD);
		return;
	}
	
	j->s->p[j->s->cur]=j->c->p[indice];
	j->c->p[indice]=NULL;
	j->c->cur--;
	j->s->cur++;
}

//ajoute le pokemon soit dans la cafet soit dans le sac
void ajout_inv(Joueur * j,Poketudiant * p){
	if(sac_plein( (j->s) ) ){
		if(!cafet_pleine((j->c)))
			ajout_cafe(j->c,p);
		else
		{
			printf(ERR_BOTHFULL);
			free_poketudiant(p);
		}
	}
	else ajout_sac(j->s,p);
}



Poketudiant* get_by_id(Joueur *j, int id)
{
	Sac *s=j->s;
	Cafetariat *c=j->c;
	
	
	//parcoure sac
	for(int i=0; i<s->cur; i++)
	{
		if(s->p[i]->id==id)
		{
			return s->p[i];
		}
	}
	
	//parcoure cafet
	for(int i=0; i<NB_TOTAL; i++)
	{
		if(c->p[i]!=NULL)
			if(c->p[i]->id==id)
			{
				return c->p[i];
			}
	}
	
	return NULL;
}

void free_joueur(Joueur j)
{
	free_sac(j.s);
	free_cafeteria(j.c);
}
