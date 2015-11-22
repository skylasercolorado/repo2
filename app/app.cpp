#include "PrimeChecker.hpp"
#include <iostream>
#include <stdexcept>
#include <getopt.h>

using namespace Camax;
using namespace std;

struct PrimeCheckerParams
{
  VerboseMode verboseMode;
  RunMode runMode;
};

static PrimeCheckerParams& parseCommandLineOptions(int argc, char **argv)
{
  PrimeCheckerParams& params = *(new PrimeCheckerParams);

  params.verboseMode = VerboseOn;
  params.runMode = ProductionMode;

  static struct option longOptions[] =
    {
      {"brief", no_argument, (int*) &params.verboseMode, VerboseOff},
      {"verbose", no_argument, (int*) &params.verboseMode, VerboseOn},
      {"debug", no_argument, (int*) &params.runMode, DebugMode},
      {"production", no_argument, (int*) &params.runMode, ProductionMode},
      {"help", no_argument, 0, 'h'},
      {0, 0, 0, 0}
    };
  
  /* getopt_long stores the option index here. */
  int optionIndex = 0;
  int c;

  while((c = getopt_long (argc, argv, "h", longOptions, &optionIndex)) != -1)
    {
      switch(c)
	{
	case 'h':
	  cout << "\n\nDescription: executable is a command line prime number checker (first phase). \n";
	  cout << "\nexecutable [options]\n";
	  cout << "\nOptions: \n";
	  cout << "\n--brief \t   \t Non verbose operation.\n";
	  cout << "--verbose \t   \t Verbose messages.\n";
	  cout << "--debug \t   \t Run in debug mode.\n";
	  cout << "--production \t   \t Run in production mode.\n";
	  cout << "--help \t -h \t Display this help message.\n\n";
	  exit(0);

	case '?':
	  // Unrecognized option
	  cout << "\n\tUnrecognized option. Try --help\n";
	  exit(0);
      
	default:
	  // No special action to do on the other valid options
	  break;
	}
    }

  return params;
}

static void doWork(int argc, char **argv)
{
  PrimeCheckerParams& params = parseCommandLineOptions(argc, argv);
  
  PrimeChecker primeChecker(params.verboseMode, params.runMode);
  int n;

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

  delete &params;
}

int main(int argc, char **argv)
{
  try
    {
      doWork(argc, argv);
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

