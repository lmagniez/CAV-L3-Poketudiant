#include <stdlib.h>
#include <stdio.h>

#include "../lib/type.h"

int comparaisontype(type t1,type t2){
	return (t1==t2);
}

int faiblesse(type t1,type t2){
	if(t1==NOISY && t2==LAZY)
		return 1;
	if(t1==LAZY && t2==MOTIVATED)
		return 1;
	if(t1==MOTIVATED && t2==NOISY)
		return 1;
	if(t1==TEACHER && (t2==NOISY || t2==LAZY))
		return 1;
	return 0;
}
