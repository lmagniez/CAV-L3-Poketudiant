#include <stdlib.h>
#include <stdio.h>

#include "../lib/sac.h"

#define ERR_OVERFLOW	"erreur, l'indice %d ne correspond a aucun poketudiant dans l'equipe\n"
#define ERR_EMPTYBAG	"erreur, sac vide\n"
#define ERR_FULLBAG		"erreur, sac plein\n"
#define ERR_USED		"erreur, poketudiant en tete d'equipe\n"


Sac initsac(){
	Sac s;
	s.cur=0;
	s.p1=0;
	for(int i=0;i<TAILLE_SAC;i++)
		s.p[i]=(Poketudiant *)malloc(sizeof(Poketudiant));
	return s;
}

//ajoute un pokemon dans le sac
void ajout_sac(Sac * s,Poketudiant * p){
	
	if(remplisSac(*s))
	{
		printf(ERR_FULLBAG);
		exit(1);
	}
	
	*(s->p[s->cur])=*p;
	s->cur++;
}

//change la valeur de p1 en combat
void changerPrem(Sac * s, int indice)
{
	if(indice>s->cur-1)
	{
		printf(ERR_OVERFLOW,indice);
		exit(1);
	}
	
	s->p1=indice;
	
}

//recup le premier poketudiant (p1)
Poketudiant* recupPremier(Sac * s)
{
	if(s->cur==0)
	{
		printf(ERR_EMPTYBAG);
		exit(1);
	}
	return s->p[s->p1];
}

//supprime  poketudiant a l'indice i
//on ne peut pas avoir un sac vide
Poketudiant* supprimerPoke_sac(Sac * s,int i)
{
	if(i>s->cur-1){
		printf(ERR_OVERFLOW,i);
		exit(1);
	}
	
	if(s->p1!=i)
	{
		printf(ERR_USED);
		exit(1);
	}
	
	Poketudiant *res=(Poketudiant*)malloc(sizeof(Poketudiant));
	*res=*(s->p[i]);
	
	for(int j=i; j<s->cur; j++)
		s->p[j]=s->p[j+1];
	
	s->cur--;
	
	return res;
	
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
int remplisSac(Sac sac){
	return (sac.cur==TAILLE_SAC);
}
