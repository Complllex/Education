CC = gcc
GLIB_HOME = /usr

SOURCES = as_strcmp.c as_strcmp_test.c
OBJECTS = $(SOURCES:%.c=%.o)
CFLAGS = -I$(GLIB_HOME)/include/glib-2.0 -I$(GLIB_HOME)/lib/glib-2.0/include -g -Wall
LDFLAGS = -L$(GLIB_HOME)/lib -lglib-2.0
PROGRAM = tests

.PHONY: all clean

all: $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $(PROGRAM)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -fr *.o $(PROGRAM) *.dSYM