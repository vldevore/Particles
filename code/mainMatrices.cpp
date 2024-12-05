#include <iostream>
#include "Matrices.h"

using namespace Matrices;

int main()
{
    Matrix A(2, 2);
    A(0, 0) = 0;
    A(0, 1) = -1;
    A(1, 0) = 1;
    A(1, 1) = 0;

    std::cout << "a: " << std::endl;
    std::cout << A << std::endl;

    A(0, 0) = 0;
    A(0, 1) = -1;
    A(1, 0) = 1;
    A(1, 1) = 0;

    Matrix B(2, 4);
    B(0, 0) = 1;
}
