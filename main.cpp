#include <iostream>

#include "fiblib.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Must input number between 1 and 92.";
        return EXIT_FAILURE;
    }

    char *ptr = nullptr;
    uint32_t input = strtol(argv[1], &ptr, 10);

    //  If not pointing to null, conversion failed
    if (*ptr != '\0') {
        std::cout << "Could not convert argument to integer.";
        return EXIT_FAILURE;
    }

    if (input < 1 || input > 92) {
        std::cout << "Input is out of range.";
    }

    std::cout << FibLib::get(input);

    return EXIT_SUCCESS;
}