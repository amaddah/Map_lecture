SHELL = /bin/bash

CC=clang
Compil=-g -O0 -Wall
Lib=-pthread

EXEC=executable
OBJDIR = obj
SRCDIR = .

Objets = $(OBJDIR)/main.o $(OBJDIR)/map.o $(OBJDIR)/messages.o

all:$(EXEC)

$(EXEC):$(Objets)
				-$(CC) $(Objets) -o $(EXEC) $(Lib)
				@echo "Executable crée !"

$(OBJDIR)/%.o:$(SRCDIR)/%.c
				-$(CC) -o $@ -c $^ $(Compil)
				@echo "Compilation de "$^" reussie !"

do:
	./do.sh
clean:
	rm -Rvf obj
	@echo "obj et .o supprimés !"
	mkdir obj
	@echo "obj recrée !"
run:
	make clean && make && ./$(EXEC)
debug:
	make clean && make && gdb ./$(EXEC)
debugmm:
	make clean && make && valgrind ./$(EXEC)
