IDIR=../include
CC=gcc
CFLAGS=-Wall -I$(IDIR)

ODIR=obj

LIBS=-lpthread

_DEPS = buffer.h consumer.h producer.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o buffer.o producer.o consumer.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
