#include <iostream>
#include <optional>
#include <iomanip>
#include <locale.h>
#include "Stack.h"

using namespace std;

/*  Условие задачи
17.	Сформировать стек из N чисел. Найти среднее арифметическое второго и третьего чисел. Результат поместить в стек.
*/

static void addMeanValue(Stack<double>& stack, const size_t index1, const size_t index2, const bool fromStart) {
    size_t curPos, step;
    if (fromStart) {
        curPos = stack.size() - 1;
        step = -1;
    }
    else {
        curPos = 0;
        step = 1;
    }

    optional<double> num1 = {}, num2 = {};
    for (; !stack.empty() && (!num1.has_value() || !num2.has_value()); curPos += step) {
        if (curPos == index1)
            num1 = stack.top();
        else if (curPos == index2)
            num2 = stack.top();
        stack.pop();
    }
    if (num1.has_value() && num2.has_value()) {
        stack.push((num1.value() + num2.value()) / 2);
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    Stack<double> stack;
    const size_t index1 = 1, index2 = 2;
    const bool fromStart = true;

    
    double buf;
    while (cin >> buf) {
        stack.push(buf);
    }

    size_t size = stack.size();
    if (size < (index1 + 1) || size < (index2 + 1)) {
        cout << "Недостаточно элементов.\n";
        return 0;
    }

    addMeanValue(stack, index1, index2, fromStart);

    for (auto item : stack) {
        cout << setprecision(12) << item << ' ';
    }
    
    cout << '\n';
}
