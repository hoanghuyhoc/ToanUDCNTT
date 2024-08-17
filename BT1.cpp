#include <iostream>
#include <conio.h>
#include <string>
#include "lib/prime.h"

int main()
{
    int A, *count;
    printf("Nhap mot so: ");
    scanf("%d", &A);
    std::vector<int> *Result = PrimeFactorize(A);
    std::vector<int> PrimeFactors = Result[0];
    std::vector<int> Exponents = Result[1];
    
    printf("Cac thua so nguyen to cua %d la: ", A);
    for (int i = 0; i < PrimeFactors.size(); i++)
    {
        std::string exponent = Exponents[i] > 1 ? "^" + std::to_string(Exponents[i]) : "";
        
        std::cout<<PrimeFactors[i]<<exponent;
        if (i < PrimeFactors.size() - 1)
        {
            printf(" * ");
        }
    }
    getch();
    return 0;
}