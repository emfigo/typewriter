CC=gcc

ODIR=obj
LDIR=lib
DDIR=include

_DEPS= reader.h printer.h typewriter.h
DEPS= $(patsubst %, $(DDIR)/%, $(_DEPS)) 
_SRCS= reader.c printer.c
SRCS= $(patsubst %, $(LDIR)/%, $(_SRCS)) 
OBJS= $(patsubst %, $(ODIR)/%, $(_SRCS:.c=.o)) 

CFLAGS=-I $(DDIR) -lm

$(ODIR)/%.o: $(LDIR)/%.c $(DEPS) 
	$(CC) -c -o $@ $< $(CFLAGS)

typewriter: $(OBJS) 
	$(CC) -o $@ $^ lib/typewriter.c $(CFLAGS)

.PHONY: clean

clean:
	rm obj/*
	if [ -f typewriter ]; then rm typewriter; fi
