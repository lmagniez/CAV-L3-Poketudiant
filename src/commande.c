
#include <stdlib.h>
#include <stdio.h>

#include "../lib/joueur.h"
#include "../lib/combat.h"
#include "../lib/commande.h"

#define ERR_OVERFLOW	"erreur, l'indice %d ne correspond a aucun poketudiant dans l'equipe\n"

void wild(Joueur * j1, int niv_min, int niv_max)
{
	Poketudiant * tmp=newPoketudiant_random(niv_min,niv_max);
	combatSauvage(j1,tmp);
	freePoketudiant(tmp);
}

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
		affichePoketudiant(s->p[i]);
	
}

void show_cafet(Joueur j1)
{
	showCafetaria(j1.inv.c);
}

void show_revision_table(Joueur j1, int table)
{
	showRevision(j1.inv.c,table);
}

//affiche le poketudiant dont l'id est id, recherche dans cafet et sac
void show_indice(Joueur j1,int id)
{
	
	Sac *s=j1.inv.s;
	Cafetariat *c=j1.inv.c;
	
	
	//parcoure sac
	for(int i=0; i<s->cur; i++)
	{
		if(s->p[i]->id==id)
		{
			printf("Poketudiant id:%d dans le sac à l'indice %d \n",id,i);
			affichePoketudiant(s->p[i]);
			
		}
	}
	
	//parcoure cafet
	for(int i=0; i<NB_TOTAL; i++)
	{
		if(c->p[i]!=NULL)
			if(c->p[i]->id==id)
			{
				printf("Poketudiant id:%d dans la cafet à l'indice %d (table %d)\n",id,i,i/NB_CHAISE);
				affichePoketudiant(c->p[i]);
			}
	}
	
	
	
	
}

//Deplace le poketudiant d'id id à la table table
void move_table(Joueur * j1,int id , int table)
{
	Sac *s=j1->inv.s;
	Cafetariat *c=j1->inv.c;
	
	
	//parcoure sac
	for(int i=0; i<s->cur; i++)
	{
		if(s->p[i]->id==id)
		{
			if(i==0)
			{
				printf("On ne peut pas déplacer l'enseignant dresseur! \n");
				return;
			}	
			
			printf("Poketudiant id:%d dans le sac à l'indice %d \n",id,i);
			drop_pokemon_table(&(j1->inv),i,table);
			return;
			
		}
	}
	
	//parcoure cafet
	for(int i=0; i<NB_TOTAL; i++)
	{
		//doit etre diff de null sinon on ne peut pas comparer
		if(c->p[i]!=NULL)
			if(c->p[i]->id==id)
			{
				printf("Poketudiant id:%d dans la cafet à l'indice %d (table %d)\n",id,i,i/NB_CHAISE);
				
				if(i/NB_CHAISE==table)return;//deja dans la table, pas besoin de deplacgi
				
				//chercher si table pleine ou non
				for(int j=(table*NB_CHAISE);j<(table*NB_CHAISE)+NB_CHAISE;j++){
					if(c->p[j]==NULL)
					{
						c->p[j]=c->p[i];
						c->p[i]=NULL;
						return;
					}
				}
				printf("table pleine! \n");
				return;
				
			}
	}
	
}


void switchP(Joueur *j1, int id1, int id2)
{
	Poketudiant *p1 = get_by_id(&(j1->inv),id1);
	Poketudiant *p2 = get_by_id(&(j1->inv),id2);
	
	if(p1==NULL||p2==NULL)printf("Erreur, un ou plusieurs identifiants n'existent pas.\n");
	else{
		Poketudiant tmp=*p1;
		*p1=*p2;
		*p2=tmp;
	}
	
	
}


//Deplace le poketudiant d'indice i (equipe->cafeteriat)
void drop(Joueur * j1 , int i)
{
	drop_pokemon(&(j1->inv),i);
}

//Deplace le poketudiant d'indice i (cafeteriat->equipe)
void pick(Joueur * j1 , int i)
{
	pick_pokemon(&(j1->inv),i);
}

//relache le poketudiant en position i de la cafetariat
void release(Joueur * j1, int i)
{
	if(j1->inv.c->p[i])
	{
		freePoketudiant(j1->inv.c->p[i]);
		j1->inv.c->p[i]=NULL;
		printf("Poketudiant en indice %d relaché \n", i);
	}
}

void catch(Joueur * j1,int n)
{
	for(int i=0; i<n; i++)
		ajout_inv(&(j1->inv), newPoketudiant_random(1,5));
}

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
