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
    std::cout << "Mat do so nguyen to tu 1 den " << n << " xap xi: " << EstimatedDensityOfPrime(n);
    getch();
    return 0;
}