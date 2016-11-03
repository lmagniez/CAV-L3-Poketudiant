#include <stdlib.h>
#include <stdio.h>

#include "../lib/type.h"

static char * tabc_string_type[]={"NOISY","LAZY","MOTIVATED","TEACHER"};

char * chaineType(type t){
	return tabc_string_type[t];
}


int comparaisontype(type t1,type t2){
	return (t1==t2);
}

//retourne 2 pour doubler l'attaque
int faiblesse(type t1,type t2){
	if(t1==NOISY && t2==LAZY)
		return 2;
	if(t1==LAZY && t2==MOTIVATED)
		return 2;
	if(t1==MOTIVATED && t2==NOISY)
		return 2;
	if(t1==TEACHER && (t2==NOISY || t2==LAZY))
		return 2;
	return 1;
}
