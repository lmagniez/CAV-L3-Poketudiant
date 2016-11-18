#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../lib/globale.h"

int my_rand(int a,int b){
	return rand()%(b+1-a)+a;
}

void vider_buffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}
 
int lire(char *chaine, int longueur)
{
    char *positionEntree = NULL;
 
    if (fgets(chaine, longueur, stdin) != NULL)
    {
        positionEntree = strchr(chaine, '\n');
        if (positionEntree != NULL)
        {
            *positionEntree = '\0';
        }
        else
        {
            vider_buffer();
        }
        return 1;
    }
    else
    {
        vider_buffer();
        return 0;
    }
}

int lecture_entree(){
	char nombreTexte[100] = {0};

	if (lire(nombreTexte, 100))
    {
        // Si lecture du texte ok, convertir le nombre en long et le retourner
        return strtol(nombreTexte, NULL, 10);
    }
    else
    {
        // Si problème de lecture, renvoyer 0
        return 0;
    }
}

