
#include "../lib/variete.h"

static char * tabc_string_var[]={"PARFLOR","ISMAR","RIGOLAMOR","PROCRASTINO","COUCHTAR",
							"NUIDEBOU","BUCHAFON","BELMENTION","PROMOMAJOR",
							"ENSEIGNANT_DRESSEUR","NO_EVOLUTION"};

char * chaineVariete(variete ele){
	return tabc_string_var[ele];
}
