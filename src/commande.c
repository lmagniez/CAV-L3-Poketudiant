
#include "../lib/joueur.h"
#include "../lib/commande.h"

void wild(Joueur * j1, int niv_min, int niv_max);

void rival(Joueur * j1, int niv_min, int niv_max);

void nurse(Joueur * j1);

void showteam(Joueur j1);

void showCafet(Joueur j1);

void show_revision_table(Joueur j1);

void showIndice(Joueur j1,int indice);

void move_table(Joueur * j1,int i , int j);

void drop(Joueur * j1 , int i);

void pick(Joueur * j1 , int i);

void release_com(Joueur * j1, int i);

void catcch(Joueur * j1,int n);

void xp(Joueur * j1, int i , int n);