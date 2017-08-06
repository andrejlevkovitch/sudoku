# Makefile for sudoku project, Linux

sudoku: main.o init.o rand_array.o zeros.o num_of_cros.o input_type.o sort_array.o sud_maker.o revers.o input_psbl_sc.o substitution.o  psbl_sc.o decision.o io.o frame.o cursor.o mesage.o coincidence.o
	gcc -o sudoku main.o init.o rand_array.o zeros.c num_of_cros.o input_type.o sort_array.o sud_maker.o revers.o input_psbl_sc.o substitution.o  psbl_sc.o decision.o io.o frame.o cursor.o mesage.o coincidence.o -lncurses -Wall

main.o: main.c
	gcc -c main.c -Wall

init.o: init.c
	gcc -c init.c -Wall

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

sud_maker.o: sud_maker.c
	gcc -c sud_maker.c -Wall

revers.o: revers.c
	gcc -c revers.c -Wall

input_psbl_sc.o: input_psbl_sc.c
	gcc -c input_psbl_sc.c -Wall

substitution.o: substitution.c
	gcc -c substitution.c -Wall

psbl_sc.o: psbl_sc.c
	gcc -c psbl_sc.c -Wall

decision.o: decision.c
	gcc -c decision.c -Wall

io.o: io.c
	gcc -c io.c -Wall

frame.o: frame.c
	gcc -c frame.c -Wall

cursor.o: cursor.c
	gcc -c cursor.c -Wall

mesage.o: mesage.c
	gcc -c mesage.c -Wall

coincidence.o: coincidence.c
	gcc -c coincidence.c -Wall

clean:
	rm -f *.o *.a *.so sudoku

