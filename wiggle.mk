CFLAGS = $(shell pkg-config --cflags x11)
LIBS = $(shell pkg-config --libs x11)  -lxdo

wiggle: wiggle.o
	${CC} -o $@ $< ${LIBS}

wiggle.o: wiggle.c
	${CC} -c -o $@ $< ${CFLAGS}
