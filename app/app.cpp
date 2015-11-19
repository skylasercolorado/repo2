#include "PrimeChecker.hpp"
#include <iostream>

using namespace Camax;
using namespace std;

int main()
{
  PrimeChecker primeChecker;
  int n = 1;

  while(n != 0)
    {
      cout << "\n\n\n\tCamila, enter a number: ";
      cin >> n;

      primeChecker.IsPrime(n);
    }
  
  return 0;
}
