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

  EXPECT_EQ(true, primeChecker.IsPrime(5));
}

TEST_F(PrimeCheckerTest, ExpectedCompositeTest)
{
  PrimeChecker primeChecker;

  EXPECT_EQ(false, primeChecker.IsPrime(4));
}
