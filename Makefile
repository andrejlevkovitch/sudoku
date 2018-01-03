# Makefile for sudoku project, Linux

sudoku: main.o libsudoku.so
	clang -o sudoku main.o -lncurses -L. -lsudoku

libsudoku.so: flags.o input_type.o num_of_cros.o  init.o   sud_maker.o psbl_sc.o input_psbl_sc.o revers.o decision.o substitution.o io_system.o colors.o frame.o cursor.o message.o coincidence.o rand_array_special.o forecasting.o mygetch.o
	clang -shared -o libsudoku.so flags.o input_type.o num_of_cros.o  init.o   sud_maker.o psbl_sc.o input_psbl_sc.o revers.o decision.o substitution.o io_system.o colors.o frame.o cursor.o message.o coincidence.o rand_array_special.o forecasting.o mygetch.o -Wall

main.o: main.c
	clang -c -fPIC main.c -Wall

flags.o: flags.c
	clang -c -fPIC flags.c -Wall

input_type.o: input_type.c
	clang -c -fPIC input_type.c -Wall

num_of_cros.o: num_of_cros.c
	clang -c -fPIC num_of_cros.c -Wall

rand_array_special.o: rand_array_special.c
	clang -c -fPIC rand_array_special.c -Wall

forecasting.o: forecasting.c
	clang -c -fPIC forecasting.c -Wall

init.o: init.c
	clang -c -fPIC init.c -Wall

sud_maker.o: sud_maker.c
	clang -c -fPIC sud_maker.c -Wall

psbl_sc.o: psbl_sc.c
	clang -c -fPIC psbl_sc.c -Wall

input_psbl_sc.o: input_psbl_sc.c
	clang -c -fPIC input_psbl_sc.c -Wall

revers.o: revers.c
	clang -c -fPIC revers.c -Wall

decision.o: decision.c
	clang -c -fPIC decision.c -Wall

substitution.o: substitution.c
	clang -c -fPIC substitution.c -Wall

io_system.o: io_system.c
	clang -c -fPIC io_system.c -Wall

colors.o: colors.c
	clang -c -fPIC colors.c -Wall

frame.o: frame.c
	clang -c -fPIC frame.c -Wall

cursor.o: cursor.c
	clang -c -fPIC cursor.c -Wall

coincidence.o: coincidence.c
	clang -c -fPIC coincidence.c -Wall

message.o: message.c
	clang -c -fPIC message.c -Wall

mygetch.o: mygetch.c	
	clang -c -fPIC mygetch.c -Wall

clean:
	rm -f *.o *.a *.so sudoku

install:
	sudo install libsudoku.so /usr/lib
	sudo install ./sudoku /usr/local/bin

uninstall:
	sudo rm -rf /usr/lib/libsudoku.so
	sudo rm -rf /usr/local/bin/sudoku
