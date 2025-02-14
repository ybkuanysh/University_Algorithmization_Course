#include<iostream>

using namespace std;

int main() {

    // По условию: надо определить входит ли точка указанная пользователем 
    //             в область пересечения двух равносторонних ромбов

    double x = 0.0, y = 0.0;

    cout << "Please enter X and Y coordinates to continue\n";
    cin >> x >> y;

    if ( (1 - abs(x-1) - abs(y) >= 0)
                && (1 - abs(x) - abs(y) >= 0)
    )
    {
        cout << "True";
    } else {
        cout << "False";
    }

    return 0;
}