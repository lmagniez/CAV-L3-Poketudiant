#include <stdlib.h>
#include <stdio.h>
#include <time.h>


#include "../lib/poketudiant.h"

int main(){
	Poketudiant * tmp=newPoketudiant_random(1,3);
	affichePoketudiant(tmp);
	
	freePoketudiant(tmp);
	
	return 0;
}
