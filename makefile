IDIR = include
CC = gcc
CFLAGS=-I$(IDIR) -Wall -Werror

SDIR = src

ODIR=build

_DEPS = linkedlist.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = kv.o linkedlist.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) $< -c -o $@ $(CFLAGS)

kv: $(OBJ)
	$(CC) $^ -o $@ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
