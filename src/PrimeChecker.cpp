#include "PrimeChecker.hpp"
#include <iostream>
#include <stdexcept>

using namespace Camax;

void PrimeChecker::printCalculationTimeAndFirstFactor(system_clock::time_point start, system_clock::time_point end, long n)
{
  microseconds diff = duration_cast<microseconds>(end - start);
  cout << "\n\tDuration: " << diff.count() << " us.";
  cout << "\n\tn: " << n;
}

void PrimeChecker::validateParameter(long n)
{
  if(_runMode == ProductionMode)
    {
      if(n < 1)
	throw invalid_argument("Negative numbers cannot be processed");
    }
  else if(_runMode == DebugMode)
    {
      if(n < 1 && n >= -99)
	throw invalid_argument("Negative numbers cannot be processed");
      else if(n <= -100 && n >= -199)
	throw runtime_error("run time error exception");
      else if(n <= -200)
	throw "5";

      cout << "\n\tsizeof(n): " << sizeof(n);
      cout << "\n\tsizeof(int): " << sizeof(int); 
    }
}

bool PrimeChecker::IsPrime(long n)
{
  validateParameter(n);

  system_clock::time_point start = system_clock::now();
  
  for(long i = 2; i < n; i++)
    {
      if((n % i) == 0) // For exact division there is no remainder. Then, this is a factor and n is composite.
	{
	  system_clock::time_point end = system_clock::now();

	  if(_verboseMode == VerboseOn)
	    printCalculationTimeAndFirstFactor(start, end, i);
	  
	  return false;
	}
    }

  system_clock::time_point end = system_clock::now();

  if(_verboseMode == VerboseOn)
    printCalculationTimeAndFirstFactor(start, end, -1);
  
  return true;
}

// bool PrimeChecker::Factors(int n)
// {
//   vector<int> factors;

//   if(_runMode == ProductionMode)
//     {
//       if(n < 1)
// 	throw invalid_argument("Negative numbers cannot be processed");
//     }
//   else
//     {
//       if(n < 1 && n >= -99)
// 	throw invalid_argument("Negative numbers cannot be processed");
//       else if(n <= -100 && n >= -199)
// 	throw runtime_error("run time error exception");
//       else if(n <= -200)
// 	throw "5";
//     }

//   // Find factors and optionally show the calculation details to the user
//   for(int i = 2; i < n; i++)
//     {
//       if((n % i) == 0) // For exact division there is no remainder. Then, this is a factor.
// 	{
// 	  factors.push_back(i);

// 	  if(_verboseMode == VerboseOn)
// 	    calculationMessage(n, i, " IS A FACTOR !!! :)");
// 	}
//       else
// 	if(_verboseMode == VerboseOn)
// 	  calculationMessage(n, i, " IS NOT A FACTOR !!! :)");
//     }

//   // Optionally show the list of found factors to the user
//   if(_verboseMode == VerboseOn)
//     {
//       cout << "\n\tFactors (other than 1 and " << n << "): ";
//       for(vector<int>::iterator it = factors.begin(); it != factors.end(); it++)
// 	{
// 	  cout << *it << ", ";
// 	}

//       if(factors.size() == 0) cout << "NONE";
//     }

//   // Return whether the number is prime or not and optionally display the result to the user
//   if(factors.size() == 0)
//     {
//       cout << "\n\n\tNumber " << n << " IS PRIME!!! :)\n\n";
//       return true;
//     }
//   else 
//     {
//       cout << "\n\n\tNumber " << n << " IS COMPOSITE!!! :(\n\n";
//       return false;
//     }
// }


void PrimeChecker::calculationMessage(long n, int i, string message)
{
  cout << "\n\t" << n << " / " << i << " = " << n/i << ". Residue: " << n%i << " ---> Number " << i << message;
}

    
	
