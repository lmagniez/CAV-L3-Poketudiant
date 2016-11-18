#ifndef _COMMANDE_H
#define _COMMANDE_H

void Handlewild(char ** arguments,Joueur *j1,int taille_arg);

void Handlerival(char ** arguments,Joueur *j1,int taille_arg);

void Handlenurse(char ** arguments,Joueur *j1,int taille_arg);

void Handleshow(char ** arguments,Joueur *j1,int taille_arg);

void Handlemove_table(char ** arguments,Joueur *j1,int taille_arg);

void Handledrop(char ** arguments,Joueur *j1,int taille_arg);

void Handlepick(char ** arguments,Joueur *j1,int taille_arg);

void Handlerelease(char ** arguments,Joueur *j1,int taille_arg);

void Handlecatch(char ** arguments,Joueur *j1,int taille_arg);

void HandleswitchP(char ** arguments,Joueur *j1,int taille_arg);

void Handlexp(char ** arguments,Joueur *j1,int taille_arg);


void wild(Joueur * j1, int niv_min, int niv_max);

void rival(Joueur * j1, int niv_min, int niv_max);

void nurse(Joueur * j1);

void show_team(Joueur * j1);

void show_cafet(Joueur * j1);

void show_revision_table(Joueur * j1, int table);

void show_indice(Joueur * j1,int indice);

void move_table(Joueur * j1,int id , int table);

void drop(Joueur * j1 , int i);

void pick(Joueur * j1 , int i);

void release(Joueur * j1, int i);

void catch(Joueur * j1,int n);

void switchP(Joueur * j1, int id1, int id2);

void xp(Joueur * j1, int i , int n);

int isInt(char *s);

#endif
