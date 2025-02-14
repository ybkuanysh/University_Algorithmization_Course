#include<iostream>
#include<cmath>

int main() {
    double x = 2.0;
    double a = 1.0;
    int n = 5;

    double result = x + a;

    for(int i = 0; i < n; i++) {
        result = powf(result, 2) + a;
    }

    std::cout << result << "\n";

    return 0;
}