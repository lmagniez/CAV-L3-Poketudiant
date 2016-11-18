
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../lib/joueur.h"
#include "../lib/combat.h"
#include "../lib/commande.h"

#define ERR_OVERFLOW	"erreur, l'indice %d ne correspond a aucun poketudiant dans l'equipe\n"
#define ERR_COMMANDE	"Erreur Syntaxe Commande ! \n" 
#define ERR_COMMANDE_NB "Erreur syntaxe, veuillez entrer un entier\n"
#define ERR_POKE_ID 	"Il n'y a aucun poketudiant correspondant à l'id: %d\n"
#define ERR_POKE_LVL	"Un poketudiant ne peut pas dépasser le lvl 10! (et ne peut pas être en dessous de 0...)\n"

void Handlewild(char ** arguments,Joueur *j1,int taille_arg){
	if(taille_arg!=2){printf(ERR_COMMANDE);return;}

	int buffer[2];
	for(int i=0;i<taille_arg;i++){
		buffer[i]=(int)strtol(arguments[i],NULL,10);
	}
	
	wild(j1,buffer[0],buffer[1]);
}

void Handlerival(char ** arguments,Joueur *j1,int taille_arg){
	if(taille_arg!=2){printf(ERR_COMMANDE);return;}

	int buffer[2];
	for(int i=0;i<taille_arg;i++){
		buffer[i]=(int)strtol(arguments[i],NULL,10);
	}
	
	rival(j1,buffer[0],buffer[1]);
}

void Handlenurse(char ** arguments,Joueur *j1,int taille_arg){
	if(taille_arg!=0){printf(ERR_COMMANDE);return;}
	
	nurse(j1);
}

void Handleshow(char ** arguments,Joueur *j1,int taille_arg){
	int nb;

	if(taille_arg == 1 && strcmp(arguments[0],"pokecafeteria")==0){
		show_cafet(j1);
	}

	else if(taille_arg == 1 && strcmp(arguments[0],"team")==0){
		show_team(j1);
	}

	else if(taille_arg == 1 ){
		if(isInt(arguments[0])){	
			int nb=(int)strtol(arguments[0],NULL,10);
			show_indice(j1,nb);
		}
		else{
			printf(ERR_COMMANDE_NB);
		}
	}

	else if(taille_arg == 2 && strcmp(arguments[0],"revision-table")==0){
		if(isInt(arguments[1])){
			nb=(int)strtol(arguments[1],NULL,10);
			show_revision_table(j1,nb);
		}
		else{
			printf(ERR_COMMANDE_NB);
		}
	}

	else{printf(ERR_COMMANDE);return;}
}

void HandleswitchP(char ** arguments,Joueur *j1,int taille_arg){
	if(taille_arg!=2){printf(ERR_COMMANDE);return;}

	int buffer[2];
	for(int i=0;i<taille_arg;i++){
		
		if(isInt(arguments[i])){
			buffer[i]=(int)strtol(arguments[i],NULL,10);
		}
		else{
			printf(ERR_COMMANDE_NB);
			return;
		}
	}
	
	switchP(j1,buffer[0],buffer[1]);
}

void Handlemove_table(char ** arguments,Joueur *j1,int taille_arg){
	if(taille_arg!=2){printf(ERR_COMMANDE);return;}

	int buffer[2];
	for(int i=0;i<taille_arg;i++){
		if(isInt(arguments[i])){
			buffer[i]=(int)strtol(arguments[i],NULL,10);
		}
		else{
			printf(ERR_COMMANDE_NB);
			return;
		}
	}
	
	move_table(j1,buffer[0],buffer[1]);

}

void Handledrop(char ** arguments,Joueur *j1,int taille_arg){
	if(taille_arg!=1){printf(ERR_COMMANDE);return;}

	int id;
	for(int i=0;i<taille_arg;i++){
		if(isInt(arguments[i]))
			id=(int)strtol(arguments[i],NULL,10);
		else{
			printf(ERR_COMMANDE_NB);
			return;
		}	
	}
	
	drop(j1,id);
}

void Handlepick(char ** arguments,Joueur *j1,int taille_arg){
	if(taille_arg!=1){printf(ERR_COMMANDE);return;}

	int id;
	for(int i=0;i<taille_arg;i++){
		if(isInt(arguments[i]))
			id=(int)strtol(arguments[i],NULL,10);
		else{
			printf(ERR_COMMANDE_NB);
			return;
		}	
	}
	
	pick(j1,id);
}

void Handlerelease(char ** arguments,Joueur *j1,int taille_arg){
	if(taille_arg!=1){printf(ERR_COMMANDE);return;}

	int id;
	for(int i=0;i<taille_arg;i++){
		if(isInt(arguments[i]))
			id=(int)strtol(arguments[i],NULL,10);
		else{
			printf(ERR_COMMANDE_NB);
			return;
		}	
	}

	release(j1,id);
}

void Handlecatch(char ** arguments,Joueur *j1,int taille_arg){
	if(taille_arg!=1){printf(ERR_COMMANDE);return;}

	int id;
	for(int i=0;i<taille_arg;i++){
		if(isInt(arguments[i]))
			id=(int)strtol(arguments[i],NULL,10);
		else{
			printf(ERR_COMMANDE_NB);
			return;
		}	
	}

	catch(j1,id);
}

void Handlexp(char ** arguments,Joueur *j1,int taille_arg){
	if(taille_arg!=2){printf(ERR_COMMANDE);return;}

	int buffer[2];
	for(int i=0;i<taille_arg;i++){
		if(isInt(arguments[i])){
			buffer[i]=(int)strtol(arguments[i],NULL,10);
		}
		else{
			printf(ERR_COMMANDE_NB);
			return;
		}
	}
	
	xp(j1,buffer[0],buffer[1]);
}


void wild(Joueur * j1, int niv_min, int niv_max)
{
	
	if(niv_min<0||niv_max>10)
	{
		printf(ERR_POKE_LVL);
		return;
	}
	
	Poketudiant * tmp=newPoketudiant_random(niv_min,niv_max);
	combatSauvage(j1,tmp);
	freePoketudiant(tmp);
}

void rival(Joueur * j1, int niv_min, int niv_max)
{
	if(niv_min<0||niv_max>10)
	{
		printf(ERR_POKE_LVL);
		return;
	}
	
	Joueur j= init_inv_rival(niv_min, niv_max);
	combatRival(j1,&j);
	
	
}

void nurse(Joueur * j1)
{
	Sac *s= j1->s;
	Cafetariat* c= j1->c;
	for(int i=0; i<s->cur; i++)
		s->p[i]->pv_cur=s->p[i]->stat_cur.pv_max_poke;
	
	for(int i=0;i<NB_TABLE;i++){
		showRevision(c,i);
	}
	
}

void show_team(Joueur * j1)
{
	Sac *s = j1->s;
	for(int i=0; i<s->cur; i++)
		affichePoketudiant(s->p[i]);
	
}

void show_cafet(Joueur * j1)
{
	showCafetaria(j1->c);
}

void show_revision_table(Joueur * j1, int table)
{
	showRevision(j1->c,table);
}

//affiche le poketudiant dont l'id est id, recherche dans cafet et sac
void show_indice(Joueur * j1,int id)
{

	Sac *s=j1->s;
	Cafetariat *c=j1->c;
	
	
	//parcoure sac
	for(int i=0; i<s->cur; i++)
	{
		if(s->p[i]->id==id)
		{
			printf("Poketudiant id:%d dans le sac à l'indice %d \n",id,i);
			affichePoketudiant(s->p[i]);
			return;
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
				return;
			}
	}
	
	printf(ERR_POKE_ID,id);
	
	
}

//Deplace le poketudiant d'id id à la table table
void move_table(Joueur * j1,int id , int table)
{
	Sac *s=j1->s;
	Cafetariat *c=j1->c;
	
	
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
			drop_pokemon_table(j1,i,table);
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
	Poketudiant *p1 = get_by_id(j1,id1);
	Poketudiant *p2 = get_by_id(j1,id2);
	
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
	drop_pokemon(j1,i);
}

//Deplace le poketudiant d'indice i (cafeteriat->equipe)
void pick(Joueur * j1 , int i)
{
	pick_pokemon(j1,i);
}

//relache le poketudiant en position i de la cafetariat
void release(Joueur * j1, int i)
{
	if(j1->c->p[i])
	{
		freePoketudiant(j1->c->p[i]);
		j1->c->p[i]=NULL;
		printf("Poketudiant en indice %d relaché \n", i);
	}
}

void catch(Joueur * j1,int n)
{
	for(int i=0; i<n; i++)
		ajout_inv(j1, newPoketudiant_random(1,5));
}

void xp(Joueur * j1, int i , int n)
{
	Sac *s=j1->s;
	if(i>s->cur||i<0)
		printf(ERR_OVERFLOW,i);
	else 
	{
		gestionLevelUp(s->p[i],n);
		affichePoketudiant(s->p[i]);
	}
	
	
}


int isInt(char *s)
{
		char c;
		int i, len = strlen(s);
		int valid=1;
		
        for(i = 0; i < len; i++)
        {
            c = s[i];
 
            if ((c < '0') || (c > '9'))
            {
                valid = 0;
                break;
            }
        }
 
        return valid;
}

