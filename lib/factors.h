#include <vector>
#include <math.h>
#include "quicksort.h"

int NumOfFactors(std::vector<int> Exponents)
{
    int NumOfFactors = 1;
    for (int i = 0; i < Exponents.size(); i++)
    {
        NumOfFactors *= Exponents[i] + 1;
    }
    return NumOfFactors;
}
int *ListOfFactors(int FactorCount, std::vector<int> PrimeFactors, std::vector<int> Exponents)
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
    quicksort(factors, 0, FactorCount - 1);
    return factors;
}

int SumOfFactors(std::vector<int> PrimeFactors, std::vector<int> Exponents)
{
    int SumOfFactors = 1;
    for (int i = 0; i < PrimeFactors.size(); i++)
    {
        SumOfFactors *= (pow(PrimeFactors[i], Exponents[i] + 1) - 1) / (PrimeFactors[i] - 1);
    }
    return SumOfFactors;
}