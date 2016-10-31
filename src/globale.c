#include <stdlib.h>
#include <stdio.h>

#include <time.h>
#include "../lib/globale.h"

int myrand(int a,int b){
	return rand()%((b+1)-a)+a;
}

