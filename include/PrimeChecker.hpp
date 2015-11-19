#ifndef CAMAX_PRIMECHECKER_HPP
#define CAMAX_PRIMECHECKER_HPP

#include <vector>
#include <string>

using namespace std;

namespace Camax
{
  class PrimeChecker
  {
  public:
    PrimeChecker(bool verbose = true) : _verbose(verbose) {}
    bool IsPrime(int n);
    
  private:
    bool _verbose;
    void calculationMessage(int n, int i, string message);
  };
}

#endif // CAMAX_PRIMECHECKER_HPP
