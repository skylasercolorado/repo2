#ifndef CAMAX_PRIMECHECKER_HPP
#define CAMAX_PRIMECHECKER_HPP

#include <vector>
#include <string>

using namespace std;

namespace Camax
{
  enum VerboseMode
    {
      VerboseOn,
      VerboseOff
    };

  enum RunMode
    {
      DebugMode,
      ProductionMode
    };
  
  class PrimeChecker
  {
  public:
    PrimeChecker(VerboseMode verboseMode = VerboseOn, RunMode runMode = ProductionMode) : _verboseMode(verboseMode), _runMode(runMode) {}
    bool IsPrime(int n);
    
  private:
    VerboseMode _verboseMode;
    RunMode _runMode;
    void calculationMessage(int n, int i, string message);
  };
}

#endif // CAMAX_PRIMECHECKER_HPP
