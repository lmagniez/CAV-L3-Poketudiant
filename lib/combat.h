#ifndef _COMBAT_H
#define _COMBAT_H

#define FUITE 1
#define CAPTURE 2
#define CHANG_POKE 3

void combatRival(Joueur *j,Joueur *rival);

void combatSauvage(Joueur *j, Poketudiant * p2);

int tourjoueur(Joueur * j, Poketudiant * p2,int combat);

int choixJoueur(Joueur * j, Poketudiant * p2,int combat);

int tourordi(Joueur * j, Poketudiant * p2);

void changerPokeOrdi(Joueur * rival);

int changementPcombat(Joueur * j, int annulable);

void calculxp(Joueur *j, int tabexp[TAILLE_SAC],int xp_total);

//revoie 1 si on peut s'enfuir 
int fuite(int lvl_poke, int lvl_enemy);

int probaCapture(int pv_eff , int pv_max);

void affichagecombat(Poketudiant * p1, Poketudiant * p2);

void affichageTour(Poketudiant * p,attaque a, int enemy, int faiblesse, int dommage);

void affichageentetour(Poketudiant * p1, Poketudiant * p2);

#endif
