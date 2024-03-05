gcc = gcc 
flags = -Werror -Wall -Wextra -std=c11
check_flag = -lcheck
gcov_flags = -fprofile-arcs -ftest-coverage
valgrind_flags = --log-file="valgrind.txt" --track-origins=yes --trace-children=yes --leak-check=full --leak-resolution=med --show-leak-kinds=all

files = *.c
test_files = ./tests/*.c
out_file = ./s21_matrix
library = ./s21_matrix.a

ifeq ($(shell uname -s), Linux)
	check_flag += -lm -lsubunit
	open=xdg-open
else
	open=open
endif

all: clang s21_matrix.a

s21_matrix.a:
	$(gcc) -c -g $(flags) $(files)
	ar rcs $(library) ./*.o 
	ranlib $(library)
	rm ./*.o

test: s21_matrix.a
	$(gcc) -g $(flags) $(test_files) $(library) -o $(out_file) $(check_flag)
	./s21_matrix
	
gcov_report:
	$(gcc) $(flags) $(gcov_flags) $(test_files) $(files) -o $(out_file) $(check_flag)
	./s21_matrix
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info 
	$(open) report/index.html
	make rm_gcov
	rm *.info

clean:
	-rm *.o
	-rm *.a
	-rm $(out_file)
	-rm $(library)
	-rm -rf report
	-make rm_gcov
	-rm valgrind.txt

rebuild:
	make clean
	make all

rm_gcov:
	rm *.gcno	
	rm *.gcda

clang:
	cp ../materials/linters/.clang-format ./
	clang-format -i */*.c *.h

format_check:
	cp ../materials/linters/.clang-format ./
	clang-format -n *.c *.h

valgrind: s21_matrix.a
	$(gcc) $(flags) $(test_files) $(library) -o $(out_file) $(check_flag)
	valgrind $(valgrind_flags) $(out_file)

val:
	gcc s21_matrix.c
	valgrind --tool=memcheck --leak-check=yes --show-leak-kinds=all ./a.out