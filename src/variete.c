
#include "../lib/variete.h"

static char * tabc_string_var[]={"PARLFOR","ISMAR","RIGOLAMOR","PROCRASTINO","COUCHTAR",
							"NUIDEBOU","BUCHAFON","BELMENTION","PROMOMAJOR",
							"ENSEIGNANT_DRESSEUR","NO_EVOLUTION"};

char * chaine_variete(variete ele){
	return tabc_string_var[ele];
}
