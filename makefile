BINDIR=bin/
SRCDIR=src/

OBJET=$(BINDIR)main.o $(BINDIR)poketudiant.o $(BINDIR)poke.o $(BINDIR)attaque.o $(BINDIR)type.o $(BINDIR)variete.o $(BINDIR)inventaire.o $(BINDIR)cafetaria.o $(BINDIR)sac.o 
CC=gcc
CFLAGS=-Wall -g

jeux : $(OBJET)
	@$(CC) -o jeux  $(BINDIR)*.o
	
$(BINDIR)main.o: $(SRCDIR)*.c
	@$(CC) $(CFLAGS) -c  -o $@ $(SRCDIR)main.c 	
	
$(BINDIR)poketudiant.o : $(SRCDIR)poketudiant.c $(SRCDIR)poke.c $(SRCDIR)attaque.c
	@$(CC) $(CFLAGS) -c  -o $@ $(SRCDIR)poketudiant.c
	
$(BINDIR)attaque.o : $(SRCDIR)attaque.c $(SRCDIR)type.c
	@$(CC) $(CFLAGS) -c  -o $@ $(SRCDIR)attaque.c

$(BINDIR)poke.o : $(SRCDIR)poke.c $(SRCDIR)type.c $(SRCDIR)variete.c
	@$(CC) $(CFLAGS) -c  -o $@ $(SRCDIR)poke.c 
	
$(BINDIR)type.o : $(SRCDIR)type.c
	@$(CC) $(CFLAGS) -c  -o $@ $(SRCDIR)type.c 

$(BINDIR)variete.o : $(SRCDIR)variete.c
	@$(CC) $(CFLAGS) -c  -o $@ $(SRCDIR)variete.c 
	
	
$(BINDIR)inventaire.o : $(SRCDIR)inventaire.c $(SRCDIR)sac.c $(SRCDIR)cafetaria.c
	@$(CC) $(CFLAGS) -c  -o $@ $(SRCDIR)inventaire.c 

$(BINDIR)cafetaria.o : $(SRCDIR)cafetaria.c $(SRCDIR)poketudiant.c
	@$(CC) $(CFLAGS) -c  -o $@ $(SRCDIR)cafetaria.c 

$(BINDIR)sac.o : $(SRCDIR)sac.c $(SRCDIR)poketudiant.c
	@$(CC) $(CFLAGS) -c  -o $@ $(SRCDIR)sac.c 
	
clean:
	@rm -rf $(BINDIR)*.o 
	@echo "Cleaning done :)"


