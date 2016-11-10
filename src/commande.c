
#include <stdlib.h>
#include <stdio.h>

#include "../lib/joueur.h"
#include "../lib/commande.h"

#define ERR_OVERFLOW	"erreur, l'indice %d ne correspond a aucun poketudiant dans l'equipe\n"

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
	Sac *s = j1.inv.s;
	
	for(int i=0; i<s->cur; i++)
	{
		affichePoketudiant(s->p[i]);
	}
	
	//afficheSac();
}

void show_cafet(Joueur j1)
{
	showCafetaria(j1.inv.c);
}

void show_revision_table(Joueur j1, int table);

void showIndice(Joueur j1,int indice);

void move_table(Joueur * j1,int i , int j);

void drop(Joueur * j1 , int i);

void pick(Joueur * j1 , int i);

void release_com(Joueur * j1, int i);

void catch(Joueur * j1,int n);

void xp(Joueur * j1, int i , int n)
{
	Sac *s=j1->inv.s;
	if(i>s->cur||i<0)
		printf(ERR_OVERFLOW,i);
	else 
	{
		gestionLevelUp(s->p[i],n);
		affichePoketudiant(s->p[i]);
	}
	
	
}
