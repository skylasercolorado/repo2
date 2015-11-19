#include "PrimeChecker.hpp"
#include <iostream>

using namespace Camax;
using namespace std;

int main()
{
  PrimeChecker primeChecker;
  int n = 1;

  while(1)
    {
      cout << "\n\n\n\tCamila, enter a number: ";
      cin >> n;

      if(n == 0) break;

      primeChecker.IsPrime(n);
    }
  
  return 0;
}
