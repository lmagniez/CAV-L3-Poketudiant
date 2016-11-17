#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "../lib/joueur.h"
#include "../lib/combat.h"
#include "../lib/commande.h"
#include "../lib/parsecommande.h"

int main(){
	
	Poketudiant * tmp1=newPoketudiant_random(1,5);
	Poketudiant * tmp2=newPoketudiant_type(PROCRASTINO,1,5);

	Poketudiant * tmp3=newPoketudiant_random(1,5);
	
	Joueur j=initJoueur(5);
	Joueur j2=initJoueur(2);
	printf("ok\n");
	
	ajout_sac(j.inv.s,tmp1);


	while(1){
		lirecommande(&j);
	}

	srand(time(NULL));//debut de code pour la bonne generation aleatoire
	
	
	catch(&j,5);
	catch(&j2,5);
	
	combatRival(&j,&j2);
	
	
	/*
	ajout_cafe(j.inv.c,newPoketudiant_random(1,5));
	ajout_cafe(j.inv.c,newPoketudiant_random(1,5));
	ajout_cafe(j.inv.c,newPoketudiant_random(1,5));
	ajout_cafe(j.inv.c,newPoketudiant_random(1,5));
	*/
	
	
	
	//ajout_sac(j.inv.s,tmp2);


	//combatSauvage(&j,tmp3);
	
	/*
	show_team(j);
	show_cafet(j);
	
	ajout_cafe(j.inv.c,tmp2);
	ajout_cafe(j.inv.c,tmp3);
	ajout_cafe_id(j.inv.c,tmp3,2);
	
	show_cafet(j);
	*/
	//pick(&j,3);
	
	/*
	pick(&j,8);//cafeteriat->equipe
	pick(&j,0);
	
	show_cafet(j);
	show_team(j);
	
	move_table(&j,2,1);
	move_table(&j,0,1);
	move_table(&j,2,0);
	move_table(&j,1,0);
	move_table(&j,1,1);
	
	move_table(&j,3,1);
	
	catch(&j,20);
	
	switchP(&j,5,17);
	release(&j,5);
	
	
	
	show_cafet(j);
	show_team(j);
	
	*/
	
	//xp(&j,1,1250);
	
	//show_indice(j,1);
	
	//xp(&j,4,50);

	return 0;
}
