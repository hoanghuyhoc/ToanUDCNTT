#include <iostream>
#include <conio.h>
#include <math.h>
#include "lib/prime.h"
#include "lib/factors.h"

using namespace std;

long long ProductOfFactors(int n, int NumOfFactors)
{
    return (long long)pow(n, NumOfFactors / 2);
}

int main()
{
    int n;
    std::cout << "Nhap n: ";
    std::cin >> n;
    vector<int> *result = PrimeFactorize(n);
    vector<int> PrimeFactors = result[0];
    vector<int> Exponents = result[1];
    int FactorCount = NumOfFactors(Exponents);
    long long Product = ProductOfFactors(n, FactorCount);
    std::cout << "Tich cac uoc so cua " << n << " la: " << Product;
    getch();
    return 0;
}