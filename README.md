# sudoku
______
Эта программа генерирует уникальные судоку, имеющие только одно решение. Пользователь может выбрать тип судоку: с буквами или цифрами, и количество вычеркнутых цифр (ограничено 58 в целях производительности).

Программа работает следующим образом:
1) осуществляется ввод типа судоку (имеет значение только при выводе - само судоку представляет собой матрицу с цифрами 0..8) и количество вычеркнутых цифр.
2) происходит рандомизация начальной матрицы, в результате которой появляется матрица судоку
3) вычеркивание значений и проверка на решаемость (необходима для создания судоку, которое имеет только одно решение).
4) система ввода-вывода позволяет решать полученное судоку.

Создается и работает под Линуксом!

Пишется на языке Си (-std=gnu99).

Требует наличия libncurses-dev
Установка с помощью make. Запуск через терминал ./sudoku
______
Основы управления:
- перемещение осуществляется стрелками
- удаление символа осуществляется с помощью клавиши BackSpace
- выход из программы с помощью клавиши ESC (на данный момент нужно нажать ESC и любую другую клавишу - особенность структуры вывода)
______
andrejlevkovitch@gmail.com
______
coincidence.c проверяет нет ли вводимого значения в уже имеющемся массиве (рабочая версия)

colors.c цвета (рабочая версия)

cursor.c передвигает курсор в поле судоку, вводит значения (рабочая версия)

decision.c решение судоку (рабочая версия)

frame.c выводит на экран рамку для судоку (рабочая версия)

init.c инициализация возможных чисел (рабочая версия)

input_psbl_sc.c составляет линию возможных (вычеркнутых) цифр (рабочая версия)

input_type.c вводит тип судоку (рабочая версия)

io_system.c система ввода-вывода (рабочая версия)

main.c основная прога (рабочая версия)

message.c выводит сообщения на экран (рабочая версия)

num_of_cros.c вводит количество вычеркиваемых цифр (рабочая версия)

psbl_sc.c вводит массивы возможных для внесения в судоку значений в столбцах и строках (рабочая версия)

rand_array.c рандомизирует начальную матрицу (рабочая версия)

revers.c отображает (зеркально) матрицу судоку (рабочая версия)

sort_array.c сортирует массив (рабочая версия)

substitution.c меняет массивы местами (рабочая версия)

sud_maker.c вычеркивает цифры из матрицы (рабочая версия)

zeros.c обнуляет массив (рабочая версия)
______
sudlib.h основной заголовочный файл

Makefile директивы make

.gitignore список игнорируемых файлов
______
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

    io_system.c
    {
        colors.c
        frame.c
        cursor.c
        {
            coincidence.c
            message.c
        }
    }

}
______
Готово к употреблению!!!
