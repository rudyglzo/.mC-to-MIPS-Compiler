CC=gcc
CFLAGS = -I. -Isrc
LEX=flex

scanner: lex.yy.o driver.o
	$(CC) $(CFLAGS) -o scanner driver.o lex.yy.o -lfl

lex.yy.o: lex.yy.c
	$(CC) $(CFLAGS) -c lex.yy.c

lex.yy.c: src/scanner.l
	$(LEX) src/scanner.l

driver.o: src/driver.c
	$(CC)  $(CFLAGS) -c src/driver.c

clean:
	rm -f lex.yy.* *.o *~ scanner
