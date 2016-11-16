#include <stdlib.h>
#include <stdio.h>

#include "../lib/sac.h"


#define ERR_EMPTYBAG	"erreur, sac vide\n"
#define ERR_FULLBAG		"erreur, sac plein\n"
#define ERR_OVERFLOW	"erreur, l'indice %d ne correspond a aucun poketudiant dans l'equipe\n"
#define ERR_USED		"erreur, poketudiant en tete d'equipe\n"
#define ERR_ISTRAINER	"erreur, on ne peut supprimer l'enseignant dresseur\n"

//initialise avec l'enseignant dresseur
Sac * initsac(int lvl){
	Sac * s=(Sac *)malloc(sizeof(Sac));
	s->cur=1;
	//for(int i=0;i<TAILLE_SAC;i++)
	//	s->p[i]=(Poketudiant *)malloc(sizeof(Poketudiant));
	
	
	printf("Poke au lvl: %d\n",lvl);
	
	s->p[0]=newPoketudiant_type(ENSEIGNANT_DRESSEUR,lvl,lvl);
	
	return s;
}

//ajoute un pokemon dans le sac
void ajout_sac(Sac * s,Poketudiant * p){
	if(sacPlein(s))
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
int sacPlein(Sac * sac){
	return (sac->cur==TAILLE_SAC);
}

void afficheSac(Sac * sac){
	printf("Sac : \n");
	char * nom;
	for(int i=0;i<sac->cur;i++){
		nom=chaineVariete(sac->p[i]->pokemon.nom);
		printf("  %d Name: %s LVL: %d Life : %d/%d \n",i,nom,sac->p[i]->lvl,sac->p[i]->pv_cur,sac->p[i]->stat_cur.pv_max_poke);
	}
	printf("\n");
}


int verifvie(Sac * sac){
	for(int i=0;i<sac->cur;i++){
		if(sac->p[i]->pv_cur > 0)return 1;
	}
	return 0;
}

//change la valeur de p1 en combat
void changerPrem(Sac *s, int indice)
{
	
	if(indice>s->cur-1||indice<0)
	{
		printf(ERR_OVERFLOW,indice);
		exit(1);
	}
	s->p1=indice;
}

//recup le premier poketudiant (p1)
Poketudiant* recupPremier(Sac *s)
{
	return s->p[s->p1];
}

//supprime  poketudiant a l'indice i
//on ne peut pas supprimer l'enseignant dresseur (indice 0)
Poketudiant* supprimerPoke_sac(Sac * s,int i)
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


