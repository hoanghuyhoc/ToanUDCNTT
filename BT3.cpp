#include <iostream>
#include <conio.h>
#include <math.h>
#include "lib/prime.h"
#include "lib/factors.h"

using namespace std;

int main()
{
    int n;
    std::cout << "Nhap n: ";
    std::cin >> n;
    std::vector<int> *result = PrimeFactorize(n);
    std::vector<int> PrimeFactors = result[0];
    std::vector<int> Exponents = result[1];
    int Sum = SumOfFactors(PrimeFactors, Exponents);
    std::cout << "Tong cac uoc cua " << n << " la: " << Sum;
    getch();
    return 0;
}