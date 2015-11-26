#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "PrimeChecker.hpp"

using namespace Camax;
using namespace std;

class PrimeCheckerTest : public ::testing::Test
{
public:
  PrimeCheckerTest()
  {
    
  }
  
  virtual void SetUp()
  {

  }
  
  virtual void TearDown()
  {
    
  }
  

};

TEST_F(PrimeCheckerTest, ExpectedPrimeTest)
{
  PrimeChecker primeChecker;

  EXPECT_TRUE(primeChecker.IsPrime(5L));
}

TEST_F(PrimeCheckerTest, ExpectedCompositeTest)
{
  PrimeChecker primeChecker;

  EXPECT_FALSE(primeChecker.IsPrime(4L));
}

TEST_F(PrimeCheckerTest, ExpectedCompositeNumber12Test)
{
  PrimeChecker primeChecker;

  EXPECT_FALSE(primeChecker.IsPrime(12L));
}

TEST_F(PrimeCheckerTest, ExpectedPrimeNumber7919Test)
{
  PrimeChecker primeChecker(VerboseOff);

  EXPECT_TRUE(primeChecker.IsPrime(7919L));
}

TEST_F(PrimeCheckerTest, ExpectedPrimeNumberNegativeTest)
{
  PrimeChecker primeChecker(VerboseOn);

  EXPECT_THROW(primeChecker.IsPrime(-1L), invalid_argument);
}
