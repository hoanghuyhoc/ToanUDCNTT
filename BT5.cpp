#include <iostream>
#include <conio.h>
#include "lib/prime.h"
#include "lib/factors.h"

using namespace std;

bool IsPerfectNumberUsingSum(int n)
{
    vector<int> *result = PrimeFactorize(n);
    vector<int> PrimeFactors = result[0];
    vector<int> Exponents = result[1];
    int FactorCount = NumOfFactors(Exponents);
    int *Factors = ListOfFactors(FactorCount, PrimeFactors, Exponents);
    int Sum = 0;
    for (int i = 0; i < FactorCount - 1; i++)
    {
        Sum += Factors[i];
    }
    return Sum == n;
}
bool IsPerfectNumberUsingFunc(int n)
{
    vector<int> *result = PrimeFactorize(n);
    vector<int> PrimeFactors = result[0];
    vector<int> Exponents = result[1];
    int FactorCount = NumOfFactors(Exponents);
    int *Factors = ListOfFactors(FactorCount, PrimeFactors, Exponents);
    return SumOfFactors(PrimeFactors, Exponents) == 2*n;
}

int main()
{
    int n;
    cout << "Nhap n ( n>10^6 ): ";
    cin >> n;
    cout << "Cach 1: Kiem tra tong cac uoc so nho hon n.\n";
    if (IsPerfectNumberUsingSum(n))
    {
        cout << n << " la so hoan hao";
    }
    else
    {
        cout << n << " khong phai la so hoan hao";
    }
    cout << "\nCach 2: Kiem tra bang phuong trinh.\n";
    if (IsPerfectNumberUsingFunc(n))
    {
        cout << n << " la so hoan hao";
    }
    else
    {
        cout << n << " khong phai la so hoan hao";
    }
    getch();
    return 0;
}