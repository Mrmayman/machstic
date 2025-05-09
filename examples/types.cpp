#include "../machstic.hpp"

#include <iostream>

int main() {
    std::variant<int, float> number = (int)69;

    match(number,
        [](const int& integer) {
            std::cout << "Integer: " << integer << std::endl;
        },
        [](const float& float_num) {
            std::cout << "Float: " << float_num << std::endl;
        }
    );

    return 0;
}
