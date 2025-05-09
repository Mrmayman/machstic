#include "../machstic.hpp"

#include <iostream>
#include <string>

struct IoError {
    std::string message;
    std::string path;
};

struct NetworkError {
    std::string message;
};

struct InvalidInput {
    std::string input;
};

int main() {
    std::variant<IoError, NetworkError, InvalidInput> error = IoError{"Failed to read file", "/path/to/file"};

    std::cout << "Before mutation:\n";
    match(error,
        [](const IoError& err) {
            std::cout << "Io error: " << err.message << " at path " << err.path << std::endl;
        },
        [](const NetworkError& err) {
            std::cout << "Network error: " << err.message << std::endl;
        },
        [](const InvalidInput& err) {
            std::cout << "Invalid Input: " << err.input << std::endl;
        }
    );

    // Mutate the variant
    match_mut(error,
        [](IoError& err) {
            err.message = "Updated: Could not open file";
            err.path = "/new/path/to/file";
        },
        [](NetworkError& err) {
            err.message = "Updated: Network timeout";
        },
        [](InvalidInput& err) {
            err.input = "Updated invalid input";
        }
    );

    std::cout << "\nAfter mutation:\n";
    match(error,
        [](const IoError& err) {
            std::cout << "Io error: " << err.message << " at path " << err.path << std::endl;
        },
        [](const NetworkError& err) {
            std::cout << "Network error: " << err.message << std::endl;
        },
        [](const InvalidInput& err) {
            std::cout << "Invalid Input: " << err.input << std::endl;
        }
    );

    return 0;
}
