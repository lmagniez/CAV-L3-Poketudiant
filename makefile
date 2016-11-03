BINDIR=bin/
SRCDIR=src/

OBJET=$(BINDIR)main.o $(BINDIR)poketudiant.o $(BINDIR)poke.o $(BINDIR)attaque.o $(BINDIR)type.o $(BINDIR)variete.o $(BINDIR)inventaire.o $(BINDIR)cafetariat.o $(BINDIR)sac.o $(BINDIR)globale.o $(BINDIR)statistique.o $(BINDIR)combat.o $(BINDIR)joueur.o
CC=gcc
CFLAGS=-Wall -g

jeux : $(OBJET)
	@$(CC) -o jeux  $(BINDIR)*.o
	
$(BINDIR)main.o: $(SRCDIR)*.c
	@$(CC) $(CFLAGS) -c  -o $@ $(SRCDIR)main.c 	
	
$(BINDIR)poketudiant.o : $(SRCDIR)poketudiant.c $(SRCDIR)poke.c $(SRCDIR)attaque.c $(SRCDIR)globale.c
	@$(CC) $(CFLAGS) -c  -o $@ $(SRCDIR)poketudiant.c
	
$(BINDIR)attaque.o : $(SRCDIR)attaque.c $(SRCDIR)type.c $(SRCDIR)globale.c
	@$(CC) $(CFLAGS) -c  -o $@ $(SRCDIR)attaque.c

$(BINDIR)poke.o : $(SRCDIR)poke.c $(SRCDIR)type.c $(SRCDIR)variete.c $(SRCDIR)statistique.c
	@$(CC) $(CFLAGS) -c  -o $@ $(SRCDIR)poke.c

$(BINDIR)joueur.o : $(SRCDIR)joueur.c $(SRCDIR)poketudiant.c $(SRCDIR)inventaire.c
	@$(CC) $(CFLAGS) -c  -o $@ $(SRCDIR)joueur.c 
	
$(BINDIR)type.o : $(SRCDIR)type.c
	@$(CC) $(CFLAGS) -c  -o $@ $(SRCDIR)type.c 

$(BINDIR)variete.o : $(SRCDIR)variete.c
	@$(CC) $(CFLAGS) -c  -o $@ $(SRCDIR)variete.c 
	
$(BINDIR)inventaire.o : $(SRCDIR)inventaire.c $(SRCDIR)sac.c $(SRCDIR)cafetariat.c
	@$(CC) $(CFLAGS) -c  -o $@ $(SRCDIR)inventaire.c 

$(BINDIR)cafetariat.o : $(SRCDIR)cafetariat.c $(SRCDIR)poketudiant.c
	@$(CC) $(CFLAGS) -c  -o $@ $(SRCDIR)cafetariat.c 

$(BINDIR)sac.o : $(SRCDIR)sac.c $(SRCDIR)poketudiant.c
	@$(CC) $(CFLAGS) -c  -o $@ $(SRCDIR)sac.c 

$(BINDIR)globale.o : $(SRCDIR)globale.c 
	@$(CC) $(CFLAGS) -c  -o $@ $(SRCDIR)globale.c 
	
$(BINDIR)statistique.o: $(SRCDIR)statistique.c
	@$(CC) $(CFLAGS) -c  -o $@ $(SRCDIR)statistique.c

$(BINDIR)combat.o: $(SRCDIR)combat.c
	@$(CC) $(CFLAGS) -c  -o $@ $(SRCDIR)combat.c 

clean:
	@rm -rf $(BINDIR)*.o 
	@echo "Cleaning done :)"
