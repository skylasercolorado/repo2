#include "PrimeChecker.hpp"
#include <iostream>
#include <stdexcept>

using namespace Camax;
using namespace std;

static void doWork()
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
}

int main()
{
  PrimeChecker primeChecker;
  int n = 1;

  // while(1)
  //   {
  //     cout << "\n\n\n\tCamila, enter a number: ";
  //     cin >> n;

  //     if(n == 0) break;

  //     primeChecker.IsPrime(n);
  //   }

  while(1)
    {
      try
	{
	  //doWork();
	  while(1)
	    {
	      cout << "\n\n\n\tCamila, enter a number: ";
	      cin >> n;
	      
	      if(n == 0) break;
	      
	      primeChecker.IsPrime(n);
	    }
	}
      catch(const invalid_argument &e)
	{
	  cout << "\n\t\t\t" << "Cannot process negative numbers. Try again." << "\n\n";
	}
    }
  
  return 0;
}

