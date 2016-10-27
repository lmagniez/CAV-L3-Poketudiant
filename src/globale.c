
#include "../lib/globale.h"

float myrand(int a,int b){
	srand(time(NULL));
	return rand()%(b-a);
}
