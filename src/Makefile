CC = gcc
TESTFLAGS = -lcheck -g
CFLAGS = -Wall -Wextra -Werror -std=c11
TESTFLAGS2 = -lcheck -lm -lpthread -lrt -lsubunit -g
GCOVFLAGS = -fprofile-arcs -ftest-coverage

all: test

s21_matrix.a : func/*.c
	$(CC) $(CFLAGS) -g -std=c11 -c func/*.c
	ar rcs s21_matrix.a *.o
	rm -rf *.o

test: clean tests/test.c func/*.c
	$(CC) $(CFLAGS) -lcheck tests/test.c func/*.c -g -o test $(TESTFLAGS)
	./test

gcov_report:
	$(CC) $(GCOVFLAGS) $(CFLAGS) tests/test.c func/*.c -o test $(TESTFLAGS)
	./test
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info
	rm -rf gcovreport gcovreport.info *.gcda *.gcno string_test.gcda string_test.gcno
	open report/index.html
rebuild: clean all

clean: 
	rm -rf *.o test *.a a.out *.gcno *.gcda test.dSYM *.info report
	clear

style_check:
	find . -name "*.c" -o -name "*.h" | xargs clang-format -style=Google -n

style:
	find . -name "*.c" -o -name "*.h" | xargs clang-format -style=Google -i

main: clean
	$(CC) $(CFLAGS) -c func/*.c
	$(CC) $(CFLAGS) main.c *.o -o main
	./main

valgrind: clean
	make test && CK_FORK=no valgrind --vgdb=no --leak-check=full --show-reachable=yes --show-leak-kinds=all --track-origins=yes --verbose --read-var-info=yes ./test

valgrind_main: clean
	make main && CK_FORK=no valgrind --vgdb=no --leak-check=full --show-reachable=yes --show-leak-kinds=all --track-origins=yes --verbose --read-var-info=yes ./main

leaks: clean
	make test && leaks -atExit -- ./test