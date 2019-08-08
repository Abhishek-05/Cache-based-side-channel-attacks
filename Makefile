OBJS=mem.o git-spy.o config.o
PROG=git-spy
CFLAGS=-g -std=gnu99 -O2
LOADLIBES= -lm

all: ${PROG}


spy: git-spy.o mem.o config.o

spy.o: mem.h config.h

mem.o: mem.h

config.o: config.h

clean: rm -f ${PROG} ${OBJS}
