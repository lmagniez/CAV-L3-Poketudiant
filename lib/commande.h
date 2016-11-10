#ifndef _COMMANDE_H
#define _COMMANDE_H

void wild(Joueur * j1, int niv_min, int niv_max);

void rival(Joueur * j1, int niv_min, int niv_max);

void nurse(Joueur * j1);

void show_team(Joueur j1);

void show_cafet(Joueur j1);

void show_revision_table(Joueur j1, int table);

void show_indice(Joueur j1,int indice);

void move_table(Joueur * j1,int i , int j);

void drop(Joueur * j1 , int i);

void pick(Joueur * j1 , int i);

void release_com(Joueur * j1, int i);

void catch(Joueur * j1,int n);

void xp(Joueur * j1, int i , int n);

#endif
