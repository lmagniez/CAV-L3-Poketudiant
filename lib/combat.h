#ifndef _COMBAT_H
#define _COMBAT_H

#define FUITE 1
#define CAPTURE 2
#define CHANG_POKE 3

int combat_rival(Joueur *j,Joueur *rival);

void combat_sauvage(Joueur *j, Poketudiant * p2);

int tour_joueur(Joueur * j, Poketudiant * p2,int combat);

int choix_joueur(Joueur * j, Poketudiant * p2,int combat);

int tour_ordi(Joueur * j, Poketudiant * p2);

void changer_poke_ordi(Joueur * rival);

int changer_poke_combat(Joueur * j, int annulable);

void calcul_xp(Joueur *j, int tabexp[TAILLE_SAC],int xp_total);

//revoie 1 si on peut s'enfuir 
int fuite(int lvl_poke, int lvl_enemy);

int proba_capture(int pv_eff , int pv_max);

void affichage_combat(Poketudiant * p1, Poketudiant * p2);

void affichage_tour(Poketudiant * p,attaque a, int enemy, int faiblesse, int dommage);

#endif
