#include "../lib/statistique.h"


statistique calcul_stat(float * coef,statistique b){
	statistique newS;
	newS.att=b.att*coef[0];
	newS.defense=b.defense*coef[1];
	newS.pv_max_poke=b.pv_max_poke*coef[2];
	return newS;
}
