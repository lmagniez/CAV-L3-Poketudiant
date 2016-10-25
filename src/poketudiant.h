#define NB_VARIETE 10

typedef enum{
	PARFLOR,ISMAR,RIGOLAMOR,PROCRASTINO,COUCHTAR,NUIDEBOU,BUCHAFON,BELMENTION,PROMOMAJOR,ENSEIGNANT_DRESSEUR,NO_EVOLUTION
}variete;

typedef enum{
	NOISY,LAZY,MOTIVATED,TEACHER
}type;

typedef struct statistique{
	int attaque;
	int defense;
	int pv_max;
}statistique;

typedef struct Poketudiant{
	variete nom;
	type spe;
	
	int lvl;
	
	int capturable;
	
	variete evolution;
	
	statistique stat_courante;
	statistique stat_base;

	int experience;
	
}Poketudiant;

char * stringVariete(variete ele);
