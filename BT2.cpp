#include <iostream>
#include <math.h>
#include <conio.h>
#include "lib/prime.h"
#include "lib/quicksort.h"

using namespace std;

int NumOfFactors(vector<int> Exponents)
{
    int NumOfFactors = 1;
    for (int i = 0; i < Exponents.size(); i++)
    {
        NumOfFactors *= Exponents[i] + 1;
    }
    return NumOfFactors;
}
int *ListOfFactors(int FactorCount, vector<int> PrimeFactors, vector<int> Exponents)
{
    int *factors = new int[FactorCount];
    factors[0] = 1;
    int i = 1;
    int temp[Exponents.size()]{0};

    while (i < FactorCount)
    {
        int factor = 1, j = Exponents.size() - 1;

        while (temp[j] == Exponents[j])
        {
            temp[j] = 0;
            j--;
        }
        temp[j]++;
        for (int k = 0; k < Exponents.size(); k++)
        {
            factor *= (int)pow(PrimeFactors[k], temp[k]);
        }
        factors[i] = factor;
        i++;
    }
    quicksort(factors, 0, FactorCount-1);
    return factors;
}
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