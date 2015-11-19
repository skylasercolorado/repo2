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

  EXPECT_TRUE(primeChecker.IsPrime(5));
}

TEST_F(PrimeCheckerTest, ExpectedCompositeTest)
{
  PrimeChecker primeChecker;

  EXPECT_FALSE(primeChecker.IsPrime(4));
}

TEST_F(PrimeCheckerTest, ExpectedCompositeNumber12Test)
{
  PrimeChecker primeChecker;

  EXPECT_FALSE(primeChecker.IsPrime(12));
}
