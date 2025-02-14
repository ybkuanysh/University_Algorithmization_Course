#include "iostream"

using namespace std;

int main() {

    double x, y;
    cout << "Please enter X and Y coordinates:" << endl;
    cin >> x >> y;

    if ((x >= -1.0 & x <= 1.0 & y >= -1.0 & y <= 0.0)
        || (x * x + y * y <= 1)) {
        cout << "True";
    } else cout << "False";

    return 0;
}


