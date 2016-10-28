#include <stdlib.h>
#include <stdio.h>


#include "../lib/globale.h"
#include "../lib/poketudiant.h"


Poketudiant * newPoketudiant_random(int borne1, int borne2){
	
	//--------------------------------
	return NULL;
}

Poketudiant * newPoketudiant_type(type t){
	
	//--------------------------------
	return NULL;
}

int xp_next(int lvl){
	return CONST_LEVEL*(1+lvl)/2;
}

int fuite(int lvl_poke, int lvl_enemy){
	float r=myrand(0,100);
	
	if(lvl_enemy-3 >= lvl_poke)
		return 0;
	else if(lvl_enemy-2 >= lvl_poke && r < 75)
		return 0;
	else if(lvl_enemy <= lvl_poke-1 && r < 60)
		return 0;
	else if(lvl_enemy ==lvl_poke && r <= 50)
		return 0;
	
	return 1;
}

int probaCapture(int pv_eff , int pv_max){
	return 2*max(((1/2)-(pv_eff/pv_max)),0);
}

void soigne_Poketudiant(Poketudiant * p){
	p->pv_cur=p->pv_max;
}


//echange les poketudiants
void swap_poketudiant(Poketudiant * a , Poketudiant * b){
	//--------------------------------
}

void affichePoketudiant(Poketudiant * p){
	char * var=stringVariete(p->pokemon.nom);
	char * type=stringType(p->pokemon.spe);
	printf("Nom : %s  Type : %s\n  Level : %d \n",var,type,p->lvl);
	printf("Statistique :\n      Attaque : %d \n       Defense : %d \n ",p->stat_cur.att,p->stat_cur.defense);
}
