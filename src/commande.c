
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../lib/joueur.h"
#include "../lib/combat.h"
#include "../lib/commande.h"
#include "../lib/map.h"

#define ERR_OVERFLOW	"erreur, l'indice %d ne correspond a aucun poketudiant dans l'equipe\n"
#define ERR_COMMANDE	"Erreur Syntaxe Commande ! \n" 
#define ERR_COMMANDE_NB "Erreur syntaxe, veuillez entrer un entier\n"
#define ERR_POKE_ID 	"Il n'y a aucun poketudiant correspondant à l'id: %d\n"
#define ERR_POKE_LVL	"Un poketudiant ne peut pas dépasser le lvl 10! (et ne peut pas être en dessous de 0...)\n"
#define ERR_CAFE_ID 	"La Cafeteria ne dispose pas d'autant de places...\n"

void handle_wild(char ** arguments,Joueur *j1,int taille_arg){
	if(taille_arg!=2){printf(ERR_COMMANDE);return;}

	int buffer[2];
	for(int i=0;i<taille_arg;i++){
		buffer[i]=(int)strtol(arguments[i],NULL,10);
	}
	
	wild(j1,buffer[0],buffer[1]);
}

void handle_rival(char ** arguments,Joueur *j1,int taille_arg){
	if(taille_arg!=2){printf(ERR_COMMANDE);return;}

	int buffer[2];
	for(int i=0;i<taille_arg;i++){
		buffer[i]=(int)strtol(arguments[i],NULL,10);
	}
	
	rival(j1,buffer[0],buffer[1]);
}

void handle_nurse(char ** arguments,Joueur *j1,int taille_arg){
	if(taille_arg!=0){printf(ERR_COMMANDE);return;}
	
	nurse(j1);
}

void handle_show(char ** arguments,Joueur *j1,int taille_arg){
	int nb;

	if(taille_arg == 1 && strcmp(arguments[0],"pokecafeteria")==0){
		show_cafet(j1);
	}

	else if(taille_arg == 1 && strcmp(arguments[0],"team")==0){
		show_team(j1);
	}

	else if(taille_arg == 1 ){
		if(is_int(arguments[0])){	
			int nb=(int)strtol(arguments[0],NULL,10);
			show_indice(j1,nb);
		}
		else{
			printf(ERR_COMMANDE_NB);
		}
	}

	else if(taille_arg == 2 && strcmp(arguments[0],"revision-table")==0){
		if(is_int(arguments[1])){
			nb=(int)strtol(arguments[1],NULL,10);
			show_revision_table(j1,nb);
		}
		else{
			printf(ERR_COMMANDE_NB);
		}
	}

	else{printf(ERR_COMMANDE);return;}
}

void handle_switchP(char ** arguments,Joueur *j1,int taille_arg){
	if(taille_arg!=2){printf(ERR_COMMANDE);return;}

	int buffer[2];
	for(int i=0;i<taille_arg;i++){
		
		if(is_int(arguments[i])){
			buffer[i]=(int)strtol(arguments[i],NULL,10);
		}
		else{
			printf(ERR_COMMANDE_NB);
			return;
		}
	}
	
	switchP(j1,buffer[0],buffer[1]);
}

void handle_move_table(char ** arguments,Joueur *j1,int taille_arg){
	if(taille_arg!=2){printf(ERR_COMMANDE);return;}

	int buffer[2];
	for(int i=0;i<taille_arg;i++){
		if(is_int(arguments[i])){
			buffer[i]=(int)strtol(arguments[i],NULL,10);
		}
		else{
			printf(ERR_COMMANDE_NB);
			return;
		}
	}
	
	move_table(j1,buffer[0],buffer[1]);

}

void handle_drop(char ** arguments,Joueur *j1,int taille_arg){
	if(taille_arg!=1){printf(ERR_COMMANDE);return;}

	int id;
	for(int i=0;i<taille_arg;i++){
		if(is_int(arguments[i]))
			id=(int)strtol(arguments[i],NULL,10);
		else{
			printf(ERR_COMMANDE_NB);
			return;
		}	
	}
	
	drop(j1,id);
}

void handle_pick(char ** arguments,Joueur *j1,int taille_arg){
	if(taille_arg!=1){printf(ERR_COMMANDE);return;}

	int id;
	for(int i=0;i<taille_arg;i++){
		if(is_int(arguments[i]))
			id=(int)strtol(arguments[i],NULL,10);
		else{
			printf(ERR_COMMANDE_NB);
			return;
		}	
	}
	
	pick(j1,id);
}

void handle_release(char ** arguments,Joueur *j1,int taille_arg){
	if(taille_arg!=1){printf(ERR_COMMANDE);return;}

	int id;
	for(int i=0;i<taille_arg;i++){
		if(is_int(arguments[i]))
			id=(int)strtol(arguments[i],NULL,10);
		else{
			printf(ERR_COMMANDE_NB);
			return;
		}	
	}

	release(j1,id);
}

void handle_catch(char ** arguments,Joueur *j1,int taille_arg){
	if(taille_arg!=1){printf(ERR_COMMANDE);return;}

	int id;
	for(int i=0;i<taille_arg;i++){
		if(is_int(arguments[i]))
			id=(int)strtol(arguments[i],NULL,10);
		else{
			printf(ERR_COMMANDE_NB);
			return;
		}	
	}

	catch(j1,id);
}

void handle_xp(char ** arguments,Joueur *j1,int taille_arg){
	if(taille_arg!=2){printf(ERR_COMMANDE);return;}

	int buffer[2];
	for(int i=0;i<taille_arg;i++){
		if(is_int(arguments[i])){
			buffer[i]=(int)strtol(arguments[i],NULL,10);
		}
		else{
			printf(ERR_COMMANDE_NB);
			return;
		}
	}
	
	xp(j1,buffer[0],buffer[1]);
}

//#################################
//#################################
//#################################
//#################################

void handle_up(char ** arguments,Joueur *j1,int taille_arg){
	if(taille_arg!=0){printf(ERR_COMMANDE);return;}
	if(position[0][1]==0){printf("Deplacement Impossible\n");return;}
	if(position[0][1]== (TAILLE_MAX_LIGNE-1) ) {
		save_char=map[position[0][1]-1][position[0][0]]; // on sauvegarde la case d'avant
		map[position[0][1]][position[0][0]]=save_char;
		position[0][1]=position[0][1]-1;
		map[position[0][1]][position[0][0]]='S';
	}
	else{
		map[position[0][1]][position[0][0]]=save_char;
		position[0][1]=position[0][1]-1;
		save_char=map[position[0][1]][position[0][0]];
		map[position[0][1]][position[0][0]]='S';
	}
	gestionAction(j1);
}

void handle_bot(char ** arguments,Joueur *j1,int taille_arg){
	if(taille_arg!=0){printf(ERR_COMMANDE);return;}
	if(position[0][1]==TAILLE_MAX_LIGNE-1){printf("Deplacement Impossible\n");return;}

	map[position[0][1]][position[0][0]]=save_char;
	position[0][1]=position[0][1]+1;
	save_char=map[position[0][1]][position[0][0]];
	map[position[0][1]][position[0][0]]='S';

	gestionAction(j1);
}

void handle_right(char ** arguments,Joueur *j1,int taille_arg){
	if(taille_arg!=0){printf(ERR_COMMANDE);return;}
	if(position[0][0]==TAILLE_MAX_CHAINE-1){printf("Deplacement Impossible\n");return;}
	if(position[0][0]== 0) {
		save_char=map[position[0][1]][position[0][0]+1]; // on sauvegarde la case d'avant
		map[position[0][1]][position[0][0]]=save_char;
		position[0][0]=position[0][0]+1;
		map[position[0][1]][position[0][0]]='S';
	}
	else{
		if(!save_char)save_char='X';
		map[position[0][1]][position[0][0]]=save_char;
		position[0][0]=position[0][0]+1;
		save_char=map[position[0][1]][position[0][0]];
		map[position[0][1]][position[0][0]]='S';
	}
	gestionAction(j1);
}

void handle_left(char ** arguments,Joueur *j1,int taille_arg){
	if(taille_arg!=0){printf(ERR_COMMANDE);return;}
	if(position[0][0]==0){printf("Deplacement Impossible\n");return;}
	if(position[0][0]==TAILLE_MAX_CHAINE-1) {
		save_char=map[position[0][1]][position[0][0]-1]; // on sauvegarde la case d'avant
		map[position[0][1]][position[0][0]]=save_char;
		position[0][0]=position[0][0]-1;
		map[position[0][1]][position[0][0]]='S';
	}
	else{
		if(!save_char)save_char='X';
		map[position[0][1]][position[0][0]]=save_char;
		position[0][0]=position[0][0]-1;
		save_char=map[position[0][1]][position[0][0]];
		map[position[0][1]][position[0][0]]='S';
	}
	gestionAction(j1);
}

//#################################
//#################################
//#################################
//#################################

void wild(Joueur * j1, int niv_min, int niv_max)
{
	
	if(niv_min<0||niv_max>10)
	{
		printf(ERR_POKE_LVL);
		return;
	}
	printf("Wild : %i %i\n",niv_min,niv_max);
	
	Poketudiant * tmp=new_poketudiant_random(niv_min,niv_max);
	combat_sauvage(j1,tmp);
}

void rival(Joueur * j1, int niv_min, int niv_max)
{
	if(niv_min<0||niv_max>10)
	{
		printf(ERR_POKE_LVL);
		return;
	}
	
	Joueur j= init_rival(niv_min,niv_max);
	combat_rival(j1,&j);
	free_joueur(j);
}

void nurse(Joueur * j1)
{
	Sac *s= j1->s;
	Cafetariat* c= j1->c;
	for(int i=0; i<s->cur; i++)
		s->p[i]->pv_cur=s->p[i]->stat_cur.pv_max_poke;
	
	for(int i=0;i<NB_TABLE;i++){
		if(c->p[i]!=NULL){
 			c->p[i]->pv_cur=c->p[i]->stat_cur.pv_max_poke;
		}
	}
	
}

void show_team(Joueur * j1)
{
	Sac *s = j1->s;
	for(int i=0; i<s->cur; i++)
		affiche_poketudiant(s->p[i]);
	
}

void show_cafet(Joueur * j1)
{
	show_cafetaria(j1->c);
}

void show_revision_table(Joueur * j1, int table)
{
	show_revision(j1->c,table);
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
			affiche_poketudiant(s->p[i]);
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
				affiche_poketudiant(c->p[i]);
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
	if(i<0||i>NB_TOTAL-1){
		printf(ERR_CAFE_ID);
		return;
	}
	
	if(j1->c->p[i])
	{
		free_poketudiant(j1->c->p[i]);
		j1->c->p[i]=NULL;
		printf("Poketudiant en indice %d relaché \n", i);
	}
}

void catch(Joueur * j1,int n)
{
	for(int i=0; i<n; i++)
		ajout_inv(j1, new_poketudiant_random(1,5));
}

void xp(Joueur * j1, int i , int n)
{
	
	Poketudiant *p=get_by_id(j1,i);
	if(p==NULL)
		printf("Aucun Poketudiant correspondant a l'id %d\n", i);
	else{
		gestion_lvl_up(p,n);
		affiche_poketudiant(p);
	}
	
}


int is_int(char *s)
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

