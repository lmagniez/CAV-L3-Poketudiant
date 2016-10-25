#include <stdlib.h>
#include <stdio.h>

#include "poke.h"

char *tabc_string[]={"PARFLOR","ISMAR","RIGOLAMOR","PROCRASTINO","COUCHTAR",
							"NUIDEBOU","BUCHAFON","BELMENTION","PROMOMAJOR",
							"ENSEIGNANT_DRESSEUR","NO_EVOLUTION"};

char * stringVariete(variete ele){
	return tabc_string[ele];
}
	

Poke tab_variete[NB_VARIETE]={
	{PARFLOR,NOISY,1,NO_EVOLUTION,{60,40,60}},
	{ISMAR,NOISY,1,RIGOLAMOR,{50,30,40}},
	{RIGOLAMOR,NOISY,1,NO_EVOLUTION,{85,55,70}},
	{PROCRASTINO,LAZY,1,NO_EVOLUTION,{40,60,60}},
	{COUCHTAR,LAZY,1,NUIDEBOU,{30,50,40}},
	{NUIDEBOU,LAZY,1,NO_EVOLUTION,{55,85,70}},
	{BUCHAFON,MOTIVATED,1,NO_EVOLUTION,{50,50,60}},
	{BELMENTION,MOTIVATED,1,PROMOMAJOR,{30,50,40}},
	{PROMOMAJOR,MOTIVATED,1,NO_EVOLUTION,{70,70,70}},
	{ENSEIGNANT_DRESSEUR,TEACHER,1,NO_EVOLUTION,{100,100,100}}
};

Poke newPoke(variete v){
	Poke new=tab_variete[v];
	return new;
}

/*
 	variete nom;
	type spe;
	
	int capturable;
	
	variete evolution;
	
	statistique stat_courante;
	statistique stat_base;

	int experience;
	* */
