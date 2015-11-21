#include "PrimeChecker.hpp"
#include <iostream>
#include <stdexcept>

using namespace Camax;
using namespace std;

static void doWork()
{
  PrimeChecker primeChecker(VerboseOn, DebugMode);
  int n = 1;

  while(1)
    {
      try
	{
	  cout << "\n\n\n\tCamila, enter a number: ";
	  cin >> n;
	  
	  if(n == 0)
	    {
	      cout << "\n\n\t\tBye Cami !!!  :( !!!\n\n\n";
	      break;
	    }
	  
	  primeChecker.IsPrime(n);
	}
      catch(const invalid_argument& e)
	{
	  cout << "\n\tException: " << e.what() << "\n\n";
	}
    }
}

int main()
{
  try
    {
      doWork();
    }
  catch(const exception &e)
    {
      cout << "\n\n\tException: " << e.what() << "\n\n";
    }
  catch(...)
    {
      cout << "\n\n\tUnknown expection occurred.\n\n";
    }
  
  return 0;
}

