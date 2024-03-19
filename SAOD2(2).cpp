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
    const int pos1 = 1, pos2 = 2;
    const bool fromStart = false;
    double sum = 0.0, buf;
    while (cin >> buf) {
        stack.Push(buf);
    }

    int size = stack.Size();
    if (size < (pos1 + 1) || size < (pos2 + 1)) {
        cout << "Недостаточно элементов.\n";
        return 0;
    }
    if (fromStart) {
        int curPos = size - 1;
        double num1 = -1.0, num2 = -1.0;
        while (!stack.Empty() && (num1 == -1.0 || num2 == -1.0)) {
            if (curPos == pos1)
                num1 = stack.Top();
            else if (curPos == pos2)
                num2 = stack.Top();
            --curPos;
            stack.Pop();
        }
        if (num1 != -1.0 && num2 != -1.0)
            stack.Push((num1 + num2) / 2.0);
    }
    else {
        int curPos = 0;
        double num1 = -1.0, num2 = -1.0;
        while (!stack.Empty() && (num1 == -1.0 || num2 == -1.0)) {
            if (curPos == pos1)
                num1 = stack.Top();
            else if (curPos == pos2)
                num2 = stack.Top();
            ++curPos;
            stack.Pop();
        }
        if (num1 != -1.0 && num2 != -1.0)
            stack.Push((num1 + num2) / 2.0);

    }

    for (auto item : stack) {
        cout << item << ' ';
    }
    

    
    cout << '\n';
}
