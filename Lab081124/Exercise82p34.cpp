#include<iostream>

int main() {
    double numerator = 1.0;
    double denominator = 1.0;
    double x = 65.0;

    for(int i = 2; i <= 64; i *= 2) {
        numerator *= (x - i);
    }

    for(int i = 2; i - 1 <= 63; i *= 2) {
        denominator *= (x - (i - 1));
    }

    std::cout << "answer = " << numerator / denominator;
    return 0;
}