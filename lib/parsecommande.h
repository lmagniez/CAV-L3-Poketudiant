#ifndef _PARSECOMANDE_H
#define _PARSECOMANDE_H

#define NCMDS 15
#define TAILLE 1
#define TAILLE_CHAINE 10

typedef void (*CmdHandling)(char ** arguments,Joueur * j1,int taille);

CmdHandling get_CmdHandling(char * firstWord);

void lire_commande(Joueur * j1);

#endif