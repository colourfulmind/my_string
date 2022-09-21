CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11 -g
LFLAGS = -fprofile-arcs -ftest-coverage -lm -lpthread
INC_CHECK = $(shell pkg-config --cflags --libs check)


all: my_string.a test gcov_report

clean:
	rm -rf *.o *.a test *.html *.css *.out *.gcda *.gcno test.dSYM
	rm -f .clang-format

test: my_string_test.a my_string_test.c
	$(CC) my_string_test.c $(INC_CHECK) $(CFLAGS) $(LFLAGS) -lcheck my_string_test.a -o $@

my_string_test.a: my_string.c my_sprintf_helpful.c my_sprintf.c my_sscanf.c
	$(CC) -c $(CFLAGS) --coverage $?
	ar -rcs $@ *.o
	ranlib $@
	rm -f *.o

my_string.a: my_string.c my_sprintf_helpful.c my_sprintf.c my_sscanf.c
	$(CC) -c $(CFLAGS) $?
	ar rc $@ *.o
	ranlib $@

rebuild: clean all

gcov_report: test
	./$?
	gcovr -r . --html --html-details -o coverage_report.html
	rm -f tests_my_string.gcda tests_my_string.gcno
	#open coverage_report.html

.PHONY: all clean test my_string.a rebuild gcov_report cppch
