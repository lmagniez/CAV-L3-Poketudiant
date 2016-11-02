#include <stdlib.h>
#include <stdio.h>


#include "../lib/globale.h"
#include "../lib/poketudiant.h"

void init(Poketudiant *newP){
	float tmp;

	//Calcul du coef on divise par 10 pour avoir un nombre decimal (3 coef differents un att , def et pv max
	for(int i=0;i<NB_COEF;i++){
		tmp=(float)myrand(B_COEF_MIN,B_COEF_MAX);
		//printf("%f\n",tmp);
		newP->coef[i]=tmp/10;
	}

	newP->base=recupAttaque(newP->pokemon.spe);

	//Niveau 1 des stats
	newP->stat_cur=calculStat(newP->coef,newP->pokemon.stat_base);

	for(int i=1;i< newP->lvl ;i++)
		calculstatlevelup(newP);

	newP->pv_cur=newP->stat_cur.pv_max_poke;
	
	newP->experience_cur=calculexp(newP->lvl-1);
		
	newP->experience_niveau_sup=calculexp(newP->lvl);
}

Poketudiant * newPoketudiant_random(int borne1, int borne2){
	srand(time(NULL));
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
	
	newP->lvl=(int)myrand(borne1,borne2);
	
	init(newP);

	return newP;
}

Poketudiant * newPoketudiant_type(variete t){
	srand(time(NULL));
	Poketudiant * newP=(Poketudiant *)malloc(sizeof(Poketudiant));
	
	newP->pokemon=recupPoke(t);	
	
	newP->lvl=(int)myrand(0,10);

	init(newP);

	return newP;
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
	char * var=chaineVariete(p->pokemon.nom);
	char * type=chaineType(p->pokemon.spe);
	printf("Nom : %s  Type : %s\n   Level : %d \n",var,type,p->lvl);

	for(int i=0;i<N_ATTACK;i++){
		printf("   Nom: %s , Puissance : %d\n",p->base[i].nom,p->base[i].puissance);
	}
	
	printf("Statistique :\n   Attaque : %d \n   Defense : %d \n",p->stat_cur.att,p->stat_cur.defense);
	printf("------------------------------------\n");
}

int doitevoluer(int lvl){
	if(LVL_FIVE == lvl)
		return 1;
	int r=myrand(0,100);
	if(LVL_FOUR == lvl)
		if(r<POURC_THREE)
			return 1;
	if(LVL_THREE == lvl)
		if(r<POURC_FOUR)
			return 1;
	return 0;	
}

void lvlup(Poketudiant *p){
	calculstatlevelup(p);
	soigne_Poketudiant(p);
	p->lvl++;
}

void calculstatlevelup(Poketudiant * p){
	int att=((p->pokemon.stat_base.att*p->coef[0])*POURC_LEVELUP)/100;
	int def=((p->pokemon.stat_base.defense*p->coef[1])*POURC_LEVELUP)/100;;
	int pv_max=((p->pokemon.stat_base.pv_max_poke*p->coef[1])*POURC_LEVELUP)/100;

	p->stat_cur.att=p->stat_cur.att+att;
	p->stat_cur.defense=p->stat_cur.defense+def;
	p->stat_cur.pv_max_poke=p->stat_cur.pv_max_poke+pv_max;
}

void evolution(Poketudiant *p){
	p->pokemon=recupPoke(p->pokemon.evolution);
	p->stat_cur=calculStat(p->coef,p->pokemon.stat_base);
	lvlup(p);
}

void freePoketudiant(Poketudiant *p){
	free(p->base);
	free(p);
}

int calculexp(int lvl){
	return 500*((1+lvl)/2);
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