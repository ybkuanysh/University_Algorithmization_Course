#include <iostream>

int main()
{
    int factK = 1;
    double result = 1;
    double oldRes = 0;
    int x = 2;

    int n = 5;

    std::cout << "start" << "\n";
    for (int i = 1; i <= n; i = i * 2 + 1)
    {
        result += oldRes * (-1) * x * x / (i * (i - 1));
        oldRes = result;
        std::cout << i << "\n";
    }
    return 0;
}