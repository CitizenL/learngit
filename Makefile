OBJS=test.o
HEAD=
make:${OBJS} ${HEAD}
	gcc -std=c99 -g -o a.out ${OBJS}
test.o:test.c ${HEAD}
	gcc -std=c99 -g -c test.c
clean:
	rm -rf ${OBJS} a.out
