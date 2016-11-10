#include <stdlib.h>
#include <stdio.h>

#include <time.h>
#include "../lib/globale.h"

int myrand(int a,int b){
	//srand ( time(NULL) );
	return rand()%(b-a)+a;
}

