# Makefile for sudoku project, Linux

sudoku: main.o input_type.o num_of_cros.o rand_array.o init.o sort_array.o zeros.o sud_maker.o psbl_sc.o input_psbl_sc.o revers.o decision.o substitution.o io_system.o colors.o frame.o cursor.o message.o coincidence.o rand_array_special.o forecasting.o
	gcc -o sudoku main.o input_type.o num_of_cros.o rand_array.o init.o sort_array.o zeros.o sud_maker.o psbl_sc.o input_psbl_sc.o revers.o decision.o substitution.o io_system.o colors.o frame.o cursor.o message.o coincidence.o rand_array_special.o forecasting.o -lncurses -std=gnu99 -Wall

main.o: main.c
	gcc -c main.c -std=gnu99 -Wall

input_type.o: input_type.c
	gcc -c input_type.c -std=gnu99 -Wall

num_of_cros.o: num_of_cros.c
	gcc -c num_of_cros.c -std=gnu99 -Wall

rand_array.o: rand_array.c
	gcc -c rand_array.c -std=gnu99 -Wall

rand_array_special.o: rand_array_special.c
	gcc -c rand_array_special.c -std=gnu99 -Wall

forecasting.o: forecasting.c
	gcc -c forecasting.c -std=gnu99 -Wall

init.o: init.c
	gcc -c init.c -std=gnu99 -Wall

sort_array.o: sort_array.c
	gcc -c sort_array.c -std=gnu99 -Wall

zeros.o: zeros.c
	gcc -c zeros.c -std=gnu99 -Wall

sud_maker.o: sud_maker.c
	gcc -c sud_maker.c -std=gnu99 -Wall

psbl_sc.o: psbl_sc.c
	gcc -c psbl_sc.c -std=gnu99 -Wall

input_psbl_sc.o: input_psbl_sc.c
	gcc -c input_psbl_sc.c -std=gnu99 -Wall

revers.o: revers.c
	gcc -c revers.c -std=gnu99 -Wall

decision.o: decision.c
	gcc -c decision.c -std=gnu99 -Wall

substitution.o: substitution.c
	gcc -c substitution.c -std=gnu99 -Wall

io_system.o: io_system.c
	gcc -c io_system.c -std=gnu99 -Wall

colors.o: colors.c
	gcc -c colors.c -std=gnu99 -Wall

frame.o: frame.c
	gcc -c frame.c -std=gnu99 -Wall

cursor.o: cursor.c
	gcc -c cursor.c -std=gnu99 -Wall

coincidence.o: coincidence.c
	gcc -c coincidence.c -std=gnu99 -Wall

message.o: message.c
	gcc -c message.c -std=gnu99 -Wall

clean:
	rm -f *.o *.a *.so sudoku

