IDIR = include
CC = gcc
CFLAGS=-I$(IDIR) -Wall -Werror

SDIR = src

ODIR = build

_DEPS = linkedlist.h db.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = kv.o linkedlist.o db.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

kv: $(OBJ)
	$(CC) $^ -o $(ODIR)/$@ $(CFLAGS)

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) $< -c -o $@ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
