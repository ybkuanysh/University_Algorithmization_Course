#include <iostream>
#include <math.h>

int main() {

    double x, y;
    std::cout << "Please enter X and Y coordinates\n";
    std::cin >> x >> y;
    
    if ((abs(x) - abs(y)) <= 0 && y < 1 && y > -1)
    {
        std::cout << "true";
    }
    else 
    {
        std::cout << "false";
    }
    
    return 0;
}