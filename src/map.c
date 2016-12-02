#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../lib/Joueur.h"
#include "../lib/map.h"
#include "../lib/globale.h"
#include "../lib/commande.h"


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

static void init_tabRival(FILE * f){
	char chaine[128];
	while (fgets (chaine, sizeof(chaine),f)!= NULL){
		if(chaine[0]!='\n')
			printf("%s",chaine);
     }
     printf("\n");
	fclose(f);
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
			printf("    ║             MENU               ║");
		break;
		case 2 :
			printf("    ║                                ║");
		break;
		case 3 :
			printf("    ║                                ║");
		break;
		case 4 :
			printf("    ║                                ║");
		break;
		case 5 :
			printf("    ║                                ║");
		break;
		case 6 :
			printf("    ║                                ║");
		break;
		case 7 :
			printf("    ║                                ║");
		break;
		case 8 :
			printf("    ║                                ║");
		break;
		case 9 :
			printf("    ║                                ║");
		break;
		case 10 :
			printf("    ║                                ║");
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
				}
	        }
	        afficheMenu(i);
        	printf("\n");
    	}
}
