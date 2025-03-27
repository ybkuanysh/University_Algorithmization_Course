//
// Created by ybkuanysh on 2025/03/27.
//
#include <iostream>
#include <math.h>

double first_cosmic_speed(double M, double R);

int main() {
    const double M_v = 4.86e27;
    const double R_v = 6175.0;
    const double M_z = 5.98e27;
    const double R_z = 6371.0;

    const double V_v = first_cosmic_speed(M_v, R_v);
    std::cout << "Первая космическая скорость Венеры: " << V_v << std::endl;
    const double V_z = first_cosmic_speed(M_z, R_z);
    std::cout << "Первая космическая скорость Земли: " << V_z << std::endl;

    return 0;
}

double first_cosmic_speed(const double M, const double R) {
    const double G = 6.673e-11;
    return sqrt(G*M/R);
}
