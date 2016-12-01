#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../lib/joueur.h"
#include "../lib/globale.h"
#include "../lib/parsecommande.h"
#include "../lib/commande.h"


CmdHandling cmdFuncs[]={handle_wild,handle_rival,handle_nurse,handle_show,handle_move_table,handle_drop,handle_pick,handle_release,handle_catch,handle_switchP,handle_xp,handle_up,handle_bot,handle_rigth,handle_left};
char * cmdNames[]={"wild","rival","nurse","show","move-table","drop","pick","release","catch","switch","xp","up","bot","rigth","left"};

CmdHandling get_CmdHandling(char * firstWord){
	int i=0;
	for(i=0;i<NCMDS;++i){
			if(strcmp(firstWord,cmdNames[i])==0){
				return cmdFuncs[i];
			}
	}
	return NULL;
}

void lire_commande(Joueur * j1){
	int taille=0;//nombre d'arguments
	char texte[100] = {0};
	char * token;
	printf("texte : ");
	lire(texte, 100);

	//premier mot
	token = strtok (texte," ");
	
	CmdHandling commande=get_CmdHandling(token);
	
	
	if(!commande){
		printf("Commande Non Valide ! \n");
		return;
	}

	char * * arguments=malloc(sizeof(char*)*TAILLE);
	
	token = strtok (NULL, " ,");

    for(;token != NULL;taille++){
		if(taille>=TAILLE)
 			arguments=realloc(arguments, (taille+1) * sizeof(char*));
        arguments[taille]=malloc(sizeof(char)*(strlen(token)+1));

 		strcpy(arguments[taille],token);

 		token = strtok (NULL, " ,");
    }

    commande(arguments,j1,taille);
    
    for (int i=0; i<taille; i++)
		free(arguments[i]);
    free(arguments);
}
