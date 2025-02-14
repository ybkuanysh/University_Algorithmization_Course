#include<iostream>
#include<cmath>

int main() {
    double product = 1.0;

    for(double i = 0.1; i <= 10; i += 0.1) {
        product *= (1 + sin(i));
    }

    std::cout << product << "\n";
    return 0;
}