#ifndef _COMBAT_H
#define _COMBAT_H

void combatRival(Poketudiant * p1, Poketudiant * p2);

void combatSauvage(Joueur j, Poketudiant * p2);

int tourjoueur(Joueur * j, Poketudiant * p2);

int choixJoueur(Joueur * j, Poketudiant * p2);

int tourordi(Joueur * j, Poketudiant * p2);

void changemntPcombat(Joueur * j);

//revoie 1 si on peut s'enfuir 
int fuite(int lvl_poke, int lvl_enemy);

int probaCapture(int pv_eff , int pv_max);

void affichagecombat(Poketudiant * p1, Poketudiant * p2);

void affichageTour(Poketudiant * p,attaque a);

void affichageentetour(Poketudiant * p1, Poketudiant * p2);

#endif
