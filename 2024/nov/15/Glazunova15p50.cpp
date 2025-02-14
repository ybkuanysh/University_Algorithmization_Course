#include<iostream>
#include<cmath>

int main() {

    int n = 9;
    int x = 2;
    double result = x;
    
    double sum = 0;

    for(int i = 3; i <= n; i += 2) {

        // Вывод каждого элемента для дебага
        // std::cout << "res on i(" << i << ") is " << result * (-1) * powf(x, 2) 
        //     * (i - 4) / i << "\n";

        result *= -1 * powf(x, 2) * (i - 4) / i;
        
        sum += result;
    }

    std::cout << "\n" << "Sum: " << sum << "\n";

    return 0;
}