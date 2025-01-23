#include <iostream>
#include <cmath>

using namespace std;

int main()
{

    int k, factorial = 0;
    double result = 1.0, x;

    cin >> k;

    for (int n = -3; n <= k; n++)
    {
        factorial *= n + 3;
        x = (double) ((n + 2) * abs(n - 4)) / factorial;
        if (x != 0.0 && !isnan(x) && !isinf(x)) {
            result *= x;
            cout << "n: " << n << "   x: " << x << "   f: " << factorial << endl;
            cout << "result: " << result << endl;
        }
        if (factorial == 0) factorial = 1;
    }

    cout << result << endl;

    return 0;
}