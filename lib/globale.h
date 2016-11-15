#ifndef _GLOBALE_H
#define _GLOBALE_H

#define POURCENT_MINI 0
#define POURCENT_MAXI 100

#ifndef max
	#define max(a,b) ( ((a) > (b)) ? (a) : (b) )
#endif

int myrand(int a,int b);

void viderBuffer();
 
int lire(char *chaine, int longueur);

int lectureEntree();
#endif
