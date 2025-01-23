#include <iostream>
#include <cmath>

int main()
{
    { // 78 A
        std::cout << "78 А: ";
        double a = 2.0;
        int n = 5;

        double result = 1;

        for (int i = 0; i < n; i++)
        {
            result *= a;
        }
        std::cout << result << "\n";
    }

    { // 78 Б
        std::cout << "78 Б: ";
        double a = 2.0;
        int n = 5;

        double result = a;

        for (int i = 0; i < n; i++)
        {
            result *= (a + i);
        }

        std::cout << result << "\n";
    }

    { // 78 В
        std::cout << "78 В: ";
        double a = 2.0;
        int n = 5;

        double result = a;

        for (int i = 0; i < n; i++)
        {
            double term = 1;
            for (int j = 0; j <= i; j++)
            {
                term *= (a + j);
            }
            result += 1 / term;
        }

        std::cout << result << "\n";
    }

    { // 78 Г
        std::cout << "78 Г: ";
        double sum = 0;

        int n = 2;
        double a = 2.0;

        for (int i = 0; i <= n; i++)
        {
            sum += 1 / powf(a, pow(2, i));
        }

        std::cout << "sum = " << sum << "\n";
    }

    { // 78 Д
        std::cout << "78 Д: ";
        double a = 2.0;
        int n = 5;

        double result = a;

        for(int i = 1; i <= n; i++) {
            result *= (a - i * n);
        }

        std::cout << result << "\n";
    }
    return 0;
}