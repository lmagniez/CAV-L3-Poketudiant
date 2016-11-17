#ifndef _PARSECOMANDE_H
#define _PARSECOMANDE_H

#define NCMDS 11
#define TAILLE 1
#define TAILLE_CHAINE 10

typedef void (*CmdHandling)(char ** arguments,Joueur * j1);

CmdHandling getCmdHandling(char * firstWord);

void lirecommande(Joueur * j1);

#endif
