IDIR=./include
CC=gcc
ODIR=obj
CFLAGS= -Wall -ansi -pedantic -std=c99 -I $(IDIR)
LDIR=./lib

_DEPS = checksurrounding.h menu.h ReadFile.h writeToFile.h firstworld.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = GameofLife.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
GameofLife: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
.PHONY: clean
clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~