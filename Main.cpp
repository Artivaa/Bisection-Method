#include <iostream>
#include <cmath>
#include <chrono>
#include <locale>

using namespace std;

double function(double x) 
{
    return x - 1.0 / (3 + sin(3.6 * x));
}

int main() 
{
    setlocale(LC_ALL, "Rus");
    double a = 0.0;
    double b = 0.85;
    double epsilon = 0.00001;
    double x;
    int iteration = 0;

    if (function(a) * function(b) >= 0) 
    {
        cout << "Нет корней на данном интервале или метод неприменим." << endl;
        return 1;
    }

    auto start = chrono::high_resolution_clock::now();

    bool found = false; 
    while ((b - a) / 2 > epsilon && !found) 
    { 
        x = (a + b) / 2; 
        iteration++; 
        cout << "Итерация " << iteration << ": x = " << x << endl; 
        if (function(x) == 0.0) 
        { 
            found = true;
        } 
        else if (function(x) * function(a) < 0) 
        { 
            b = x; 
        } 
        else 
        { 
            a = x; 
        } 
    }

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();

    x = (a + b) / 2;

    cout << "Количество итераций: " << iteration << endl;
    cout << "Корень: " << x << endl;
    cout << "Затраченое время: " << duration << " микросекунд" << endl;

    return 0;
}
