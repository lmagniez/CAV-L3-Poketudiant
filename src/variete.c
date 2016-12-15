#include <string.h>
#include "../lib/variete.h"
#include "../lib/poke.h"

static char * tabc_string_var[]={"PARLFOR","ISMAR","RIGOLAMOR","PROCRASTINO","COUCHTAR",
							"NUIDEBOU","BUCHAFON","BELMENTION","PROMOMAJOR",
							"ENSEIGNANT_DRESSEUR","NO_EVOLUTION"};

char * chaine_variete(variete ele){

	return tabc_string_var[ele];
}

variete recup_variete(char * chaine){
	if(strcmp(chaine,"NO_EVOLUTION")==0)
		return -1;
	for(int i=0;i<NB_VARIETE;i++){
		if(strcmp(chaine,tabc_string_var[i])==0)
			return i;
	}

	return -1;
}
