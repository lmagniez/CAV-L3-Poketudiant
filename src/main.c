#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "../lib/joueur.h"
#include "../lib/combat.h"
#include "../lib/commande.h"

int main(){
	
	srand(time(NULL));//debut de code pour la bonne generation aleatoire
	
	Poketudiant * tmp1=newPoketudiant_random(1,5);
	Poketudiant * tmp2=newPoketudiant_type(PROCRASTINO,1,5);

	Poketudiant * tmp3=newPoketudiant_random(1,5);
	
	Joueur j=initJoueur();
	printf("ok\n");
	
	ajout_sac(j.inv.s,tmp1);
	//ajout_sac(j.inv.s,tmp2);


	//combatSauvage(&j,tmp3);
	
	
	printf("ok\n");
	
	show_team(j);
	//show_cafet(j);
	
	
	ajout_cafe(j.inv.c,tmp2);
	//ajout_cafe(j.inv.c,tmp3);
	
	ajout_cafe_id(j.inv.c,tmp3,2);
	
	show_cafet(j);
	
	//pick(&j,3);
	pick(&j,8);
	pick(&j,0);
	
	show_cafet(j);
	show_team(j);
	
	move_table(&j,2,1);
	move_table(&j,0,1);
	move_table(&j,2,0);
	move_table(&j,1,0);
	move_table(&j,1,1);
	
	move_table(&j,3,1);
	
	
	show_cafet(j);
	show_team(j);
	
	
	//xp(&j,1,1250);
	
	//show_indice(j,1);
	
	//xp(&j,4,50);
	
	for(int i=1; i<10; i++)
	{
		printf("%d ",xp_next(i));
	}
	

	return 0;
}
