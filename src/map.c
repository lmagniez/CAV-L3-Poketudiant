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

static void generationMap(){
	FILE * fichier=fopen(FICHIER_MAP, "r");
	
	int i=0,ligne=0; //ligne de a remplir
	int rival=1;
	char caractereActuel;

	if (fichier == NULL) { printf("Erreur Fichier Map \n "); exit(0); }


	do{
        caractereActuel = fgetc(fichier); // On lit le caractère

        if(caractereActuel=='\n' || caractereActuel=='\0' || caractereActuel==' ' || caractereActuel=='?')continue;

        map[ligne][i]=caractereActuel;

        rival=initPosition(ligne,i,caractereActuel,rival);

        i++;
        if(i==TAILLE_MAX_CHAINE){i=0;ligne++;}
    }while(ligne < TAILLE_MAX_LIGNE && caractereActuel != EOF);

    fclose(fichier);
}

void initMap(){
	generationMap();
	afficheMap();
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

void afficheMap(){
		for(int i=0;i<TAILLE_MAX_LIGNE;i++){
		for(int j=0;j<TAILLE_MAX_CHAINE;j++){
			switch(map[i][j]){
				case 'X' :
					printf("▓");
				break;
				case 'N' :
					printf(ANSI_COLOR_RED "▓" ANSI_COLOR_RESET); 
				break;
				case 'S' :
					printf(ANSI_COLOR_YELLOW "♀" ANSI_COLOR_RESET); 
				break;
				case 'O' :
					printf(ANSI_COLOR_GREEN "▓" ANSI_COLOR_RESET);
				break;
				case 'A' :
					printf(ANSI_COLOR_MAGENTA "▓" ANSI_COLOR_RESET);
				break;
				case 'Z' :
					printf(ANSI_COLOR_MAGENTA "▓" ANSI_COLOR_RESET);
				break;
				case 'E' :
					printf(ANSI_COLOR_MAGENTA "▓" ANSI_COLOR_RESET);
				break;
			}
        }
        printf("\n");
    }
}
