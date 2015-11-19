#include "PrimeChecker.hpp"
#include <iostream>

using namespace Camax;
using namespace std;

bool PrimeChecker::IsPrime(int n)
{
  vector<int> factors;

  for(int i = 2; i < n; i++)
    {
      if((n % i) == 0) // For exact division there is no reaminder. Then, this is a factor.
	{
	  factors.push_back(i);

	  if(_verbose)
	    calculationMessage(n, i, " IS A FACTOR !!! :)");
	}
      else
	if(_verbose)
	  calculationMessage(n, i, " IS NOT A FACTOR !!! :)");
    }

  if(_verbose)
    {
      cout << "\n\tFactors (other than 1 and " << n << "): ";
      for(vector<int>::iterator it = factors.begin(); it != factors.end(); it++)
	{
	  cout << *it << ", ";
	}

      if(factors.size() == 0) cout << "NONE";
    }

  if(factors.size() == 0)
    {
      cout << "\n\n\tNumber " << n << " IS PRIME!!! :)\n\n";
      return true;
    }
  else 
    {
      cout << "\n\n\tNumber " << n << " IS COMPOSITE!!! :(\n\n";
      return false;
    }
}

void PrimeChecker::calculationMessage(int n, int i, string message)
{
  cout << "\n\t" << n << " / " << i << " = " << n/i << ". Residue: " << n%i << " ---> Number " << i << message;
}

    
	
