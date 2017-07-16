# Makefile for sudoku project

sudoku: sudoku.o init.o print_mas.o rand_array.o zeros.o num_of_cros.o input_type.o sort_array.o vozvrat.o sud_maker.o
	gcc -o sudoku sudoku.o init.o print_mas.o rand_array.o zeros.c num_of_cros.o input_type.o sort_array.o vozvrat.o sud_maker.o -Wall

init.o: init.c
	gcc -c init.c -Wall

sudoku.o: sudoku.c
	gcc -c sudoku.c -Wall

print_mas.o: print_mas.c
	gcc -c print_mas.c -Wall

rand_array.o: rand_array.c
	gcc -c rand_array.c -Wall

zeros.o: zeros.c
	gcc -c zeros.c -Wall

input_type.o: input_type.c
	gcc -c input_type.c -Wall

num_of_cros.o: num_of_cros.c
	gcc -c num_of_cros.c -Wall

sort_array.o: sort_array.c
	gcc -c sort_array.c -Wall

vozvrat.o: vozvrat.c
	gcc -c vozvrat.c -Wall

sud_maker.o: sud_maker.c
	gcc -c sud_maker.c -Wall
clean:
	rm -f *.o sudoku
