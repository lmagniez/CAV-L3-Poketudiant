#ifndef _MAP_H
#define _MAP_H

#define FICHIER_MAP "./map/map1"
#define TAILLE_MAX_CHAINE 19
#define TAILLE_MAX_LIGNE 12

#define NB_RIVAL 3
#define NB_JOUEUR 1
#define NB_PERSO NB_RIVAL+NB_JOUEUR

#define NB_POSITION 2 

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

char map[TAILLE_MAX_CHAINE][TAILLE_MAX_CHAINE];
int position[NB_PERSO][NB_POSITION];
char save_char;

void initMap();

void gestionAction();

void afficheMap();
#endif
