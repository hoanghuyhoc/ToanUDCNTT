#include <iostream>
#include <vector>
#include <iomanip>

std::vector<int> SieveOfEratosthenes(int n, long long &sum, double &product)
{
    sum = 0;
    product = 1;
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
            product *= i;
            prime.push_back(i);
        }
    }

    return prime;
}

int main()
{
    int n;
    long long sum = 0;
    double product = 1;
    std::cout << "Nhap n: ";
    std::cin >> n;
    std::cout << "Cac so nguyen to <= " << n << " la: ";
    std::vector<int> sieve = SieveOfEratosthenes(n, sum, product);
    for (int i = 0; i < sieve.size(); i++)
    {
        std::cout << sieve[i] << " ";
    }
    std::cout << "\nTong cac so nguyen to <= " << n << " la: " << sum;
    std::cout << "\nTich cac so nguyen to <= " << n << " la: " << std::fixed << std::setprecision(0) << product;
    return 0;
}