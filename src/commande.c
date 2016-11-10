
#include "../lib/joueur.h"
#include "../lib/commande.h"

void wild(Joueur * j1, int niv_min, int niv_max);

void rival(Joueur * j1, int niv_min, int niv_max);

void nurse(Joueur * j1)
{
	Sac *s= j1->inv.s;
	Cafetariat* c= j1->inv.c;
	for(int i=0; i<s->cur; i++)
		s->p[i]->pv_cur=s->p[i]->stat_cur.pv_max_poke;
	
	for(int i=0;i<NB_TABLE;i++){
		showRevision(c,i);
	}
	
}

void show_team(Joueur j1)
{
	afficheSac(j1.inv.s);
}

void show_cafet(Joueur j1)
{
	showCafetaria(j1.inv.c);
}

void show_revision_table(Joueur j1);

void showIndice(Joueur j1,int indice);

void move_table(Joueur * j1,int i , int j);

void drop(Joueur * j1 , int i);

void pick(Joueur * j1 , int i);

void release_com(Joueur * j1, int i);

void catch(Joueur * j1,int n);

void xp(Joueur * j1, int i , int n);
