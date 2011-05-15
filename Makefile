CFLAGS = -Wall -g

all: trash

trash: trash.o
	gcc ${CLFLAGS} -o $@ $^
