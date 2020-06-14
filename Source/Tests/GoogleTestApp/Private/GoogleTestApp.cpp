#include "GoogleTestApp.h"

#include "src/gmock-all.cc"
#include "src/gtest_main.cc"
#include "src/gtest-all.cc" //Do not do this in Unreal 4.20. It will cause some errors because internally google test adds windows.h which conflicts to other headers that CoreMinimal.h depends.
#include "gtest/gtest.h"
#include "gmock/gmock.h"

class GivenASampleTest : public ::testing::Test
{
};

TEST_F(GivenASampleTest, WhenRunningSampleTestShouldPass)
{
    ASSERT_TRUE(true);
}

TEST_F(GivenASampleTest, WhenRunningSampleTestShouldNotPass)
{
    ASSERT_FALSE(false);
}

TEST(MyTest, ThisIsNotAFixture)
{
    ASSERT_FALSE(false);
}