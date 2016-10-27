#include <stdlib.h>
#include <stdio.h>
#include <time.h>

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

attaque * recupAttaque(type t){
	return NULL;
}

int domageattaque(int k,int att_attack,int def_defender,int power){
	return k*(att_attack/def_defender)*power;
}
