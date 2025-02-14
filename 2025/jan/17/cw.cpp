#include<iostream>

int main() {
    
    int counter = 0;

    for (int i = 100; i <= 500; i++) {
        if (i/100 + i%100/10 + i%10 == 15) {
            counter++;
            std::cout << i << "\n";
        }
    }

    std::cout << counter;
    return 0;
}