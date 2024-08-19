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

int SumOfFactors(std::vector<int> PrimeFactors, std::vector<int> Exponents)
{
    int SumOfFactors = 1;
    for (int i = 0; i < PrimeFactors.size(); i++)
    {
        SumOfFactors *= (pow(PrimeFactors[i], Exponents[i] + 1) - 1) / (PrimeFactors[i] - 1);
    }
    return SumOfFactors;
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
    std::vector<int> PrimeFactors, Exponents;
    if (n > 1)
    {
        std::vector<int> *result = PrimeFactorize(n);
        PrimeFactors = result[0];
        Exponents = result[1];
    }

    int Sum = SumOfFactors(PrimeFactors, Exponents);
    std::cout << "Tong cac uoc cua " << n << " la: " << Sum;
    return 0;
}