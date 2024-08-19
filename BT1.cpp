#include <iostream>
#include <string>
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
        if (CheckPrime(i)) // i is a prime number
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

int main()
{
    int A, *count;
    printf("Nhap mot so: ");
    scanf("%d", &A);
    while (A < 2)
    {
        printf("n phai lon hon hoac bang 2. Nhap lai: ");
        scanf("%d", &A);
    }
    std::vector<int> *Result = PrimeFactorize(A);
    std::vector<int> PrimeFactors = Result[0];
    std::vector<int> Exponents = Result[1];

    printf("Phan tich thua so nguyen to: %d = ", A);
    for (int i = 0; i < PrimeFactors.size(); i++)
    {
        std::string exponent = Exponents[i] > 1 ? "^" + std::to_string(Exponents[i]) : "";

        std::cout << PrimeFactors[i] << exponent;
        if (i < PrimeFactors.size() - 1)
        {
            printf(" * ");
        }
    }
    return 0;
}