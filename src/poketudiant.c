#include <stdlib.h>
#include <stdio.h>

#include "../lib/globale.h"
#include "../lib/poketudiant.h"

int ID=0;

void init(Poketudiant *newP, int lvl){
	float tmp;

	//Calcul du coef on divise par 10 pour avoir un nombre decimal (3 coef differents un att , def et pv max
	for(int i=0;i<NB_COEF;i++){
		tmp=(float)myrand(B_COEF_MIN,B_COEF_MAX);
		//printf("%f\n",tmp);
		newP->coef[i]=tmp/10;
	}
	
	newP->id=ID++;

	newP->base=recupAttaque(newP->pokemon.spe);

	//Niveau 1 des stats
	newP->stat_cur=calculStat(newP->coef,newP->pokemon.stat_base);

	for(int i=2;i<= lvl;i++)
		calculstatlevelup(newP,0);

	newP->pv_cur=newP->stat_cur.pv_max_poke;
	
	newP->experience_cur=xp_next(newP->lvl-1);
		
	newP->experience_niveau_sup=xp_next(newP->lvl);
}

Poketudiant * newPoketudiant_random(int borne1, int borne2){
	
	
	
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
	newP->lvl=1;
	
	newP->pokemon=newPokeRand();
	
	int lvl=(int)myrand(borne1,borne2);
	
	init(newP,lvl);

	return newP;
}

Poketudiant * newPoketudiant_type(variete t,int borne1, int borne2){
	srand(time(NULL));
	Poketudiant * newP=(Poketudiant *)malloc(sizeof(Poketudiant));
	newP->lvl=1;
	
	
	newP->pokemon=recupPoke(t);	
	
	int lvl=(int)myrand(borne1,borne2);

	init(newP,lvl);

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
	//printf("Nom : %s  Type : %s\n   Level : %d \n",var,type,p->lvl);
	printf("ID: %d Nom : %s  Type : %s\n   Level : %d \n   Pv: %d/%d \n",p->id, var,type,p->lvl,p->pv_cur,p->stat_cur.pv_max_poke);
	
	for(int i=0;i<N_ATTACK;i++){
		printf("   Nom: %s , Puissance : %d\n",p->base[i].nom,p->base[i].puissance);
	}
	
	printf("Statistique :\n   Attaque : %d \n   Defense : %d \n",p->stat_cur.att,p->stat_cur.defense);
	printf("XP :  %d / %d \n",p->experience_cur,p->experience_niveau_sup);
	printf("------------------------------------\n");
}


//Renvoie si un poketudiant doit evoluer
//Pourcentage en fonction de son niveau (20% niveau3, 37.5% niveau 4, 100% niveau 5)
int doitevoluer(int lvl){
	if(LVL_FIVE == lvl)
		return 1;
	int r=myrand(POURCENT_MINI,POURC_MAX);
	if(LVL_FOUR == lvl)
		if(r<POURC_THREE)
			return 1;
	if(LVL_THREE == lvl)
		if(r<POURC_FOUR)
			return 1;
	return 0;	
}

//Faire monter de niveau un poketudiant
void lvlup(Poketudiant *p){
	calculstatlevelup(p,1);
	soigne_Poketudiant(p);
	//p->lvl++;
}

//Calcule les nouvelles stats d'un poketudiant et les affiche
//lvlUp: 0->initialisation 1->lvl up (gere l'affichage)
void calculstatlevelup(Poketudiant * p, int lvlUp){
	char *nom = chaineVariete(p->pokemon.nom);
	p->lvl+=1;
	int att=((p->pokemon.stat_base.att*p->coef[0])*POURC_LEVELUP)/100;
	int def=((p->pokemon.stat_base.defense*p->coef[1])*POURC_LEVELUP)/100;;
	int pv_max=((p->pokemon.stat_base.pv_max_poke*p->coef[1])*POURC_LEVELUP)/100;


	if(lvlUp)
		printf("%s monte au niveau %d! \n ATT: %d+%d -> %d \n DEF: %d+%d -> %d \n PV: %d+%d -> %d \n "
		,nom,p->lvl
		,p->stat_cur.att,att,p->stat_cur.att+att
		,p->stat_cur.defense,def,p->stat_cur.defense+def
		,p->stat_cur.pv_max_poke,pv_max,p->stat_cur.pv_max_poke+pv_max);

	p->stat_cur.att=p->stat_cur.att+att;
	p->stat_cur.defense=p->stat_cur.defense+def;
	p->stat_cur.pv_max_poke=p->stat_cur.pv_max_poke+pv_max;
}


void evolution(Poketudiant *p){

		p->pokemon=recupPoke(p->pokemon.evolution);//change le poke
		p->stat_cur=calculStat(p->coef,p->pokemon.stat_base);
	
}


void gestionLevelUp(Poketudiant * p,int xp_add){
	
	char *nom, *nom2; 
	nom= chaineVariete(p->pokemon.nom);
	printf("%s a gagné %d experiences !\n",nom,xp_add);
	
	p->experience_cur+=xp_add;

	//if(p->experience_cur<p->experience_niveau_sup) return ;
	
	while(p->experience_cur>p->experience_niveau_sup)
	{
		if(p->pokemon.evolution!=NO_EVOLUTION&&doitevoluer(p->lvl)){
			evolution(p);
			nom2=chaineVariete(p->pokemon.nom);
			
			printf("*****************************\n\
FELICITATION! Votre %s a évolué en %s !\n\
*****************************\n",nom,nom2);
			
			p->experience_niveau_sup=xp_next(p->lvl);
			//return;
		}

		lvlup(p);
		
		p->experience_niveau_sup=xp_next(p->lvl);
	}
}

//libere un Poketudiant
void freePoketudiant(Poketudiant *p){
	free(p->base);
	free(p);
}


//Calcule xp necessaire pour monter de niveau quand niveau=lvl
int xp_next(int lvl){
	return CONST_LEVEL*((1.0+(float)lvl)/2.0);
}

