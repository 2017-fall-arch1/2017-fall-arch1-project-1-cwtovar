all: bstDemo

CFLAGS=-g -O3

# Symbols helpful for understanding the productions
#   $@ is the production's target
#   $^ are the production's prerequisites

bstDemo: bst.o bstDemo.o
	cc -o $@ $^

bst.o: bst.c bst.h
	cc -c $(CFLAGS) bst.c

bstDemo.o: bstDemo.c bst.h
	cc -c $(CFLAGS) bstDemo.c

clean:
	rm -f *.o bstDemo

demo: bstDemo
	./bstDemo

