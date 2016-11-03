#ifndef _COMBAT_H
#define _COMBAT_H

void combatRival(Poketudiant * p1, Poketudiant * p2);

void combatSauvage(Poketudiant * p1, Poketudiant * p2);

int tourjoueur(Poketudiant * p1, Poketudiant * p2);

int choixJoueur(Poketudiant * p1, Poketudiant * p2);

int tourordi(Poketudiant * p1, Poketudiant * p2);

//revoie 1 si on peut s'enfuir 
int fuite(int lvl_poke, int lvl_enemy);

int probaCapture(int pv_eff , int pv_max);

void affichagecombat(Poketudiant * p1, Poketudiant * p2);

void affichageTour(Poketudiant * p,attaque a);

void affichageentetour(Poketudiant * p1, Poketudiant * p2);

#endif
