#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "../lib/globale.h"
#include "../lib/poketudiant.h"

int ID=0;

void init(Poketudiant *newP, int lvl){
	float tmp;

	//Calcul du coef on divise par 10 pour avoir un nombre decimal (3 coef differents un att , def et pv max
	for(int i=0;i<NB_COEF;i++){
		tmp=(float)my_rand(B_COEF_MIN,B_COEF_MAX);
		newP->coef[i]=tmp/10;
	}
	
	newP->id=ID++;

	newP->base=recup_attaque(newP->poke.spe);

	//Niveau 1 des stats
	newP->stat_cur=calcul_stat(newP->coef,newP->poke.stat_base);

	for(int i=2;i<= lvl;i++)
		calcul_stat_lvl_up(newP,0);

	newP->pv_cur=newP->stat_cur.pv_max_poke;
	
	newP->experience_cur=xp_next(newP->lvl-1);
		
	newP->experience_niveau_sup=xp_next(newP->lvl);
}

Poketudiant * new_poketudiant_random(int borne1, int borne2){
	
	
	
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
	
	newP->poke=new_poke_rand();
	
	int lvl=(int)my_rand(borne1,borne2);
	
	init(newP,lvl);

	return newP;
}

Poketudiant * new_poketudiant_type(variete t,int borne1, int borne2){
	srand(time(NULL));
	Poketudiant * newP=(Poketudiant *)malloc(sizeof(Poketudiant));
	newP->lvl=1;
	
	
	newP->poke=recup_poke(t);	
	
	int lvl=(int)my_rand(borne1,borne2);

	init(newP,lvl);

	return newP;
}

void soigne_poketudiant(Poketudiant * p){
	p->pv_cur=p->stat_cur.pv_max_poke;
}

//echange les poketudiants
void swap_poketudiant(Poketudiant * a , Poketudiant * b){
	Poketudiant p=*a;
	*a=*b;
	*b=p;
}

void affiche_poketudiant(Poketudiant * p){
	char * var=chaine_variete(p->poke.nom);
	char * type=chaine_type(p->poke.spe);
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
int doit_evoluer(int lvl){
	if(LVL_FIVE == lvl)
		return 1;
	int r=my_rand(POURCENT_MINI,POURC_MAX);
	if(LVL_FOUR == lvl)
		if(r<POURC_THREE)
			return 1;
	if(LVL_THREE == lvl)
		if(r<POURC_FOUR)
			return 1;
	return 0;	
}

//Faire monter de niveau un poketudiant
void lvl_up(Poketudiant *p){
	calcul_stat_lvl_up(p,1);
	soigne_poketudiant(p);
}

//Calcule les nouvelles stats d'un poketudiant et les affiche
//lvlUp: 0->initialisation 1->lvl up (gere l'affichage)
void calcul_stat_lvl_up(Poketudiant * p, int lvlUp){
	char *nom = chaine_variete(p->poke.nom);
	p->lvl+=1;
	int att=((p->poke.stat_base.att*p->coef[0])*POURC_LEVELUP)/100;
	int def=((p->poke.stat_base.defense*p->coef[1])*POURC_LEVELUP)/100;;
	int pv_max=((p->poke.stat_base.pv_max_poke*p->coef[1])*POURC_LEVELUP)/100;


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

		p->poke=recup_poke(p->poke.evolution);//change le poke
		p->stat_cur=calcul_stat(p->coef,p->poke.stat_base);
	
}


void gestion_lvl_up(Poketudiant * p,int xp_add){
	
	if(p->lvl==10)
		return;
	
	char *nom, *nom2; 
	nom= chaine_variete(p->poke.nom);
	printf("%s a gagné %d experiences !\n",nom,xp_add);
	
	p->experience_cur+=xp_add;

	//if(p->experience_cur<p->experience_niveau_sup) return ;
	
	while(p->experience_cur>p->experience_niveau_sup&&p->lvl<10)
	{
		
		if(p->poke.evolution!=NO_EVOLUTION&&doit_evoluer(p->lvl)){
			evolution(p);
			nom2=chaine_variete(p->poke.nom);
			
			printf("*****************************\n\
FELICITATION! Votre %s a évolué en %s !\n\
*****************************\n",nom,nom2);
			
			p->experience_niveau_sup=xp_next(p->lvl);
		}

		lvl_up(p);
		
		p->experience_niveau_sup=xp_next(p->lvl);
	}
	
	if(p->lvl==10)
	{
		p->experience_cur=p->experience_niveau_sup;
	}
}

//libere un Poketudiant
void free_poketudiant(Poketudiant *p){
	free(p->base);
	free(p);
}


//Calcule xp necessaire pour monter de niveau quand niveau=lvl
int xp_next(int lvl){
	return CONST_LEVEL*((1.0+(float)lvl)/2.0);
}

