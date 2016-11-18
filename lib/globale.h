#ifndef _GLOBALE_H
#define _GLOBALE_H

#define POURCENT_MINI 0
#define POURCENT_MAXI 100

#ifndef max
	#define max(a,b) ( ((a) > (b)) ? (a) : (b) )
#endif

int my_rand(int a,int b);

void vider_buffer();
 
int lire(char *chaine, int longueur);

int lecture_entree();
#endif
