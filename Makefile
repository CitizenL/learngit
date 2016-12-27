OBJS=test.o
LIB_PATH=/home/testlr/Exerceise/TEST/source/tlpi-dist/lib
make:${OBJS} 
	gcc -std=c99 -g -o a.out ${OBJS} -I ${LIB_PATH} -L ${LIB_PATH} -ltlpi
test.o:test.c
	gcc -std=c99 -g -c test.c -I ${LIB_PATH} 
clean:
	rm -rf ${OBJS} a.out
