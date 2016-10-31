#include <stdlib.h>
#include <stdio.h>

#include "../lib/poke.h"

Poke tab_variete[NB_VARIETE]={
	{PARFLOR,NOISY,1,NO_EVOLUTION,{60,40,60}},
	{ISMAR,NOISY,1,RIGOLAMOR,{50,30,40}},
	{RIGOLAMOR,NOISY,0,NO_EVOLUTION,{85,55,70}},
	{PROCRASTINO,LAZY,1,NO_EVOLUTION,{40,60,60}},
	{COUCHTAR,LAZY,1,NUIDEBOU,{30,50,40}},
	{NUIDEBOU,LAZY,0,NO_EVOLUTION,{55,85,70}},
	{BUCHAFON,MOTIVATED,1,NO_EVOLUTION,{50,50,60}},
	{BELMENTION,MOTIVATED,1,PROMOMAJOR,{30,50,40}},
	{PROMOMAJOR,MOTIVATED,0,NO_EVOLUTION,{70,70,70}},
	{ENSEIGNANT_DRESSEUR,TEACHER,0,NO_EVOLUTION,{100,100,100}}
};

Poke newPoke(variete v){
	Poke new=tab_variete[v];
	return new;
}

Poke newPokeRand(){
	int r=myrand(0,NB_VARIETE);
	Poke k = tab_variete[r];
	if(k.capturable==1)
		return k;
	return newPokeRand();
}
