OBJS=test.o
make:${OBJS} 
	gcc -std=c99 -g -o a.out ${OBJS}
test.o:test.c
	gcc -std=c99 -g -c test.c
clean:
	rm -rf ${OBJS} a.out
