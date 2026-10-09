#include "matrix.hpp"

#include <cmath>
#include <iostream>
#include <stdexcept>
#include <string>

bool close(double lhs, double rhs, double tolerance = 1e-9)
{
    return std::abs(lhs - rhs) <= tolerance;
}

void check(bool condition, const std::string& label)
{
    std::cout << label << ": " << (condition ? "PASS" : "FAIL") << '\n';
}

int main()
{
    const Matrix a({{1.0, 2.0}, {3.0, 4.0}});
    const Matrix b({{2.0, 0.0}, {1.0, 2.0}});

    const Matrix sum = a + b;
    check(close(sum.at(0, 0), 3.0) && close(sum.at(0, 1), 2.0)
              && close(sum.at(1, 0), 4.0) && close(sum.at(1, 1), 6.0),
          "matrix addition");

    const Matrix product = a * b;
    check(close(product.at(0, 0), 4.0) && close(product.at(0, 1), 4.0)
              && close(product.at(1, 0), 10.0) && close(product.at(1, 1), 8.0),
          "matrix multiplication");

    std::cout << "Matrix a:\n" << a;

    // TODO: Add at least one addition test, one multiplication test,
    std::cout << "additional matrix addition test"  << std::endl;
    const Matrix A1({{1.0,3.0},{5.0,7.0}});
    const Matrix B1({{8.0,6.0},{9.0,7.4}});
    const Matrix C = A1 + B1;
        // A*B = {{9.0,9.0},{14.0,14.4}}
    check(close(C.at(0, 0), 9.0) && close(C.at(0, 1), 9.0) &&
            close(C.at(1, 0), 14.0) && close(C.at(1, 1), 14.4), "additional matrix addition test");
    std::cout << "A1+B1 result:\n" << C;
    std::cout << "additional matrix multiplication test"  << std::endl;
    const Matrix A2({{1.0,2.0},{3.0,4.0}});
    const Matrix B2({{5.0,6.0},{7.0,8.0}});
    const Matrix D = A2 * B2;
        // A*B = {{19.0,22.0},{43.0,50.0}}
    check(close(D.at(0, 0), 19.0) && close(D.at(0, 1), 22.0) &&
            close(D.at(1, 0), 43.0) && close(D.at(1, 1), 50.0), "additional matrix multiplication test");
    std::cout << "A2*B2 result:\n" << D;
    // and one invalid-dimension test.
    bool flag1=false;
    try
    {
        const Matrix A3({{1.7,4,5},{6.3,8.4}});
        const Matrix B3({{4.7,3.2}});
        const Matrix U=A3+B3;
        
    }
    catch(const std::invalid_argument&)
        {
            flag1 = true;
        }
    check(flag1, "wrong dimension flag1 exception for matrix addition");
    bool flag2=false;
    try
    {
        const Matrix A4({{1.7,4,5},{6.3,8.4}});
        const Matrix B4({{4.7,3.2}});
        const Matrix bad=A4+B4;
    }
    catch(const std::invalid_argument&)
        {
            flag2 = true;
        }
    check(flag2, "wrong dimension flag2 exception for matrix multiplication");
    return 0;
}
