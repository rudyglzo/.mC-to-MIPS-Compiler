CC = gcc
CFLAGS = -I./src -std=gnu99
LEX = lex
YACC = bison
YFLAGS = -v -d
GRAMMAR = parser.y
OBJS = obj/lex.yy.o obj/parser.tab.o obj/tree.o obj/driver.o obj/strtab.o obj/codegen.o

obj/mcc: $(OBJS) | obj
	$(CC) $(CFLAGS) -o $@ $^ -ll

obj/parser.tab.o: obj/parser.tab.c | obj
	$(CC) $(CFLAGS) -c $< -o $@

obj/lex.yy.o: obj/lex.yy.c | obj
	$(CC) $(CFLAGS) -c $< -o $@

obj/parser.tab.h obj/parser.tab.c: src/$(GRAMMAR) src/tree.h | obj
	$(YACC) $(YFLAGS) -o obj/parser.tab.c src/$(GRAMMAR)

obj/lex.yy.c: src/scanner.l obj/parser.tab.h | obj
	$(LEX) -o $@ src/scanner.l

obj/tree.o: src/tree.c src/tree.h | obj
	$(CC) $(CFLAGS) -c $< -o $@

obj/driver.o: src/driver.c src/tree.h obj/parser.tab.h | obj
	$(CC) $(CFLAGS) -c $< -o $@

obj/strtab.o: src/strtab.c src/strtab.h obj/parser.tab.h | obj
	$(CC) $(CFLAGS) -c $< -o $@

obj/codegen.o: src/codegen.c src/codegen.h src/tree.h | obj
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean test objdir

obj:
	@mkdir -p obj

clean:
	@rm -rf obj
	@rm -f lex.yy.* *.o *~ scanner

test: obj/mcc
	@python ./test/testParser.py