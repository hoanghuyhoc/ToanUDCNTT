#include <iostream>
#include <conio.h>
#include <math.h>

int EstimatedDensityOfPrime(int n)
{
    return n / log(n);
}

int main()
{
    int n;
    std::cout << "Nhap n: ";
    std::cin >> n;
    while (n <= 1)
    {
        std::cout << "n phai lon hon 1. Nhap lai n: ";
        std::cin >> n;
    }
    std::cout << "Mat do so nguyen to trong khoang (1, n) xap xi: " << EstimatedDensityOfPrime(n);
    return 0;
}