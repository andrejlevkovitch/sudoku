# Makefile for sudoku project

sudoku: main.o init.o print_mas.o rand_array.o zeros.o num_of_cros.o input_type.o sort_array.o vozvrat.o sud_maker.o revers.o input_psbl_sc.o substitution.o mygetch.o psbl_sc.o decision.o
	gcc -o sudoku main.o init.o print_mas.o rand_array.o zeros.c num_of_cros.o input_type.o sort_array.o vozvrat.o sud_maker.o revers.o input_psbl_sc.o substitution.o mygetch.o psbl_sc.o decision.o -Wall

init.o: init.c
	gcc -c init.c -Wall

main.o: main.c
	gcc -c main.c -Wall

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

revers.o: revers.c
	gcc -c revers.c -Wall

input_psbl_sc.o: input_psbl_sc.c
	gcc -c input_psbl_sc.c -Wall

substitution.o: substitution.c
	gcc -c substitution.c -Wall

mygetch.o: mygetch.c
	gcc -c mygetch.c -Wall

psbl_sc.o: psbl_sc.c
	gcc -c psbl_sc.c -Wall

decision.o: decision.c
	gcc -c decision.c -Wall

clean:
	rm -f *.o sudoku
