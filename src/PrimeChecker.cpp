#include "PrimeChecker.hpp"
#include <iostream>
#include <stdexcept>
#include <chrono>
#include <ratio>

using namespace Camax;
using namespace std;
using namespace std::chrono;

bool PrimeChecker::IsPrime(int n)
{
  if(_runMode == ProductionMode)
    {
      if(n < 1)
	throw invalid_argument("Negative numbers cannot be processed");
    }
  else
    {
      if(n < 1 && n >= -99)
	throw invalid_argument("Negative numbers cannot be processed");
      else if(n <= -100 && n >= -199)
	throw runtime_error("run time error exception");
      else if(n <= -200)
	throw "5";
    }

  //  time_point end;
  //  miliseconds diff;
  system_clock::time_point start = system_clock::now();
  
  for(int i = 2; i < n; i++)
    {
      if((n % i) == 0) // For exact division there is no remainder. Then, this is a factor.
	{
	  //TODO: Move this message to the app level ---> cout << "\n\n\tNumber " << n << " IS COMPOSITE!!! :(\n\n";
	  system_clock::time_point end = system_clock::now();
	  microseconds diff = end - start;
	  if(_verboseMode == VerboseOn)
	    cout << "\n\tDuration: " << diff.count() << " us.";
	  
	  return false;
	}
    }

  //TODO: Move this message to the app level ---> cout << "\n\n\tNumber " << n << " IS COMPOSITE!!! :(\n\n";
  system_clock::time_point end = system_clock::now();
  microseconds diff = end - start;
  if(_verboseMode == VerboseOn)
    cout << "\n\tDuration: " << diff.count() << " us.";
	  
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


void PrimeChecker::calculationMessage(int n, int i, string message)
{
  cout << "\n\t" << n << " / " << i << " = " << n/i << ". Residue: " << n%i << " ---> Number " << i << message;
}

    
	
