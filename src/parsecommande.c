#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../lib/joueur.h"
#include "../lib/globale.h"
#include "../lib/parsecommande.h"
#include "../lib/commande.h"


#define NCMDS 11


typedef void (*CmdHandling)(Joueur * j1);

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

void appelfonction(Joueur * j1){

}


void lirecommande(){
	char texte[100] = {0};
	char * token;
	printf("texte : ");
	lire(texte, 100);
	//premier mot
	token = strtok (texte," ");
	
	CmdHandling commande=getCmdHandling(token);
	
	
		
    while (token != NULL){
        printf ("%s \n", token);
        token = strtok (NULL, " ,");
 
    }
}
