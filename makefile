main: test.c partition.c partition.h
	gcc -o main test.c partition.c partition.h -I.