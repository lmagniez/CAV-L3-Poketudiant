#include <stdlib.h>
#include <stdio.h>

#include "poketudiant.h"

static char *tabc_string[]={"PARFLOR","ISMAR","RIGOLAMOR","PROCRASTINO","COUCHTAR",
							"NUIDEBOU","BUCHAFON","BELMENTION","PROMOMAJOR",
							"ENSEIGNANT_DRESSEUR","NO_EVOLUTION"};

char * stringVariete(variete ele){
	return tabc_string[ele];
}
	

Poketudiant tab_variete[NB_VARIETE]={
	{PARFLOR,NOISY,1,1,NO_EVOLUTION,{0,0,0},{60,40,60},0},
	{ISMAR,NOISY,1,1,RIGOLAMOR,{0,0,0},{50,30,40},0},
	{RIGOLAMOR,NOISY,1,0,NO_EVOLUTION,{0,0,0},{85,55,70},0},
	{PROCRASTINO,LAZY,1,1,NO_EVOLUTION,{0,0,0},{40,60,60},0},
	{COUCHTAR,LAZY,1,1,NUIDEBOU,{0,0,0},{30,50,40},0},
	{NUIDEBOU,LAZY,1,0,NO_EVOLUTION,{0,0,0},{55,85,70},0},
	{BUCHAFON,MOTIVATED,1,1,NO_EVOLUTION,{0,0,0},{50,50,60},0},
	{BELMENTION,MOTIVATED,1,1,PROMOMAJOR,{0,0,0},{30,50,40},0},
	{PROMOMAJOR,MOTIVATED,1,0,NO_EVOLUTION,{0,0,0},{70,70,70},0},
	{ENSEIGNANT_DRESSEUR,TEACHER,1,1,NO_EVOLUTION,{0,0,0},{100,100,100},0}
};

Poketudiant newPoketudiant(variete v,int lvl){
	Poketudiant new=tab_variete[v];
	
	new.lvl=lvl;
	
	
	
	return new;
}

int main(){
	newPoketudiant(PARFLOR,5);
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
