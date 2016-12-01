#ifndef _COMMANDE_H
#define _COMMANDE_H

void handle_wild(char ** arguments,Joueur *j1,int taille_arg);

void handle_rival(char ** arguments,Joueur *j1,int taille_arg);

void handle_nurse(char ** arguments,Joueur *j1,int taille_arg);

void handle_show(char ** arguments,Joueur *j1,int taille_arg);

void handle_move_table(char ** arguments,Joueur *j1,int taille_arg);

void handle_drop(char ** arguments,Joueur *j1,int taille_arg);

void handle_pick(char ** arguments,Joueur *j1,int taille_arg);

void handle_release(char ** arguments,Joueur *j1,int taille_arg);

void handle_catch(char ** arguments,Joueur *j1,int taille_arg);

void handle_switchP(char ** arguments,Joueur *j1,int taille_arg);

void handle_xp(char ** arguments,Joueur *j1,int taille_arg);

void handle_up(char ** arguments,Joueur *j1,int taille_arg);

void handle_bot(char ** arguments,Joueur *j1,int taille_arg);

void handle_rigth(char ** arguments,Joueur *j1,int taille_arg);

void handle_left(char ** arguments,Joueur *j1,int taille_arg);

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

int is_int(char *s);

#endif
