#include<iostream>
#include<cmath>

int main() {

    double x = 0, y = 0;
    std::cout << "Please enter X and Y coordinates to continue\n";
    std::cin >> x >> y;

    if (
        1 - fabs(x - 1) - fabs(y - 1) >= 0
    )
    {
        std::cout << "True";
    } else {
        std::cout << "False";
    }
    
    return 0;
}