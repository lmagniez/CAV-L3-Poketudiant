#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "../lib/joueur.h"
#include "../lib/globale.h"
#include "../lib/combat.h"

//Tour de l'ordi
int tour_ordi(Joueur * j, Poketudiant * p2){
	Poketudiant * p1=j->s->p[j->s->p1];
	int nba=my_rand(0,1);
	int k=my_rand(B_COEF_MIN,B_COEF_MAX);
	int resFaiblesse=faiblesse(p2->base[nba].t,p1->poke.spe);
	int power=p2->base[nba].puissance*resFaiblesse;
	int dommage=dommage_attaque(k/10.0,p2->stat_cur.att,p1->stat_cur.defense,power);
	p1->pv_cur=p1->pv_cur-dommage;
	affichage_tour(p2,p2->base[nba],1,resFaiblesse,dommage);//1: ennemi
	return 0;
}

//Affiche les actions possibles et demande une action au joueur
int tour_joueur(Joueur * j, Poketudiant * p2,int combat){
	int i;
	Poketudiant * p1;
	p1=j->s->p[j->s->p1];
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
	return choix_joueur(j,p2,combat);
}

int choix_joueur(Joueur * j, Poketudiant * p2,int combat){
	int reponse,dommage,power,k,probCapt,resFaiblesse;
	Poketudiant * p1;
	p1=j->s->p[j->s->p1];
	printf("Votre choix : ");
	reponse=lecture_entree();

	switch(reponse){
		case 1:
		case 2:
			reponse=reponse-1;
			k=my_rand(B_COEF_MIN,B_COEF_MAX);
			resFaiblesse=faiblesse(p1->base[reponse].t,p2->poke.spe);
			power = p1->base[reponse].puissance*resFaiblesse;
			dommage=dommage_attaque(k/10.0,p1->stat_cur.att,p2->stat_cur.defense,power);
			p2->pv_cur=p2->pv_cur-dommage;
			affichage_tour(p1,p1->base[reponse],0,resFaiblesse,dommage);//0: dresseur
		break;
		case 3:
			if(!fuite(p1->lvl,p2->lvl) || combat == 0){
				printf("Fuite Impossible !\n");
				return 0;
			}
			printf("Vous prenez la Fuite !\n");
			return FUITE;
		break;
		case 4:
			if(combat==0){
				printf("On ne capture pas un poketudiant d'un autre enseignant dresseur !\n");
				return 0;
			}
			probCapt=proba_capture(p2->pv_cur,p2->stat_cur.pv_max_poke);
			k=my_rand(POURCENT_MINI,POURCENT_MAXI);
			if(k<probCapt && combat == 1){
				printf("Vous avez Attrape le Poketudiant ! \n");
				return CAPTURE;
			}
			printf("Le Poketudiant s'est enfuie ! \n");
			return 0;
		break;
		case 5:
			affiche_sac(j->s);
			if(changer_poke_combat(j,1)==-1)choix_joueur(j,p2,combat);
			return CHANG_POKE;
		break;
		default:
			printf("Mauvaise Entrée ! ");
			choix_joueur(j,p2,combat);
		break;
	}
	return 0;
}

//Demande de changer un poketudiant en fonction de son id dans le sac 
//retourne -1: change pas de poketudiant (id=-1 ou meme pokemon)
//annulable: 1:peut faire retour 0:peut pas faire retour
int changer_poke_combat(Joueur * j, int annulable){
	int reponse;
	if(annulable)
		printf("\n-1: retour ");	
	printf("\nChoisissez le Poketudiant: ");
	reponse=lecture_entree();

	//annuler (que si autorisé)
	if(annulable&&(reponse==-1||reponse==j->s->p1)){
		return -1;
	}

	else if(reponse < j->s->cur && reponse >=0){
		changer_premier(j->s,reponse);
	}

	else{
		printf("Choix Incorrect");
		changer_poke_combat(j,annulable);
	}

	if(j->s->p[j->s->p1]->pv_cur<1){
		printf("\nLe Poketudiant est KO!!");
		changer_poke_combat(j,annulable);
	}

	return 0;
}

//Change de Poketudiant pour un joueur ordi
void  changer_poke_ordi(Joueur *j){
	Sac *s=j->s;
	int rand=my_rand(0,j->s->cur-1);
	changer_premier(j->s,rand);

	if(s->p[s->p1]->pv_cur<1)//poke
		changer_poke_ordi(j);
}

//Initialise un combat avec un dresseur rival
int combat_rival(Joueur *j,Joueur *rival){
	int a=0;
	int tabexp[TAILLE_SAC];
	Sac *s1,*s2;
	s1=j->s;
	s2=rival->s;
	
	for(int i=0; i<TAILLE_SAC; i++)
		tabexp[i]=0;
	tabexp[s1->p1]=1;
	
	
	
	Poketudiant *p1,*p2;
	//Poketudiant j
	p1=s1->p[s1->p1];
	//Poketudiant adverse
	p2=s2->p[s2->p1];
	
	affichage_combat(p1,p2);
	
	while(!a){
		a=tour_joueur(j,p2,0);
		if(p2->pv_cur<1){
			printf("Le Poketudiant ennemi est KO\n");
			p2->pv_cur=0;
			//rival.inv.s->p[rival.inv.s->p1]->pv_cur=0;

			calcul_xp(j,tabexp,p2->experience_cur);
			
			if(verif_vie(rival->s) == 0){
				printf("Vous avez Gagné le Combat ! \n");
				return 1;
				break;
			}

			//REINITIALISE A 0 
			for(int i=0; i<TAILLE_SAC; i++)
				tabexp[i]=0;
			tabexp[s1->p1]=1;
				
			changer_poke_ordi(rival);
			p2=s2->p[s2->p1];
			//printf("Le joueur envoie au combat: %s \n",p2->pokemon.nom);
			
		}

		if(a==CHANG_POKE){
			
			p1=s1->p[s1->p1];
			
		} //changement poketudiant

		a=tour_ordi(j,p2);
		if(p1->pv_cur<1){
			printf("Votre Poketudiant est KO \n");
			s1->p[s1->p1]->pv_cur=0;
			
			if(verif_vie(s1) == 0){ //test si encore des poketudiants en vie
				printf("Game Over !! \n");
				soigne_poketudiant(j->s->p[0]);//on soigne l'enseignant dresseur
				return 0;
			}

			affiche_sac(s1);
			changer_poke_combat(j,0);
			p1=s1->p[s1->p1];
		}
		affichage_combat(p1,p2);
	}
	return -1;
}

//initialise un combat de pokemon sauvage
void combat_sauvage(Joueur *j, Poketudiant * p2){
	int a=0;

	int tabexp[TAILLE_SAC];
	
	Sac *s=j->s;

	Poketudiant * p1=s->p[s->p1];
	for(int i=0; i<TAILLE_SAC; i++)
		tabexp[i]=0;
	tabexp[s->p1]=1;

	affichage_combat(p1,p2);

	while(!a){
		a=tour_joueur(j,p2,1);
		if(p2->pv_cur<1){
			printf("Le Poketudiant ennemi est KO\n");
			calcul_xp(j,tabexp,p2->experience_cur);
			free_poketudiant(p2);
			break;
		}

		if(a==FUITE){free_poketudiant(p2);break;} //fuite
		if(a==CAPTURE){ajout_inv(j,p2);break;} //capture


		if(a==CHANG_POKE){
			p1=s->p[s->p1];
			tabexp[s->p1]=1;
		} 
		a=tour_ordi(j,p2);

		if(p1->pv_cur<1){
			printf("Votre Poketudiant est KO \n");
			s->p[s->p1]->pv_cur=0;
			tabexp[s->p1]=0;//ne gagne pas d'xp si il est ko
			
			if(verif_vie(s) == 0){
				printf("Game Over !! ");
				soigne_poketudiant(j->s->p[0]);
				return;
			}

			affiche_sac(s);
			changer_poke_combat(j,0);
			p1=s->p[s->p1];
		}
		affichage_combat(p1,p2);
	}
}

//Calcul du taux d'xp a repartir sur chacun des poketudiants
void calcul_xp(Joueur *j,int tabexp[TAILLE_SAC],int xp_total){
	int nb_poke=0;
	for(int i=0;i<TAILLE_SAC;i++)
		nb_poke += tabexp[i];

	int nb_exp=(xp_total*(0.1))/nb_poke;

	for(int i=0;i<TAILLE_SAC;i++){
		if(tabexp[i]==1)
			gestion_lvl_up(j->s->p[i],nb_exp);
	}	
}

//Calcul de la probabilité de capture (2*max(1/2-pvEff/pvMax,0))
int proba_capture(int pv_eff , int pv_max){
	float taux=1.0*pv_eff/pv_max;
	float prob=0.5-taux;
	return 2*max(prob,POURCENT_MINI)*POURCENT_MAXI;
}

//Calcul de la fuite (0% si 3 niveaux de moins, 25% si 2 niveaux de moins, 40% si 1 niveau de moins, 50% si même niveau)
int fuite(int lvl_poke, int lvl_enemy){
	float r=my_rand(POURCENT_MINI,POURCENT_MAXI);
	
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

//Affichage d'une action effectué par un joueur
void affichage_tour(Poketudiant * p,attaque a, int isEnemy, int faiblesse,int dommage){
	char *enemy, *efficace;
	if(isEnemy) enemy=" ennemi"; else enemy="";
	if(faiblesse==2) efficace="C'est super efficace !"; else efficace="";
	
	char * var1=chaine_variete(p->poke.nom);
	printf("\n%s%s va attaquer ! \n %s utilise %s. %s \n%s%s inflige %d dommages\n\n",var1,enemy,var1,a.nom, efficace,var1,enemy, dommage);
}

//Affichage des informations de debut de combat
void affichage_combat(Poketudiant * p1, Poketudiant * p2){
	
	char * var1=chaine_variete(p1->poke.nom);
	char * var2=chaine_variete(p2->poke.nom);

	char * type1=chaine_type(p1->poke.spe);
	char * type2=chaine_type(p2->poke.spe);

	printf("---JOUEUR--------------------------ADVERSAIRE--\n");
	printf("-----------------------------------------------\n");
	printf(" %s (lvl.%d)\t\t%s (lvl.%d)\n",var1,p1->lvl,var2,p2->lvl);
	printf(" type: %s \t\t\t\t type: %s\n",type1,type2);
	printf(" pv: %d/%d \t\t\t\t pv: %d/%d\n",p1->pv_cur,p1->stat_cur.pv_max_poke,p2->pv_cur,p2->stat_cur.pv_max_poke);
	printf("-----------------------------------------------\n");
}

