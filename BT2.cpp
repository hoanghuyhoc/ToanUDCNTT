#include <iostream>
#include <vector>
#include <math.h>

bool CheckPrime(int n)
{
    if (n <= 1)
    {
        return false;
    }

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

std::vector<int> *PrimeFactorize(int A)
{
    std::vector<int> PrimeFactors, Exponents;
    for (int i = 2; i <= A; i++)
    {
        if (CheckPrime(i))
        {
            if (A % i == 0)
            {
                int count = 0;
                while (A % i == 0)
                {
                    A /= i;
                    count++;
                }
                PrimeFactors.push_back(i);
                Exponents.push_back(count);
            }
        }
    }
    std::vector<int> *result = new std::vector<int>[2];
    result[0] = PrimeFactors;
    result[1] = Exponents;
    return result;
}

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
    return factors;
}

int main()
{
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    while (n <= 0)
    {
        printf("n phai lon hon 0. Nhap lai: ");
        scanf("%d", &n);
    }
    std::vector<int> PrimeFactors, Exponents;
    if (n > 1)
    {
        std::vector<int> *result = PrimeFactorize(n);
        PrimeFactors = result[0];
        Exponents = result[1];
    }
    int FactorCount = NumOfFactors(Exponents);
    int *Factors = ListOfFactors(FactorCount, PrimeFactors, Exponents);
    printf("So uoc cua %d la: %d\n", n, FactorCount);
    std::cout << "Cac uoc cua " << n << " la: ";
    for (int i = 0; i < FactorCount; i++)
    {
        std::cout << Factors[i] << ((i < FactorCount - 1) ? ", " : "");
    }
    return 0;
}