#include<iostream>
#include<cmath>

int main() {

    // Exercise 79 Abramov
    {
        double sum = 1.0;

        for (double i = 0.1; i <= 10; i+=0.1) {
            sum *= 1 + sinf(i);
        }

        std::cout << sum;
    }

    return 0;
}