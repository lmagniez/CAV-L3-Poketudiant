#ifndef _POKETUDIANT_H
#define _POKETUDIANT_H

#include "poke.h"
//#include "inventaire.h"
#include "attaque.h"
#include "type.h"
#include "variete.h"


#define CONST_LEVEL 500
#define B_COEF_MIN 9
#define B_COEF_MAX 12
#define NB_COEF 3

typedef struct Poketudiant{
	Poke pokemon;
		
	float * coef;
	
	statistique stat_cur;
	
	attaque * base;

	int lvl;
		
	int pv_cur;

	
	int experience_cur;
	int experience_niveau_sup;
	
	//Inventaire inv;
}Poketudiant;


//creer un poketudiant entre 2 niveau
Poketudiant * newPoketudiant_random(int borne1, int borne2);

//creer un poketudiant entre en fonction du type
Poketudiant * newPoketudiant_type(type t);

//calcul l'exp pour le niveau suivant
int xp_next(int lvl);

//calcul la probabilite de capture
int probaCapture(int pv_eff , int pv_max);

//revoie 1 si on peut s'enfuir 
int fuite(int lvl_poke, int lvl_enemy);

void soigne_Poketudiant(Poketudiant * p);

//echange les poketudiants
void swap_poketudiant(Poketudiant * a , Poketudiant * b);

void affichePoketudiant(Poketudiant * p);

int calculexp(int lvl);
#endif
