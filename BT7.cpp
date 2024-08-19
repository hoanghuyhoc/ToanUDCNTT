#include <iostream>
#include <vector>

std::vector<int> SieveOfEratosthenes(int n, long long &sum)
{
    std::vector<int> prime;
    int *sieve = new int[n + 1]{0};

    for (int i = 2; i <= n; i++)
    {
        if (sieve[i] == 0)
        {
            for (int j = i * i; j <= n; j += i)
            {
                sieve[j] = i;
            }
            sum += i;
            prime.push_back(i);
        }
    }

    return prime;
}

int main()
{
    int n;
    long long sum = 0;
    long long product = 1;
    std::cout << "Nhap n: ";
    std::cin >> n;
    std::cout << "Cac so nguyen to <= " << n << " la: ";
    std::vector<int> sieve = SieveOfEratosthenes(n, sum);
    for (int i = 0; i < sieve.size(); i++)
    {
        std::cout << sieve[i] << " ";
    }
    std::cout << "\nTong cac so nguyen to <= " << n << " la: " << sum;
    return 0;
}