#include <iostream>
#include <math.h>

int main() {
    double x, y;
    std::cout << "Please enter X and Y coordinates\n";
    std::cin >> x >> y;

    if ( (pow(x, 2) + pow(y, 2) <= 1) 
        && (pow(x - 2, 2) + pow(y, 2) <= 4))
    {
        std::cout << "True\n";
    } else {
        std::cout << "False\n";
    }
    
    
    (pow(x, 2) + pow(y, 2) <= 1) && (pow(x - 2, 2) + pow(y, 2) <= 4) ? std::cout<<"true\n" : std::cout<<"false\n";

    return 0;
}