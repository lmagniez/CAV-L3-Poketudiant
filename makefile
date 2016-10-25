BINDIR=bin/
SRCDIR=src/

OBJET=$(BINDIR)main.o $(BINDIR)poketudiant.o $(BINDIR)poke.o $(BINDIR)attaque.o $(BINDIR)type.o $(BINDIR)variete.o 
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
	
$(BINDIR)type.o : $(SRCDIR)type.c $(SRCDIR)type.h
	@$(CC) $(CFLAGS) -c  -o $@ $(SRCDIR)type.c 

$(BINDIR)variete.o : $(SRCDIR)variete.c $(SRCDIR)variete.h
	@$(CC) $(CFLAGS) -c  -o $@ $(SRCDIR)variete.c 
	
clean:
	@rm -rf $(BINDIR)*.o 
	@echo "Cleaning done :)"


