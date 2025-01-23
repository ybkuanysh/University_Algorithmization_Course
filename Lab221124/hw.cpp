#include <iostream>
#include <cmath>

using namespace std;

int main()
{

    // Glazunova ex7
    {
        double x = 2, result = x, last = 1;
        int n = 10;

        for (int i = 1; i <= n; i++)
        {
            last = last * (-1) * powf(x, 2) / (2 * i * (2 * i - 1));
            result += last;
        }

        cout << "Result: " << result << "\n\n";
    }

    // Glazunova ex9
    {
        double x = 2, result = 0, last = x;
        int n = 21;

        for (int i = 5; i <= n; i += 4)
        {
            result += last;
            last = last * powf(x, 4) / (i * (i - 1) * (i - 2) * (i - 3));
        }

        cout << "Result: " << result << "\n\n";
    }

    // Glazunova ex11
    {
        double x = 2, result = 0, last = 1;
        int n = 10;

        for (int i = 1; i <= n; i++)
        {
            result += last;
            last = last * powf(x, 2) / i * (i * 2 + 1) / (i * 2 - 1);
        }

        cout << "Result: " << result << "\n\n";
    }

    // Glazunova ex13
    {
        double x = 2, result = 0, last = (x - 1) / (x + 1);
        int n = 10;

        for (int i = 3; i <= n; i += 2)
        {
            result += last;
            last = last * (i - 2) * powf((x - 1) / (x + 1), 2) / i;
        }

        cout << "Result: " << result << "\n\n";
    }
    // Glazunova ex17
    {
        double x = 2, result = 0, last = 1;
        int n = 10;

        for (int i = 1; i <= n; i++)
        {
            result += last;
            last = last * powf(x, 2) / (2 * i * (2 * i - 1));
        }

        cout << "Result: " << result << "\n\n";
    }

    // Glazunova ex19
    {
        double x = 2, result = 0, last = 1;
        int n = 10;

        for (int i = 1; i <= n; i++)
        {
            result += last;
            last = last * 2 * x / i;
        }

        cout << "Result: " << result << "\n\n";
    }
    return 0;
}