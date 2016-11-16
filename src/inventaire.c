#include <stdlib.h>
#include <stdio.h>

#include "../lib/inventaire.h"

#define ERR_TEAMFULL "Impossible l'equipe est pleine\n"
#define ERR_NOPKTD "Il n'y a pas de poketudiants a cette place\n"
#define ERR_BOTHFULL "Le sac et La cafetaria sont pleins\n"


//initialise l'inventaire
Inventaire initinv(int lvl){
	Inventaire inv;
	inv.s=initsac(lvl);
	inv.c=initcaf();
	return inv;
}

//soigne tous les poketudiants du sac
void soigne_sac(Inventaire * inv){
	for(int i=0;i<inv->s->cur;i++){
		soigne_Poketudiant(inv->c->p[i]);
	}
}

//soigne tous les poketudiants de la cafet
void soigne_caf(Inventaire * inv){
	for(int i=0;i<inv->c->cur;i++){
		soigne_Poketudiant(inv->c->p[i]);
	}
}

//depose le poketudiant de l'equipe vers la cafet
void drop_pokemon(Inventaire * inv,int indice){
	Poketudiant *p=supprimerPoke_sac(inv->s,indice);
	ajout_cafe(inv->c,p);
}

//depose le poketudiant de l'equipe vers la cafet (en fonction table)
void drop_pokemon_table(Inventaire * inv,int indice, int table){
	Poketudiant *p=supprimerPoke_sac(inv->s,indice);
	ajout_cafe_id(inv->c,p,table);
}

//depose le poketudiant de la cafet vers l'equipe
void pick_pokemon(Inventaire * inv,int indice){
	if(sacPlein(inv->s)){
		printf(ERR_TEAMFULL);
		return;
	}
	if(inv->c->p[indice]==NULL){
		printf(ERR_NOPKTD);
		return;
	}
	
	//swap_poketudiant(inv->s->p[inv->s->cur],inv->c->p[inv->c->cur]);
	inv->s->p[inv->s->cur]=inv->c->p[indice];
	inv->c->p[indice]=NULL;
	inv->c->cur--;
	inv->s->cur++;
}

//ajoute le pokemon soit dans la cafet soit dans le sac
void ajout_inv(Inventaire * inv,Poketudiant * p){
	if(sacPlein( (inv->s) ) ){
		if(!cafetPleine((inv->c)))
			ajout_cafe(inv->c,p);
		else
			printf(ERR_BOTHFULL);
	}
	else ajout_sac(inv->s,p);
}

Poketudiant* get_by_id(Inventaire *inv, int id)
{
	Sac *s=inv->s;
	Cafetariat *c=inv->c;
	
	
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

