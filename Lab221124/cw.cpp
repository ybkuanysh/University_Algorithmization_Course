// p44 15b,30b, 15m, 30m
#include <iostream>
#include <cmath>

using namespace std;
int Exercise_15m();

int main()
{

    {
        cout << "Exercise 15b started\n"
             << "output:";

        int n = 24;
        bool isSimpleFlag = false;

        int i = 1, j;
        while (n > i)
        {
            isSimpleFlag = true;
            j = 2;
            while (i >= j)
            {
                if (i % j == 0 && n % j == 0)
                {
                    isSimpleFlag = false;
                    break;
                }
                j++;
            }
            if (isSimpleFlag)
                cout << " " << i;
            i++;
        }

        cout << "\n";
    }

    {
        cout << "Exercise 30b started\n"
             << "output:";

        int m = 11, n = 15, sum = 0;

        while (m <= n)
        {
            if (m % 2 != 0)
                sum += pow(m, 2);
            m++;
        }

        cout << " Sum: " << sum << "\n";
    }

    {
        Exercise_15m();
    }

    {
        cout << "Exercise 30m started\n" << "output: ";

        int n = 0, m = 47;

        while (n < 99) {
            if(pow(n, 2) > m) {
                cout << "n: " << n << "\n";
                break;
            }
            n++;
        }
    }
    return 0;
}

// Здесь все для задания 15 из среднего уровня.
bool isNumLucky(int n)
{
    return (
    n / 100000 
    + n % 100000 / 10000 
    + n % 10000 / 1000 
    == 
    n % 1000 / 100 
    + n % 100 / 10 
    + n % 10 
    && 
    n % 1000 / 100 
    + n % 100 / 10 
    + n % 10 
    == 
    13
    );
}

int Exercise_15m()
{
        cout << "Exercise 15m started\n" << "output:";

        int i = 49048, sum = 0;
        /*
            Число 49048 ровно на 1 меньше,
            чем первое счастливое число с 
            суммой цифр равной 13
        */
        while (i <= 999999)
        {
            if (isNumLucky(i)) sum++;
            i++;
        }

        cout << " Sum: " << sum << "\n";

        return 0;
}