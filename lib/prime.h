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