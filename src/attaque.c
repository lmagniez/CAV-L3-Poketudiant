#include <stdlib.h>
#include <stdio.h>

#include "../lib/globale.h"
#include "../lib/attaque.h"

attaque tab_attaque[NB_ATTACK]={
	{"BAVARDAGE",NOISY,10},
	{"GROBOUCAN",NOISY,15},
	{"MEGAPHONE-VOCAL",NOISY,20},
	{"BAILLEMENT",LAZY,10},
	{"PTI'SOMME",LAZY,15},
	{"SUPERDODO",LAZY,20},
	{"OBOULO",MOTIVATED,10},
	{"EXO-MAISON",MOTIVATED,15},
	{"MAX-REVIZ",MOTIVATED,20},
	{"TIT'QUESTION",TEACHER,10},
	{"POSER-COLLE",TEACHER,15},
	{"FATAL-INTERRO",TEACHER,20}
};

//retourne un tab de 2 attaque pour le pokemon
attaque * recupAttaque(type t){
	attaque * tab=(attaque *)malloc(N_ATTACK*sizeof(attaque));
	attaque tmp;
	int indice;
	
	//première attaque
	indice=myrand(0,NB_ATTACK-1);
	tmp=tab_attaque[indice];
	while(!comparaisontype(tmp.t,t)){
		indice=myrand(0,NB_ATTACK-1);
		tmp=tab_attaque[indice];
	}
	tab[0]=tmp;
		
	//autres attaques (une seule a priori)
	for(int i=1;i<N_ATTACK;i++){
		indice=myrand(0,NB_ATTACK-1);
		tmp=tab_attaque[indice];
		while(comparaisontype(tmp.t,t)){
			indice=myrand(0,NB_ATTACK-1);
			tmp=tab_attaque[indice];
		}
		tab[i]=tmp;
	}
	return tab;
} 

//renvoie les dommages d'une attaque 
int domageattaque(float k,int att_attack,int def_defender,int power){
	float res=(k*(att_attack*1.0/def_defender)*power);
	return (int)res;
}
