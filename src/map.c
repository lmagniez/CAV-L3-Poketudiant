#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../lib/joueur.h"
#include "../lib/combat.h"
#include "../lib/map.h"
#include "../lib/globale.h"
#include "../lib/commande.h"
#include "../lib/sac.h"


static int initPosition(int y, int x,char c,int rival){
	switch(c){
		case 'S' :
			position[0][0]=x;
			position[0][1]=y;
		break;
		case 'A' :
			position[rival][0]=x;
			position[rival][1]=y;
			rival++;
		break;
		case 'Z' :
			position[rival][0]=x;
			position[rival][1]=y;
			rival++;
		break;
		case 'E' :
			position[rival][0]=x;
			position[rival][1]=y;
			rival++;
		break;
	}
	return rival;
}

static FILE * generationMap(){
	FILE * fichier=fopen(FICHIER_MAP, "r");

	int ligne=0; //ligne de a remplir
	int rival=1;

	if (fichier == NULL) { printf("Erreur Fichier Map \n "); exit(0); }

	char chaine[128];

	 while ( ligne < TAILLE_MAX_LIGNE && fgets (chaine, sizeof(chaine),fichier)!= NULL ){

      	for(int i=0;i<TAILLE_MAX_CHAINE;i++){
      		rival=initPosition(ligne,i,chaine[i],rival);
      		map[ligne][i]=chaine[i];
      	}

      	ligne++;
    }

    return fichier;
}

static int nbmot(char * chaine){
	int compteur=0,taille = 0;
	char tampon[64];
	for(; sscanf(chaine += taille, "%63s%n", tampon, &taille) == 1; compteur++);
	return compteur;
}

static void init_tabRival(FILE * f){
	char chaine[128];
	char nom[50];
	int numRival,min,max;
	variete v;

	while (fgets (chaine, sizeof(chaine),f)!= NULL){
		if(chaine[0]!='\n'){
			if(nbmot(chaine)==2){
				sscanf(chaine,"%50s%d",nom,&numRival);
			}
			else if (nbmot(chaine)==3){
				sscanf(chaine,"%50s%d%d",nom,&min,&max);
				if(strcmp(nom,"ENSEIGNANT_DRESSEUR")==0){
					tab_rival[numRival-1]=init_rival_precis(min,max);
				}
				v=recup_variete(nom);
				if((int)v<0){
					printf("Erreur dans l'initialisation de la MAP\n");
					exit(0);
				}
				ajout_sac(tab_rival[numRival-1].s,new_poketudiant_type(v,min,max));
			}

		}
     }
	fclose(f);
}

static void findegame_looser(Joueur * j){
	printf("    ╔════════════════════════════════╗");
	printf("    ║           GAME OVER            ║");
	printf("    ╚════════════════════════════════╝");
	free_joueur(*j);
	libereJoueur();
	exit(0);
}

static void findegame_win(Joueur * j){
	printf("    ╔════════════════════════════════╗");
	printf("    ║       VOUS AVEZ GAGNE  !!      ║");
	printf("    ╚════════════════════════════════╝");
	free_joueur(*j);
	libereJoueur();
	exit(0);
}

void initMap(){
	FILE * f=generationMap();
	init_tabRival(f);
}

void gestionAction(Joueur * j){
	int nb_pourc=0;
	switch(save_char){
		case 'X':
		break;
		case 'N':
			nurse(j);
			printf("Vos poketudiants ont ete soignés :D\n");
		break;
		case 'O':
			nb_pourc=my_rand(0,POURCENT_MAXI);
			if(nb_pourc<=20)
				wild(j,1,NB_VARIETE);
		break;
		case 'A' :
			combat_rival(j,&(tab_rival[0])) == 1 ? save_char='B': findegame_looser(j);
			j->nb_point == 3 ? findegame_win(j) : j->nb_point++;
		break;
		case 'Z' :
			combat_rival(j,&(tab_rival[1])) == 1 ? save_char='B': findegame_looser(j);
			j->nb_point == 3 ? findegame_win(j) : j->nb_point++;
		break;
		case 'E' :
			combat_rival(j,&(tab_rival[2])) == 1 ? save_char='B': findegame_looser(j);
			j->nb_point == 3 ? findegame_win(j) : j->nb_point++;
		break;
	}
}

void libereJoueur(){
	for(int i=0;i<NB_RIVAL;i++)
		free_joueur(tab_rival[i]);
}

static void afficheMenu(int i){
	switch(i){
		case 0 :
			printf("    ╔════════════════════════════════╗");
		break;
		case 1 :
			printf("    ║             AIDE               ║");
		break;
		case 2 :
			printf("    ╚════════════════════════════════╝");
		break;
		case 3 :
			printf("    ║  ");
			printf(ANSI_COLOR_RED "██"ANSI_COLOR_RESET);
			printf("  : soigne  ");
			printf(ANSI_COLOR_MAGENTA "██"ANSI_COLOR_RESET);
			printf("  : rival   ");
			printf("  ║");
		break;
		case 4 :
			printf("    ║                                ║");
		break;
		case 5 :
			printf("    ║  ");
			printf(ANSI_COLOR_GREEN "██"ANSI_COLOR_RESET);
			printf("  : Herbes  ");
			printf( "██");
			printf("  : chemin  ");
			printf("  ║");
		break;
		case 6 :
			printf("    ║                                ║");
		break;
		case 7 :
			printf("    ║          DEPLACEMENT           ║");
		break;
		case 8 :
			printf("    ║                                ║");
		break;
		case 9 :
			printf("    ║  ↑:up  ↓:bot  →:right  ←:left  ║");
		break;
		case 10 :
			printf("    ║  ↑:w   ↓:s →  →:a      ←:d     ║");
		break;
		case 11 :
			printf("    ╚════════════════════════════════╝");
		break;
	}
}

void afficheMap(){
		for(int i=0;i<TAILLE_MAX_LIGNE;i++){
			for(int j=0;j<TAILLE_MAX_CHAINE;j++){
				switch(map[i][j]){
					case 'X' :
						printf("██");
					break;
					case 'N' :
						printf(ANSI_COLOR_RED "██" ANSI_COLOR_RESET);
					break;
					case 'S' :
						printf(ANSI_COLOR_YELLOW "♀♀" ANSI_COLOR_RESET);
					break;
					case 'O' :
						printf(ANSI_COLOR_GREEN "██" ANSI_COLOR_RESET);
					break;
					case 'A' :
					case 'Z' :
					case 'E' :
						printf(ANSI_COLOR_MAGENTA "██" ANSI_COLOR_RESET);
					break;
					case 'B' :
						printf(ANSI_COLOR_CYAN "██" ANSI_COLOR_RESET);
					break;
				}
	        }
	        afficheMenu(i);
        	printf("\n");
    	}
}
