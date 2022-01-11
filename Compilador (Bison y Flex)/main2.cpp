#include <iostream>
#include <fstream>
#include "Driver.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    Driver driver;
    if (argc == 2) {
        driver.parse(argv[1]);
    }
    else {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}