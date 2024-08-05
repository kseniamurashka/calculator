# Лабораторная работа по ТСПП  (2023/2024 учебный год)
## Тема: полный калькулятор
Данная программа представляет собой реализацию полного калькулятора математических выражений, выполняющего как основные арифметические операции, так и тригонометрические и логарифмические функции.

## Зависимости ПО
В целях тестирования программы в проект был включен git submodule googletest.
В коде использованы бибилиотеки C++:
- iostream
- cstdlib
- algorithm
- string
- vector
- stack
- queue

Сторонние библиотеки или утилиты использованы не были, все необходимые файлы содержатся в репозитории.

## Сборка ПО
Использовалась система сборки Make. В файле Makefile содержится скрипт для сборки и тестирования программы.
- Для проведения тестов использовать скрипт: 
```
make runtest
```
Исполняемый файл имеет название test
- Для запуска калькултора использовать скрпит: 
```
make run
```
 Исполняемый файл имеет название calc

Список необходимых системе сборки файлов:
- main.cpp
- Calculator.h
- Calculator.cpp
- test.h
- test.cpp

## Использование ПО
После запуска исполняемого файла программа ожидает строку, содержащую математическое выражение.
Калькулятор работает с целыми и дробными числами(дробная часть отдельяется точкой). Допустимые операции и функции:
- () - скобки
- +, -, *, /, ^ - сложение, вычитание (может также быть унтерпретировано как унарный минус), умножение, деление, возведение в степень соответсвенно
- root - функция корня, принимает два аргрумента: основание и степень
- sin, cos, tg, ctg - тригонометрические функции
- acos, asin, atg, actg - обратные тригонометрические функции
- lnn, log2n, lgn - функции натурального логарифма, логарифма основания 2 и 10
Выражение должно удовлетворять следующим требованиям:
- Соблюден баланс скобок
- Не используются иные операторы или функции, кроме обозначенных выше
- Бинарные операторы не дублирутся и имееют два операнда, находящиеся по разные стороны от оператора
- Унарный минус не дублируется 
- Все функции, за исключением корня, получают только один аргумент
- Аргумент(ы) функций заключен(ы) в скобки
- Аругменты валидны (логарифмические функции получают только положительные аргументы, аргументы arcsin и arccos принадлежит отрезку [-1, 1], корень четной степени берется от положительного числа, отрицаельное число не возводится в дробную степень и другое)

## Авторы
* **Мурашка К.М.** - *разработчик* - [gitlab](https://vgit.mirea.ru/ksenia_murashka)