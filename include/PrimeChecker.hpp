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
    bool IsPrime(long n);
    
  private:
    VerboseMode _verboseMode;
    RunMode _runMode;
    void calculationMessage(long n, int i, string message);
    void printCalculationTimeAndFirstFactor(system_clock::time_point start, system_clock::time_point end, long n);
    void validateParameter(long n);
  };
}

#endif // CAMAX_PRIMECHECKER_HPP
