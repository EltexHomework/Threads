# Задание №11 - Потоки
## Сборщик проекта
В качестве сборщика проекта используется Makefile. Для компиляции проекта необходимо ввести следующую команду в корне проекта:
``` bash
make
```

Для очистки бинарных файлов можно воспользоваться командой:
``` bash
make clean
```

Для задания №2 использовать команды:
- mutexes
``` bash
make mutexes
```
- no_mutexes
``` bash
make no_mutexes
```

## Задание
1) Написать программу, в которой 5 потоков получают свои индексы и выводят их на экран.
2) Написать программу, в которой несколько потоков инкрементируют одну глобальную переменную с использованием / без использования мьютексов.
3) Написать многопоточную программу с магазинами и покупателями. В начале работы 5 магазинов заполняются ≈10.000 единицами товара. Есть 3 покупателя с потребностью у каждого ≈100.000 единиц. Каждый покупатель заходит в случайный свободный магазин, забирает товары и засыпает на 2 секунды. При удовлетворении всей потребности поток покупателя уничтожается. Также существует погрузчик, который каждую секунду добавляет в случайный магазин 5000 единиц товара. Когда все покупатели удовлетворили потребности, программа завершается. Все участники логируют действия в стандартный поток вывода.

## Результаты тестирования программ
### Задание №3
```
Loader started
Customer 1 started
Loader loaded 2 shop. Goods: 8859
Customer 2 started
Customer 1 bought 8859 goods from 2 shop. Demand: 91141
Customer 3 started
Customer 2 bought 874 goods from 5 shop. Demand: 99126
Customer 3 bought 533 goods from 4 shop. Demand: 99467
Loader loaded 5 shop. Goods: 5000
Customer 2 bought 0 goods from 4 shop. Demand: 99126
Loader loaded 5 shop. Goods: 10000
Customer 3 bought 0 goods from 4 shop. Demand: 99467
Customer 1 bought 10000 goods from 5 shop. Demand: 81141
Loader loaded 2 shop. Goods: 5000
Customer 2 bought 2616 goods from 1 shop. Demand: 96510
Customer 3 bought 0 goods from 4 shop. Demand: 99467
Customer 1 bought 0 goods from 5 shop. Demand: 81141
Loader loaded 2 shop. Goods: 10000
Loader loaded 4 shop. Goods: 5000
Customer 2 bought 0 goods from 5 shop. Demand: 96510
Customer 3 bought 5000 goods from 4 shop. Demand: 94467
Customer 1 bought 10000 goods from 2 shop. Demand: 71141
Loader loaded 3 shop. Goods: 11541
Loader loaded 4 shop. Goods: 5000
Customer 2 bought 0 goods from 2 shop. Demand: 96510
Customer 3 bought 11541 goods from 3 shop. Demand: 82926
Customer 1 bought 0 goods from 2 shop. Demand: 71141
Loader loaded 4 shop. Goods: 10000
Loader loaded 5 shop. Goods: 5000
Customer 2 bought 0 goods from 3 shop. Demand: 96510
Customer 3 bought 5000 goods from 5 shop. Demand: 77926
Customer 1 bought 10000 goods from 4 shop. Demand: 61141
Loader loaded 4 shop. Goods: 5000
Loader loaded 1 shop. Goods: 5000
Customer 2 bought 0 goods from 5 shop. Demand: 96510
Customer 3 bought 0 goods from 3 shop. Demand: 77926
Customer 1 bought 0 goods from 2 shop. Demand: 61141
Loader loaded 4 shop. Goods: 10000
Loader loaded 3 shop. Goods: 5000
Customer 2 bought 10000 goods from 4 shop. Demand: 86510
Customer 3 bought 0 goods from 4 shop. Demand: 77926
Customer 1 bought 0 goods from 4 shop. Demand: 61141
Loader loaded 2 shop. Goods: 5000
Loader loaded 5 shop. Goods: 5000
Customer 2 bought 5000 goods from 5 shop. Demand: 81510
Customer 3 bought 0 goods from 4 shop. Demand: 77926
Customer 1 bought 5000 goods from 3 shop. Demand: 56141
Loader loaded 4 shop. Goods: 5000
Loader loaded 3 shop. Goods: 5000
Customer 2 bought 5000 goods from 4 shop. Demand: 76510
Customer 3 bought 0 goods from 5 shop. Demand: 77926
Customer 1 bought 5000 goods from 1 shop. Demand: 51141
Loader loaded 5 shop. Goods: 5000
Loader loaded 5 shop. Goods: 10000
Customer 2 bought 0 goods from 4 shop. Demand: 76510
Customer 3 bought 0 goods from 1 shop. Demand: 77926
Customer 1 bought 0 goods from 4 shop. Demand: 51141
Loader loaded 2 shop. Goods: 10000
Loader loaded 1 shop. Goods: 5000
Customer 2 bought 5000 goods from 3 shop. Demand: 71510
Customer 3 bought 0 goods from 4 shop. Demand: 77926
Customer 1 bought 5000 goods from 1 shop. Demand: 46141
Loader loaded 3 shop. Goods: 5000
Loader loaded 5 shop. Goods: 15000
Customer 2 bought 5000 goods from 3 shop. Demand: 66510
Customer 3 bought 10000 goods from 2 shop. Demand: 67926
Customer 1 bought 0 goods from 4 shop. Demand: 46141
Loader loaded 1 shop. Goods: 5000
Loader loaded 1 shop. Goods: 10000
Customer 2 bought 0 goods from 2 shop. Demand: 66510
Customer 1 bought 10000 goods from 1 shop. Demand: 36141
Customer 3 bought 0 goods from 4 shop. Demand: 67926
Loader loaded 1 shop. Goods: 5000
Loader loaded 1 shop. Goods: 10000
Customer 2 bought 0 goods from 3 shop. Demand: 66510
Customer 1 bought 10000 goods from 1 shop. Demand: 26141
Customer 3 bought 15000 goods from 5 shop. Demand: 52926
Loader loaded 4 shop. Goods: 5000
Loader loaded 3 shop. Goods: 5000
Customer 2 bought 5000 goods from 3 shop. Demand: 61510
Customer 3 bought 0 goods from 5 shop. Demand: 52926
Customer 1 bought 0 goods from 3 shop. Demand: 26141
Loader loaded 5 shop. Goods: 5000
Loader loaded 4 shop. Goods: 10000
Customer 2 bought 0 goods from 3 shop. Demand: 61510
Customer 3 bought 5000 goods from 5 shop. Demand: 47926
Customer 1 bought 0 goods from 5 shop. Demand: 26141
Loader loaded 5 shop. Goods: 5000
Loader loaded 1 shop. Goods: 5000
Customer 2 bought 0 goods from 2 shop. Demand: 61510
Customer 3 bought 5000 goods from 5 shop. Demand: 42926
Customer 1 bought 0 goods from 3 shop. Demand: 26141
Loader loaded 5 shop. Goods: 5000
Loader loaded 4 shop. Goods: 15000
Customer 2 bought 5000 goods from 5 shop. Demand: 56510
Customer 3 bought 5000 goods from 1 shop. Demand: 37926
Customer 1 bought 0 goods from 2 shop. Demand: 26141
Loader loaded 5 shop. Goods: 5000
Loader loaded 3 shop. Goods: 5000
Customer 2 bought 0 goods from 2 shop. Demand: 56510
Customer 3 bought 15000 goods from 4 shop. Demand: 22926
Customer 1 bought 0 goods from 4 shop. Demand: 26141
Loader loaded 2 shop. Goods: 5000
Loader loaded 1 shop. Goods: 5000
Customer 2 bought 5000 goods from 1 shop. Demand: 51510
Customer 3 bought 5000 goods from 2 shop. Demand: 17926
Customer 1 bought 0 goods from 1 shop. Demand: 26141
Loader loaded 5 shop. Goods: 10000
Loader loaded 2 shop. Goods: 5000
Customer 2 bought 0 goods from 4 shop. Demand: 51510
Customer 3 bought 5000 goods from 3 shop. Demand: 12926
Customer 1 bought 0 goods from 1 shop. Demand: 26141
Loader loaded 3 shop. Goods: 5000
Loader loaded 4 shop. Goods: 5000
Customer 2 bought 5000 goods from 2 shop. Demand: 46510
Customer 3 bought 0 goods from 1 shop. Demand: 12926
Customer 1 bought 5000 goods from 3 shop. Demand: 21141
Loader loaded 1 shop. Goods: 5000
Loader loaded 2 shop. Goods: 5000
Customer 2 bought 10000 goods from 5 shop. Demand: 36510
Customer 3 bought 5000 goods from 2 shop. Demand: 7926
Customer 1 bought 5000 goods from 1 shop. Demand: 16141
Loader loaded 4 shop. Goods: 10000
Loader loaded 3 shop. Goods: 5000
Customer 2 bought 0 goods from 2 shop. Demand: 36510
Customer 3 bought 5000 goods from 3 shop. Demand: 2926
Customer 1 bought 0 goods from 1 shop. Demand: 16141
Loader loaded 3 shop. Goods: 5000
Loader loaded 5 shop. Goods: 5000
Customer 2 bought 5000 goods from 3 shop. Demand: 31510
Customer 3 bought 0 goods from 2 shop. Demand: 2926
Customer 1 bought 0 goods from 3 shop. Demand: 16141
Loader loaded 3 shop. Goods: 5000
Loader loaded 3 shop. Goods: 10000
Customer 2 bought 10000 goods from 3 shop. Demand: 21510
Customer 3 bought 0 goods from 3 shop. Demand: 2926
Customer 1 bought 10000 goods from 4 shop. Demand: 6141
Loader loaded 5 shop. Goods: 10000
Loader loaded 3 shop. Goods: 5000
Customer 2 bought 10000 goods from 5 shop. Demand: 11510
Customer 3 bought 0 goods from 5 shop. Demand: 2926
Customer 1 bought 0 goods from 2 shop. Demand: 6141
Loader loaded 3 shop. Goods: 10000
Loader loaded 3 shop. Goods: 15000
Customer 2 bought 0 goods from 2 shop. Demand: 11510
Customer 3 bought 0 goods from 4 shop. Demand: 2926
Customer 1 bought 0 goods from 5 shop. Demand: 6141
Loader loaded 4 shop. Goods: 5000
Loader loaded 4 shop. Goods: 10000
Customer 2 bought 0 goods from 1 shop. Demand: 11510
Customer 3 bought 0 goods from 1 shop. Demand: 2926
Customer 1 bought 0 goods from 2 shop. Demand: 6141
Loader loaded 3 shop. Goods: 20000
Loader loaded 4 shop. Goods: 15000
Customer 2 bought 0 goods from 2 shop. Demand: 11510
Customer 3 bought 2926 goods from 4 shop. Demand: 0
Customer 1 bought 6141 goods from 4 shop. Demand: 0
Loader loaded 2 shop. Goods: 5000
Loader loaded 4 shop. Goods: 10933
Customer 2 bought 11510 goods from 3 shop. Demand: 0
Customer 3 fulfilled demand
Customer 1 fulfilled demand
Loader loaded 1 shop. Goods: 5000
Loader loaded 5 shop. Goods: 5000
Customer 2 fulfilled demand
```
## Демонстрация работы программ
### Задание №1
![task1](https://github.com/user-attachments/assets/f68fe797-a1ec-430a-b616-55261a1f7037)

### Задание №2
![task2](https://github.com/user-attachments/assets/a381af1a-c73d-4af8-ba0f-faf444649e48)

### Задание №3
![task3](https://github.com/user-attachments/assets/9e78c46b-f5cf-40f7-a900-7090b001c350)
