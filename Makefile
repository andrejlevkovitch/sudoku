# Makefile for sudoku project, Linux

sudoku: main.o libsudoku.so
	gcc -o sudoku main.o -lncurses -L. -lsudoku

libsudoku.so: flags.o input_type.o num_of_cros.o  init.o   sud_maker.o psbl_sc.o input_psbl_sc.o revers.o decision.o substitution.o io_system.o colors.o frame.o cursor.o message.o coincidence.o rand_array_special.o forecasting.o
	gcc -shared -o libsudoku.so flags.o input_type.o num_of_cros.o  init.o   sud_maker.o psbl_sc.o input_psbl_sc.o revers.o decision.o substitution.o io_system.o colors.o frame.o cursor.o message.o coincidence.o rand_array_special.o forecasting.o -std=gnu99 -Wall

main.o: main.c
	gcc -c -fPIC main.c -std=gnu99 -Wall

flags.o: flags.c
	gcc -c -fPIC flags.c -std=gnu99 -Wall

input_type.o: input_type.c
	gcc -c -fPIC input_type.c -std=gnu99 -Wall

num_of_cros.o: num_of_cros.c
	gcc -c -fPIC num_of_cros.c -std=gnu99 -Wall

rand_array_special.o: rand_array_special.c
	gcc -c -fPIC rand_array_special.c -std=gnu99 -Wall

forecasting.o: forecasting.c
	gcc -c -fPIC forecasting.c -std=gnu99 -Wall

init.o: init.c
	gcc -c -fPIC init.c -std=gnu99 -Wall

sud_maker.o: sud_maker.c
	gcc -c -fPIC sud_maker.c -std=gnu99 -Wall

psbl_sc.o: psbl_sc.c
	gcc -c -fPIC psbl_sc.c -std=gnu99 -Wall

input_psbl_sc.o: input_psbl_sc.c
	gcc -c -fPIC input_psbl_sc.c -std=gnu99 -Wall

revers.o: revers.c
	gcc -c -fPIC revers.c -std=gnu99 -Wall

decision.o: decision.c
	gcc -c -fPIC decision.c -std=gnu99 -Wall

substitution.o: substitution.c
	gcc -c -fPIC substitution.c -std=gnu99 -Wall

io_system.o: io_system.c
	gcc -c -fPIC io_system.c -std=gnu99 -Wall

colors.o: colors.c
	gcc -c -fPIC colors.c -std=gnu99 -Wall

frame.o: frame.c
	gcc -c -fPIC frame.c -std=gnu99 -Wall

cursor.o: cursor.c
	gcc -c -fPIC cursor.c -std=gnu99 -Wall

coincidence.o: coincidence.c
	gcc -c -fPIC coincidence.c -std=gnu99 -Wall

message.o: message.c
	gcc -c -fPIC message.c -std=gnu99 -Wall

clean:
	rm -f *.o *.a *.so sudoku

install:
	sudo install libsudoku.so /usr/lib
	sudo install ./sudoku /usr/local/bin

uninstall:
	sudo rm -rf /usr/lib/libsudoku.so
	sudo rm -rf /usr/local/bin/sudoku
