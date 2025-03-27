//
// Created by ybkuanysh on 2025/03/27.
//
#include <iostream>

std::string toOctal(int num) {
    std::string result;
    while (num > 0) {
        result = std::to_string(num % 8) + result; // ������塞 ���⮪
        num /= 8;
    }
    return result.empty() ? "0" : result;
}

int main() {
    int num = 100;
    std::cout << "���쬥�筮�: " << toOctal(num) << std::endl;
    return 0;
}
