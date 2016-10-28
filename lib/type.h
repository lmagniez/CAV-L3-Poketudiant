#ifndef _TYPE_H
#define _TYPE_H

typedef enum{
	NOISY,LAZY,MOTIVATED,TEACHER
}type;

char * stringType(type t);

//compare 2 types (generations attaques)
int comparaisontype(type t1,type t2);


//dit si tel type est une faiblesse de l'autre
int faiblesse(type t1,type t2);
#endif
