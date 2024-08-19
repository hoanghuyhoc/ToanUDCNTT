#include <iostream>
#include <math.h>
#include <vector>

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
long long ProductOfFactors(int n, int NumOfFactors)
{
    return (long long)pow(n, NumOfFactors / 2);
}

int main()
{
    int n;
    std::cout << "Nhap n: ";
    std::cin >> n;
    while (n <= 0)
    {
        std::cout << "n phai lon hon 0. Nhap lai: ";
        std::cin >> n;
    }
    std::vector<int> Exponents;
    if (n > 1)
    {
        std::vector<int> *result = PrimeFactorize(n);
        Exponents = result[1];
    }
    
    int FactorCount = NumOfFactors(Exponents);
    long long Product = ProductOfFactors(n, FactorCount);
    std::cout << "Tich cac uoc so cua " << n << " la: " << Product;
    return 0;
}