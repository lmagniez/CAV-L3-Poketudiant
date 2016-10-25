BINDIR=bin/
SRCDIR=src/

CC=gcc
CFLAGS=-Wall -g

jeux : poketudiant.o poke.o main.o
	@$(CC) -o jeux  $(BINDIR)*.o
	
main.o: $(SRCDIR)*.c $(SRCDIR)*.h
	@$(CC) $(CFLAGS) -c  -o $(BINDIR)$@ $(SRCDIR)main.c 	
	
poketudiant.o : $(SRCDIR)poketudiant.c $(SRCDIR)poketudiant.h
	@$(CC) $(CFLAGS) -c  -o $(BINDIR)$@ $(SRCDIR)poketudiant.c 	

poke.o : $(SRCDIR)poke.c $(SRCDIR)poke.h 
	@$(CC) $(CFLAGS) -c  -o $(BINDIR)$@ $(SRCDIR)poke.c 
	
clean:
	@rm -rf $(SRCDIR)*.o 
	@echo "Cleaning done :)"


