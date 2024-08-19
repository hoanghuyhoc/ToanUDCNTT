#include <iostream>
#include <vector>
#include <iomanip>

std::vector<int> SieveOfEratosthenes(int m, int n, long long &sum, double &product)
{
    sum = 0;
    product = 1;
    std::vector<int> prime;
    int *sieve = new int[n + 1]{0};

    for (int i = 2; i < m; i++)
    {
        if (sieve[i] == 0)
        {
            for (int j = i * i; j <= n; j += i)
            {
                sieve[j] = i;
            }
        }
    }
    for (int i = m; i <= n; i++)
    {
        if (sieve[i] == 0)
        {
            for (int j = i * i; j <= n; j += i)
            {
                sieve[j] = i;
            }
            sum += i;
            product *= i;
            prime.push_back(i);
        }
    }

    return prime;
}

int main()
{
    int m, n;
    long long sum = 0;
    double product = 1;
    std::cout << "Cac so nguyen to trong doan [m, n] (m>2)\n";
    std::cout << "Nhap m: ";
    std::cin >> m;
    std::cout << "Nhap n: ";
    std::cin >> n;

    std::cout << "Cac so nguyen to trong doan [" << m << ", " << n << "] la: ";
    std::vector<int> sieve = SieveOfEratosthenes(m, n, sum, product);
    for (int i = 0; i < sieve.size(); i++)
    {
        std::cout << sieve[i] << " ";
    }
    std::cout << "\nTong cac so nguyen to trong doan [" << m << ", " << n << "] la: " << sum;
    std::cout << "\nTich cac so nguyen to trong doan [" << m << ", " << n << "] la: " << std::fixed << std::setprecision(0) << product;
    return 0;
}