#include <stdlib.h>
#include <stdio.h>


#include "../lib/globale.h"
#include "../lib/poketudiant.h"



Poketudiant * newPoketudiant_random(int borne1, int borne2){
	srand(time(NULL));
	float tmp;
	if( borne1 < 1 || borne2 < 1){
		printf("Creation Poketudiant Impossible \n");
		return NULL;
	}
	
	if( borne1 > borne2){
		int tmp=borne2;
		borne2=borne1;
		borne1=tmp;
	}
	
	Poketudiant * newP=(Poketudiant *)malloc(sizeof(Poketudiant));
	
	newP->pokemon=newPokeRand();
	
	
	//Calcul du coef on divise par 10 pour avoir un nombre decimal (3 coef differents un att , def et pv max
	
	for(int i=0;i<NB_COEF;i++){
		tmp=(float)myrand(B_COEF_MIN,B_COEF_MAX);
		//printf("%f\n",tmp);
		newP->coef[i]=tmp/10;
	}
	
	newP->base=recupAttaque(newP->pokemon.spe);
	

	newP->lvl=(int)myrand(borne1,borne2);

	//Niveau 1 des stats
	newP->stat_cur=calculStat(newP->coef,newP->pokemon.stat_base);

	newP->pv_cur=newP->stat_cur.pv_max_poke;
	
	newP->experience_cur=calculexp(newP->lvl-1);
		
	newP->experience_niveau_sup=calculexp(newP->lvl);
			
	return newP;
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
	p->pv_cur=p->stat_cur.pv_max_poke;
}


//echange les poketudiants
void swap_poketudiant(Poketudiant * a , Poketudiant * b){
	Poketudiant p=*a;
	*a=*b;
	*b=p;
}

void affichePoketudiant(Poketudiant * p){
	printf("Deb Affiche \n");
	printf("%d %d \n",p->pokemon.nom,p->pokemon.spe);
	
	char * var=chaineVariete(p->pokemon.nom);
	printf("Apres NOM\n");
	char * type=chaineType(p->pokemon.spe);
	printf("Recup chaine\n");
	printf("------------------------------------\n");
	printf("Nom : %s  Type : %s\n   Level : %d \n",var,type,p->lvl);
	printf("Nom Affiche \n");

	printf("Attaque :\n");
	for(int i=0;i<N_ATTACK;i++){
		printf("   Nom: %s , Puissance : %d\n",p->base[i].nom,p->base[i].puissance);
	}
	printf("Atta Affiche \n");
	
	printf("Statistique :\n   Attaque : %d \n   Defense : %d \n",p->stat_cur.att,p->stat_cur.defense);
	printf("------------------------------------\n");
	printf("fin Affiche \n");
}


int calculexp(int lvl){
	return 500*((1+lvl)/2);
}

void freePoketudiant(Poketudiant *p)
{
	free(p->base);
	free(p);
}
