#ifndef CAMAX_PRIMECHECKER_HPP
#define CAMAX_PRIMECHECKER_HPP

#include <vector>
#include <string>
#include <chrono>
#include <ratio>

using namespace std;
using namespace std::chrono;

namespace Camax
{
  enum VerboseMode : int
    {
      VerboseOn,
      VerboseOff
    };

  enum RunMode : int
    {
      DebugMode,
      ProductionMode
    };
  
  class PrimeChecker
  {
  public:
    PrimeChecker(VerboseMode verboseMode = VerboseOn, RunMode runMode = ProductionMode) : _verboseMode(verboseMode), _runMode(runMode) {}
    bool IsPrime(long long n);
    
  private:
    VerboseMode _verboseMode;
    RunMode _runMode;
    void calculationMessage(long long n, int i, string message);
    void printCalculationTime(system_clock::time_point start, system_clock::time_point end);
    void validateParameter(long long n);
  };
}

#endif // CAMAX_PRIMECHECKER_HPP
