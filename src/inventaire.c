#include <stdlib.h>
#include <stdio.h>

#include "../lib/inventaire.h"

#define ERR_TEAMFULL "Impossible l'equipe est pleine\n"
#define ERR_NOPKTD "Il n'y a pas de poketudiants a cette place\n"
#define ERR_BOTHFULL "Le sac et La cafetaria sont pleins\n"


//initialise l'inventaire
Inventaire initinv(){
	Inventaire inv;
	inv.s=initsac();
	inv.c=initcaf();
	return inv;
}

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
	Poketudiant *p=supprimerPoke_sac(&(inv->s),indice);
	ajout_cafe(&(inv->c),p);
}

//depose le poketudiant de la cafet vers l'equipe
void pick_pokemon(Inventaire * inv,int indice){
	
	if(remplisSac(inv->s)){
		printf(ERR_TEAMFULL);
		return;
	}
	if(inv->c.p[indice]==NULL){
		printf(ERR_NOPKTD);
		return;
	}
	
	swap_poketudiant(inv->s.p[inv->s.cur],inv->c.p[inv->c.cur]);
	inv->c.cur--;
}

//ajoute le pokemon soit dans la cafet soit dans le sac
void ajout_inv(Inventaire * inv,Poketudiant * p){
	if(remplisSac( (inv->s) ) ){
		if(!remplisCafet((inv->c)))
			ajout_cafe( &(inv->c),p);
		else
			printf(ERR_BOTHFULL);
	}
	ajout_sac(&(inv->s),p);
}
