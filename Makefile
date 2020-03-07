CC = gcc
CFLAGS = -std=c11 -g

all:
	# gcc -c header.h $(CFLAGS)
	$(CC) -c util.h util.c $(CFLAGS)
	$(CC) -c _malloc.h _malloc.c $(CFLAGS)
	# gcc -c test.c $(CFLAGS)
	$(CC) test.c header.h util.o _malloc.o -o main  $(CFLAGS)
	@echo "=================== Successful ==================="
clear:
	rm -f *.o *.gch main