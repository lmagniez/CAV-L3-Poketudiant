#include <stdlib.h>
#include <stdio.h>

#include "../lib/sac.h"


#define ERR_EMPTYBAG	"erreur, sac vide\n"
#define ERR_FULLBAG		"erreur, sac plein\n"
#define ERR_OVERFLOW	"erreur, l'indice %d ne correspond a aucun poketudiant dans l'equipe\n"
#define ERR_USED		"erreur, poketudiant en tete d'equipe\n"
#define ERR_ISTRAINER	"erreur, on ne peut supprimer l'enseignant dresseur\n"

//initialise avec l'enseignant dresseur
Sac * init_sac(int lvl){
	Sac * s=(Sac *)malloc(sizeof(Sac));
	s->cur=1;
	s->p1=0;
	
	for(int i=0;i<TAILLE_SAC;i++)
		s->p[i]=NULL;

	s->p[0]=new_poketudiant_type(ENSEIGNANT_DRESSEUR,lvl,lvl);
	
	return s;
}

Sac * init_sac_rival(int lvl_min,int lvl_max){
	Sac * s=(Sac *)malloc(sizeof(Sac));
	s->cur=3;
	
	s->p[0]=new_poketudiant_type(ENSEIGNANT_DRESSEUR,lvl_min,lvl_max);
	s->p[1]=new_poketudiant_random(lvl_min,lvl_max);
	s->p[2]=new_poketudiant_random(lvl_min,lvl_max);
	
	
	return s;
}

//ajoute un poketudiant dans le sac
void ajout_sac(Sac * s,Poketudiant * p){
	if(sac_plein(s))
	{
		printf(ERR_FULLBAG);
		exit(1);
	}
	
	s->p[s->cur]=p;
	s->cur++;
}



//inverse les positions de deux poketudiant dans le tab
void switch_sac(Sac * s,int i,int j)
{
	Poketudiant tmp;
	tmp=*(s->p[i]);
	*(s->p[i])=*(s->p[j]);
	*(s->p[j])=tmp;
	
}

//renvoie si le sac est remplis 
int sac_plein(Sac * sac){
	return (sac->cur==TAILLE_SAC);
}

void affiche_sac(Sac * sac){
	printf("Sac : \n");
	char * nom;
	for(int i=0;i<sac->cur;i++){
		nom=chaine_variete(sac->p[i]->poke.nom);
		printf("  %d Name: %s LVL: %d Life : %d/%d \n",i,nom,sac->p[i]->lvl,sac->p[i]->pv_cur,sac->p[i]->stat_cur.pv_max_poke);
	}
	printf("\n");
}


int verif_vie(Sac * sac){
	for(int i=0;i<sac->cur;i++){
		if(sac->p[i]->pv_cur > 0)return 1;
	}
	return 0;
}

//change la valeur de p1 en combat
void changer_premier(Sac *s, int indice)
{
	
	if(indice>s->cur-1||indice<0)
	{
		printf(ERR_OVERFLOW,indice);
		exit(1);
	}
	s->p1=indice;
}

//recup le premier poketudiant (p1)
Poketudiant* recup_premier(Sac *s)
{
	return s->p[s->p1];
}

//supprime  poketudiant a l'indice i
//on ne peut pas supprimer l'enseignant dresseur (indice 0)
Poketudiant* supprimer_poke_sac(Sac * s,int i)
{	
	if(i==0){
		printf(ERR_ISTRAINER);
		exit(1);
	}
	
	if(i>s->cur-1||i<0){
		printf(ERR_OVERFLOW,i);
		exit(1);
	}
	
	if(s->p1==i)
	{
		printf(ERR_USED);
		exit(1);
	}
	
	Poketudiant *res=s->p[i];
	s->p[i]=NULL;
	//*res=*(s->p[i]);
	
	for(int j=i; j<s->cur; j++)
		s->p[j]=s->p[j+1];
	
	s->cur--;
	
	return res;
	
}

void free_sac(Sac *s)
{
	for(int i=0; i<TAILLE_SAC; i++)
	{
		if(s->p[i])
		{
			free_poketudiant(s->p[i]);
		}
	}
	
	free(s);
}
