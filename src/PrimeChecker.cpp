#include "PrimeChecker.hpp"
#include <iostream>

using namespace Camax;
using namespace std;

bool PrimeChecker::IsPrime(int n)
{
  vector<int> factors;

  for(int i = 2; i < n; i++)
    {
      if((n % i) == 0)
	{
	  factors.push_back(i);

	  if(_verbose)
	      cout << "\n\t" << n << " / " << i << " = " << n/i << ". Residue: " << n%i << " ---> Number " << i << " IS A FACTOR !!! :)";
	}
      else
	if(_verbose)
	  cout << "\n\t" << n << " / " << i << " = " << n/i << ". Residue: " << n%i << " ---> Number " << i << " IS NOT A FACTOR !!! :(";
    }

  cout << "\n\tFactors (other than 1 and " << n << "): ";
  for(vector<int>::iterator it = factors.begin(); it != factors.end(); it++)
    {
      cout << *it << ", ";
    }

  if(factors.size() == 0)
    {
      cout << "NONE";
      cout << "\n\n\tNumber " << n << " IS PRIME!!! :)\n\n";
      return true;
    }
  else
    {
      cout << "\n\n\tNumber " << n << " IS COMPOSITE!!! :(\n\n";
      return false;
    }
}

      
    
	
