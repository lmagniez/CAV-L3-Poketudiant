#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "../lib/joueur.h"
#include "../lib/globale.h"
#include "../lib/combat.h"

int tourordi(Joueur * j, Poketudiant * p2){
	Poketudiant * p1=j->inv.s->p[j->inv.s->p1];
	int nba=myrand(0,2);
	int k=myrand(B_COEF_MIN,B_COEF_MAX);
	int power = p2->base[nba].puissance*faiblesse(p2->base[nba].t,p1->pokemon.spe);
	int dommage=domageattaque(k/10.0,p2->stat_cur.att,p1->stat_cur.defense,power);
	p1->pv_cur=p1->pv_cur-dommage;
	affichageTour(p2,p2->base[nba]);
	return 0;
}

int tourjoueur(Joueur * j, Poketudiant * p2,int combat){
	int i;
	Poketudiant * p1=j->inv.s->p[j->inv.s->p1];
	printf("\n---------------------------\n");
	printf("Attaque : \n");
	
	for(i=0;i<N_ATTACK;i++){
		printf("   %d - Nom: %s\n",i+1,p1->base[i].nom);
	}

	printf("Action \n");
	printf("   %d - Fuite\n",++i);
	printf("   %d - Capture\n",++i);
	printf("   %d - Changer Poketudiant\n",++i);
	printf("---------------------------\n");
	//si 0 on continue le combat si 1 fuite reussi si 2 capture reussi 3 si changement pokemon
	return choixJoueur(j,p2,combat);
}

int choixJoueur(Joueur * j, Poketudiant * p2,int combat){
	int reponse,dommage,power,k,probCapt;
	Poketudiant * p1=j->inv.s->p[j->inv.s->p1];
	printf("Votre choix : ");
	scanf("%d", &reponse);

	switch(reponse){
		case 1:
		case 2:
			reponse=reponse-1;
			k=myrand(B_COEF_MIN,B_COEF_MAX);
			power = p1->base[reponse].puissance*faiblesse(p1->base[reponse].t,p2->pokemon.spe);
			dommage=domageattaque(k/10.0,p1->stat_cur.att,p2->stat_cur.defense,power);
			p2->pv_cur=p2->pv_cur-dommage;
			affichageTour(p1,p1->base[reponse]);
		break;
		case 3:
			if(!fuite(p1->lvl,p2->lvl) || combat == 1){
				printf("Fuite Impossible !\n");
				return 0;
			}
			printf("Vous prenez la Fuite !\n");
			return FUITE;
		break;
		case 4:
			probCapt=probaCapture(p2->pv_cur,p2->stat_cur.pv_max_poke);
			printf("probcapt: %d\n",probCapt);
			k=myrand(POURCENT_MINI,POURCENT_MAXI);
			if(k<probCapt && combat == 0){
				printf("Vous avez Attrape le Poketudiant ! \n");
				return CAPTURE;
			}
			printf("Le Poketudiant s'est enfuie ! \n");
			return 0;
		break;
		case 5:
			afficheSac(j->inv.s);
			changemntPcombat(j);
			return CHANG_POKE;
		break;
		default:
			printf("Mauvaise Entrée ! ");
			choixJoueur(j,p2,combat);
		break;
	}
	return 0;
}

void changemntPcombat(Joueur * j){
	int reponse;
	printf("\nChoississez le Poketudiant: ");
	scanf("%d", &reponse);

	if(reponse < j->inv.s->cur && reponse >=0){
		changerPrem(j->inv.s,reponse);
	}

	else{
		printf("Choix Incorrect");
		changemntPcombat(j);
	}

	if(j->inv.s->p[j->inv.s->p1]->pv_cur<1){
		printf("\nLe Poketudiant est KO!!");
		changemntPcombat(j);
	}

	printf("\n");
}

void  changerPokeOrdi(Joueur * j){
	int rand=myrand(0,j->inv.s->p1);
	changerPrem(j->inv.s,rand);

	if(j->inv.s->p[j->inv.s->p1]->pv_cur<1){
		changerPokeOrdi(j);
	}
}

void combatRival(Joueur j,Joueur rival){
	int a=0;
	int * tabexp=(int *)malloc(TAILLE_SAC*sizeof(int));

	//Poketudiant j
	Poketudiant * p1=j.inv.s->p[j.inv.s->p1];

	//Poketudiant adverse
	Poketudiant * p2=rival.inv.s->p[rival.inv.s->p1];
	
	while(a){
		a=tourjoueur(&j,p2,0);
		if(p2->pv_cur<1){
			printf("Le Poketudiant ennemi est KO\n");
			rival.inv.s->p[rival.inv.s->p1]->pv_cur=0;

			calculxp(&j,tabexp,p2->experience_cur);
			
			if(verifvie(j.inv.s) == 0){
				printf("Vous avez Gagnez le Combat ! ");
				break;
			}

			tabexp=(int *)malloc(TAILLE_SAC*sizeof(int));
			changerPokeOrdi(&rival);
			p2=rival.inv.s->p[rival.inv.s->p1];
		}

		if(a==CHANG_POKE){
			p1=j.inv.s->p[j.inv.s->p1];
			tabexp[j.inv.s->p1]=1;
		} //changement poketudiant

		a=tourordi(&j,p2);
		if(p1->pv_cur<1){
			printf("Votre Poketudiant est KO \n");
			j.inv.s->p[j.inv.s->p1]->pv_cur=0;
			
			if(verifvie(j.inv.s) == 0){ //test si encore des poketudiants en vie
				printf("Game Over !! ");
				exit(0);
			}

			afficheSac(j.inv.s);
			changemntPcombat(&j);
			p1=j.inv.s->p[j.inv.s->p1];
		}
		affichageentetour(p1,p2);
	}
}

void combatSauvage(Joueur j, Poketudiant * p2){
	int a=0;

	int * tabexp=(int *)malloc(TAILLE_SAC*sizeof(int));

	Poketudiant * p1=j.inv.s->p[j.inv.s->p1];
	tabexp[j.inv.s->p1]=1;

	affichagecombat(p1,p2);

	while(!a){
		a=tourjoueur(&j,p2,0);
		if(p2->pv_cur<1){
			printf("Le Poketudiant ennemi est KO\n");
			calculxp(&j,tabexp,p2->experience_cur);
			break;
		}

		if(a==FUITE){break;} //fuite
		if(a==CAPTURE){ajout_inv(&(j.inv),p2);break;} //capture
		
		if(a==CHANG_POKE){
			p1=j.inv.s->p[j.inv.s->p1];
			tabexp[j.inv.s->p1]=1;
		} //changement poketudiant

		a=tourordi(&j,p2);

		if(p1->pv_cur<1){
			printf("Votre Poketudiant est KO \n");
			j.inv.s->p[j.inv.s->p1]->pv_cur=0;
			
			if(verifvie(j.inv.s) == 0){
				printf("Game Over !! ");
				exit(0);
			}

			afficheSac(j.inv.s);
			changemntPcombat(&j);
			p1=j.inv.s->p[j.inv.s->p1];
		}
		affichageentetour(p1,p2);
	}
}

void calculxp(Joueur *j,int tabexp[TAILLE_SAC],int xp_total){
	int nb_poke=0;
	for(int i=0;i<TAILLE_SAC;i++)
		nb_poke += tabexp[i] == 1 ? 1 : 0;

	int nb_exp=xp_total/nb_poke;

	for(int i=0;i<TAILLE_SAC;i++){
		gestionLevelUp(j->inv.s->p[i],nb_exp);
	}	
}

int probaCapture(int pv_eff , int pv_max){
	float prob=0.5-(1.0*pv_eff/pv_max);
	prob=fabs(prob);
	return 2*max(prob,POURCENT_MINI)*POURCENT_MAXI;
}

int fuite(int lvl_poke, int lvl_enemy){
	float r=myrand(POURCENT_MINI,POURCENT_MAXI);
	
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

void affichageTour(Poketudiant * p,attaque a){
	char * var1=chaineVariete(p->pokemon.nom);
	printf("\n%s va attaquer ! %s utilise %s \n\n",var1,var1,a.nom);
}

void affichagecombat(Poketudiant * p1, Poketudiant * p2){
	
	char * var1=chaineVariete(p1->pokemon.nom);
	char * var2=chaineVariete(p2->pokemon.nom);

	char * type1=chaineType(p1->pokemon.spe);
	char * type2=chaineType(p2->pokemon.spe);

	printf("------------       ------------\n");
	printf(" %s          %s\n",var1,var2);
	printf(" %s           %s\n",type1,type2);
	printf("------------       ------------\n");
}

void affichageentetour(Poketudiant * p1, Poketudiant * p2){
	char * var1=chaineVariete(p1->pokemon.nom);
	char * var2=chaineVariete(p2->pokemon.nom);

	printf("%s %d/%d ------ ",var1,p1->pv_cur,p1->stat_cur.pv_max_poke);
	printf("%s %d/%d\n\n",var2,p2->pv_cur,p2->stat_cur.pv_max_poke);
}