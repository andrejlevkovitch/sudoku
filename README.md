# sudoku

Эта программа создает матрицы для судоку методом уменшающегося псвдорандома. Каждая головоломка имеет только одно решение, так как перед созданием проверяется на решаемость. Сложность задается пользователем методом вычеркивания желаемого количество цифр.
Создается и работает под Линуксом!
Пишется на языке Си.
Система Линукс.
Требует наличия libncurses libncurses-dev.

Основы управления:
- перемещение осуществляется стрелками
- удаление символа осуществляется с помощью клавиши BackSpace
- выход из программы с помощью клавиши ESC

andrejlevkovitch@gmail.com

coincidence.c проверяет нет ли вводимого значения в уже имеющемся массиве (рабочая версия)

cursor.c передвигает курсор в поле судоку, вводит значения (рабочая версия)

decision.c решение судоку (рабочая версия)

frame.c выводит на экран рамку для судоку (рабочая версия)

init.c инициализация возможных чисел (рабочая версия)

input_psbl_sc.c составляет линию возможных (вычеркнутых) цифр (рабочая версия)

input_type.c вводит тип судоку (рабочая версия)

io.c система ввода-вывода

main.c основная прога (рабочая версия)

mesage.c выводит сообщения на экран

num_of_cros.c вводит количество вычеркиваемых цифр (рабочая версия)

psbl_sc.c вводит массивы возможных для внесения в судоку значений в столбцах и строках (рабочая версия)

rand_array.c рандомизирует начальную матрицу (рабочая версия)

revers.c отображает (зеркально) матрицу судоку (рабочая версия)

sort_array.c сортирует массив (рабочая версия)

substitution.c меняет массивы местами (рабочая версия)

sud_maker.c вычеркивает цифры из матрицы (рабочая версия)

zeros.c обнуляет массив (рабочая версия)

sudlib.h основной заголовочный файл

Makefile директивы make

.gitignore список игнорируемых файлов

Структура:

main.c

{

    input_type.c

    num_of_cros.c

    rand_array.c
    {
        init.c
        sort_array.c
        zeros.c
    }

    sud_maker.c
    {
        psbl_sc.c
        {
            init.c
            input_psbl_sc.c
            revers.c
        }

        decision.c
        {
            substitution.c
            revers.c
        }
    }

    io.c
    {
        frame.c
        cursor.c
        {
            coincidence.c
            mesage.c
        }
    }

}

Готово к употреблению!!!
