#include<iostream>

using namespace std;

int main() {

    int count = 1; // любое натуральное число делится само на себя

    for(int i = 1; i <= 1000; i++) {
        
        for(int j = 1; j <= i/2; j++) {
            if(i % j == 0) {
                count++;
            }
        }

        if(count == 5) {
            cout << "This number has 5 dividers: i = " << i << "\n";
        }

        count = 1; // Возвращаем первоначальное значение

    }

    return 0;
}