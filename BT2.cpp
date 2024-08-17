#include <iostream>
#include <conio.h>
#include "lib/prime.h"
#include "lib/factors.h"

using namespace std;

int main()
{
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    vector<int> *result = PrimeFactorize(n);
    vector<int> PrimeFactors = result[0];
    vector<int> Exponents = result[1];
    int FactorCount = NumOfFactors(Exponents);
    int *Factors = ListOfFactors(FactorCount, PrimeFactors, Exponents);
    printf("So uoc cua %d la: %d\n", n, FactorCount);
    cout << "Cac uoc cua " << n << " la: ";
    for (int i = 0; i < FactorCount; i++)
    {
        cout << Factors[i] << ((i < FactorCount - 1) ? ", " : "");
    }
    getch();
    return 0;
}