#include "GoogleTestApp.h"
 
#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "ExampleGameCore/Public/CFloatingActor.h"
#include "ExampleGameCore/Public/IUnrealActor.h"
#include "ExampleGameCore/Public/IUnrealMath.h"

class MockUnrealMath : public IUnrealMath {
public:
    MOCK_METHOD1(Sin, float(float Value));
};

class MockUnrealActor : public IUnrealActor {
public:
    MOCK_METHOD1(SetActorLocation, void(FVector location));
    MOCK_METHOD0(GetActorLocation, FVector());
};

class GivenAFloatingActor : public ::testing::Test {
protected:
    MockUnrealActor mMockActor;
    MockUnrealMath mMockMath;
    CFloatingActor mFloatingActor;
    FVector mVector;
public:
    GivenAFloatingActor() :
        mFloatingActor(mMockActor, mMockMath)
    {

        mVector.X = 0;
        mVector.Y = 0;
        mVector.Z = 0;

        ON_CALL(mMockActor, GetActorLocation()).WillByDefault(::testing::Return(mVector));
    };
};

TEST_F(GivenAFloatingActor, WhenFirstTickShouldNotMove)
{
    EXPECT_CALL(mMockMath, Sin(::testing::_)).Times(2);
    EXPECT_CALL(mMockActor, GetActorLocation()).Times(1);
    EXPECT_CALL(mMockActor, SetActorLocation(::testing::Field(&FVector::Z, 0))).Times(1);

    mFloatingActor.Tick(0.0f);
}

TEST_F(GivenAFloatingActor, WhenTicksTwiceShouldMoveBySinDifferenceTimes20)
{
    EXPECT_CALL(mMockActor, GetActorLocation()).Times(2);
    EXPECT_CALL(mMockMath, Sin(0.0f)).WillRepeatedly(::testing::Return(0.0f));
    EXPECT_CALL(mMockMath, Sin(1.0f)).WillRepeatedly(::testing::Return(1.0f));
    EXPECT_CALL(mMockActor, SetActorLocation(::testing::_)).Times(1);
    EXPECT_CALL(mMockActor, SetActorLocation(::testing::Field(&FVector::Z, 20.0f))).Times(1);

    mFloatingActor.Tick(0.0f);
    mFloatingActor.Tick(1.0f);
}

TEST_F(GivenAFloatingActor, WhenTicksThreeTimesShouldConsiderDifferenceBetweenLast2Ticks)
{
    EXPECT_CALL(mMockMath, Sin(0.0f)).WillRepeatedly(::testing::Return(0.0f));
    EXPECT_CALL(mMockMath, Sin(1.0f)).WillRepeatedly(::testing::Return(1.0f));
    EXPECT_CALL(mMockMath, Sin(2.0f)).WillRepeatedly(::testing::Return(0.5f));
    EXPECT_CALL(mMockActor, GetActorLocation()).Times(3);
    EXPECT_CALL(mMockActor, SetActorLocation(::testing::_)).Times(2);
    EXPECT_CALL(mMockActor, SetActorLocation(::testing::Field(&FVector::Z, -10.0f))).Times(::testing::AtLeast(1));

    mFloatingActor.Tick(0.0f);
    mFloatingActor.Tick(1.0f);
    mFloatingActor.Tick(1.0f);
}