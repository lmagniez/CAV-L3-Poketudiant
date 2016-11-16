#ifndef _COMMANDE_H
#define _COMMANDE_H

void Handlewild(Joueur *j1);

void Handlerival(Joueur *j1);

void Handlenurse(Joueur *j1);

void Handleshow(Joueur *j1);

void Handlemove_table(Joueur *j1);

void Handledrop(Joueur *j1);

void Handlepick(Joueur *j1);

void Handlerelease(Joueur *j1);

void Handlecatch(Joueur *j1);

void HandleswitchP(Joueur *j1);

void Handlexp(Joueur *j1);


void wild(Joueur * j1, int niv_min, int niv_max);

void rival(Joueur * j1, int niv_min, int niv_max);

void nurse(Joueur * j1);

void show(Joueur * j1, char ** param);

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

#endif
