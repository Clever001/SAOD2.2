#include <iostream>
#include <locale.h>
#include "Stack.h"

using namespace std;

/*
17.	Сформировать стек из N чисел. Найти среднее арифметическое второго и третьего чисел. Результат поместить в стек.
*/


int main()
{
    setlocale(LC_ALL, "Rus");
    Stack<double> stack;
    double buf;
    while (cin >> buf) {
        stack.Push(buf);
    }
    if (stack.Size() < 3) {
        cout << "В стеке слишком мало чисел. Невозможно выполнить поставленную операцию." << '\n';
        return 0;
    }

    cout << "Вывод первоначального стека.\n";
    for (auto item : stack) {
        cout << item << ' ';
    }
    cout << '\n';

    double result = (stack[1] + stack[2]) / 2.0;
    stack.Push(result);

    cout << "Вывод измененного стека.\n";
    for (auto item : stack) {
        cout << item << ' ';
    }
    cout << '\n';
}
