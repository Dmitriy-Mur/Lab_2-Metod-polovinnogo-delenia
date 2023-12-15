#include <iostream>
#include <cmath>
using namespace std;

double equation(double x)
{
    return x - 2 + sin(1 / x);
}

int main()
{
    double a, b, x;
    double eps = 0;
    setlocale(LC_ALL, "Rus");
    cout << "Для решения уравнения y = x - 2 + sin(1/x) = 0 (ожидаемый ответ: 1,3077),\nведите пераметры интервала a и b (рекомендуем 1 и 2!): ";
    cin >> a >> b;
    while ((eps == 0) or (eps >= abs(a - b))) {
        cout << "Введите значение эпсилон(0 < eps < " << abs(a - b) << "): ";
        cin >> eps;
    }
    bool flag = true;
    while ((abs(a - b) > eps) and flag){
        x = (a + b) / 2;
        if (equation(x) * equation(a) < 0)
            b = x;
        else if (equation(x) * equation(b) < 0)
            a = x;
        else {
            cout << "Нет решений на заданном промежутке" << '\n';
            flag = false;
        }
    }
    if (flag)
        cout << "Корень фунции равен: " << x << '\n';
}