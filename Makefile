# Makefile for sudoku project, Linux

sudoku: main.o init.o rand_array.o zeros.o num_of_cros.o input_type.o sort_array.o sud_maker.o revers.o input_psbl_sc.o substitution.o  psbl_sc.o decision.o io_system.o frame.o cursor.o message.o coincidence.o
	gcc -o sudoku main.o init.o rand_array.o zeros.c num_of_cros.o input_type.o sort_array.o sud_maker.o revers.o input_psbl_sc.o substitution.o  psbl_sc.o decision.o io_system.o frame.o cursor.o message.o coincidence.o -lncurses -Wall

main.o: main.c
	gcc -c main.c -Wall

input_type.o: input_type.c
	gcc -c input_type.c -Wall

num_of_cros.o: num_of_cros.c
	gcc -c num_of_cros.c -Wall

rand_array.o: rand_array.c
	gcc -c rand_array.c -Wall

init.o: init.c
	gcc -c init.c -Wall

sort_array.o: sort_array.c
	gcc -c sort_array.c -Wall

zeros.o: zeros.c
	gcc -c zeros.c -Wall

sud_maker.o: sud_maker.c
	gcc -c sud_maker.c -Wall

psbl_sc.o: psbl_sc.c
	gcc -c psbl_sc.c -Wall

input_psbl_sc.o: input_psbl_sc.c
	gcc -c input_psbl_sc.c -Wall

revers.o: revers.c
	gcc -c revers.c -Wall

decision.o: decision.c
	gcc -c decision.c -Wall

substitution.o: substitution.c
	gcc -c substitution.c -Wall

io_system.o: io_system.c
	gcc -c io_system.c -Wall

frame.o: frame.c
	gcc -c frame.c -Wall

cursor.o: cursor.c
	gcc -c cursor.c -Wall

coincidence.o: coincidence.c
	gcc -c coincidence.c -Wall

message.o: message.c
	gcc -c message.c -Wall

clean:
	rm -f *.o *.a *.so sudoku

