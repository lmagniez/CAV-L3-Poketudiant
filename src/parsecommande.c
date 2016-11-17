#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../lib/joueur.h"
#include "../lib/globale.h"
#include "../lib/parsecommande.h"
#include "../lib/commande.h"


CmdHandling cmdFuncs[]={Handlewild,Handlerival,Handlenurse,Handleshow,Handlemove_table,Handledrop,Handlepick,Handlerelease,Handlecatch,HandleswitchP,Handlexp};
char * cmdNames[]={"wild","rival","nurse","show","switch","move-table","drop","pick","relase","catch","xp"};

CmdHandling getCmdHandling(char * firstWord){
	int i=0;
	for(i=0;i<NCMDS;++i){
		if(strcmp(firstWord,cmdNames[i])==0)
			return cmdFuncs[i];
	}
	return NULL;
}

void lirecommande(Joueur * j1){
	int taille=0;
	char texte[100] = {0};
	char * token;
	printf("texte : ");
	lire(texte, 100);

	//premier mot
	token = strtok (texte," ");
	
	CmdHandling commande=getCmdHandling(token);

	if(!commande){
		printf("Commande Non Valide ! \n");
		return;
	}

	char * * arguments=malloc(sizeof(char*)*TAILLE);
	
	token = strtok (NULL, " ,");

    for(;token != NULL;taille++){
    	if(taille>TAILLE)
 			arguments=realloc(arguments, taille * sizeof(char));
        
        arguments[taille]=malloc(sizeof(char)*(strlen(token)+1));

 		strcpy(arguments[taille],token);

 		token = strtok (NULL, " ,");
    }

    if(taille==0){
    	printf("Aucune Commande n'a aucun argumements ! \n");
    	return ;
    }

    commande(arguments,j1);

}
