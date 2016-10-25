BINDIR=bin/
SRCDIR=src/

CC=gcc
CFLAGS=-Wall -g

jeux : $(BINDIR)main.o $(BINDIR)poketudiant.o $(BINDIR)poke.o
	@$(CC) -o jeux  $(BINDIR)*.o
	
$(BINDIR)main.o: $(SRCDIR)*.c $(SRCDIR)*.h
	@$(CC) $(CFLAGS) -c  -o $@ $(SRCDIR)main.c 	
	
$(BINDIR)poketudiant.o : $(SRCDIR)poketudiant.c $(SRCDIR)poketudiant.h
	@$(CC) $(CFLAGS) -c  -o $@ $(SRCDIR)poketudiant.c 	

$(BINDIR)poke.o : $(SRCDIR)poke.c $(SRCDIR)poke.h 
	@$(CC) $(CFLAGS) -c  -o $@ $(SRCDIR)poke.c 
	
clean:
	@rm -rf $(BINDIR)*.o 
	@echo "Cleaning done :)"


