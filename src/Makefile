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

style_check:
	find . -name "*.c" -o -name "*.h" -o -name "*.cpp" | xargs clang-format -style=Google -n

style_set:
	find . -name "*.c" -o -name "*.h" -o -name "*.cpp" | xargs clang-format -style=Google -i


main: clean
	$(CC) $(CFLAGS) -c func/*.c
	$(CC) $(CFLAGS) main.c *.o -o main
	./main

install: uninstall
	cd calc/ && qmake && make && make clean
	mv calc/calc.app build

open:
	./build/Contents/MacOS/calc

uninstall:
	cd calc && rm -rf Makefile calc.app calc.pro.user .qmake.stash .qtc_clangd .tmp .qm
	rm -rf build

dist: install
	rm -rf Archive_calc/
	mkdir Archive_calc/
	mv build/calc.app Archive_calc/
	tar -cvzf Archive_calc.tar.gz Archive_calc

dvi:
	open docs/index.html

valgrind:
	valgrind --vgdb=no --leak-check=full --show-reachable=yes --show-leak-kinds=all --track-origins=yes --verbose --read-var-info=yes ./build/calc.app/Contents/MacOS/calc

valgrind_main: clean
	make main && CK_FORK=no valgrind --vgdb=no --leak-check=full --show-reachable=yes --show-leak-kinds=all --track-origins=yes --verbose --read-var-info=yes ./main

leaks:
	leaks -atExit -- ./build/Contents/MacOS/calc

clean: 
	rm -rf *.o main
	rm -rf *.o test
	rm -rf *.o *.a
	rm -rf *.o a.out
	rm -rf *.o *.gcno
	rm -rf *.o *.gcda
	rm -rf *.o test.dSYM
	rm -rf *.o *.info
	rm -rf *.o report
	rm -rf Archive_calc
	rm -rf Archive_calc.tar.gz
	clear