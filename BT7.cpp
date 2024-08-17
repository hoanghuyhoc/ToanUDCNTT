#include <iostream>
#include <conio.h>

int* SieveOfEratosthenes(int n)
{
    int *sieve = new int[n + 1]{0};
    for (int i = 2; i <= n; i++)
    {
        if (sieve[i] == 0)
        {
            for (int j = i * i; j <= n; j += i)
            {
                sieve[j] = i;
            }
        }
    }
    return sieve;
}

int main()
{
    int n;
    std::cout << "Nhap n: ";
    std::cin >> n;
    std::cout << "Cac so nguyen to nho hon " << n << " la: ";
    int *sieve = SieveOfEratosthenes(n);
    for (int i = 2; i <= n; i++)
    {
        if (sieve[i] == 0)
        {
            std::cout << i << " ";
        }
    }
    delete[] sieve;
    getch();
    return 0;
}