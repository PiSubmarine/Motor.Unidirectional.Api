#include <gtest/gtest.h>

#include "PiSubmarine/Motor/Unidirectional/Api/IControllerMock.h"

namespace PiSubmarine::Motor::Unidirectional::Api
{
    TEST(IControllerMockTest, SupportsMotorControlOperations)
    {
        IControllerMock controller;

        EXPECT_CALL(controller, SetPowered(true))
            .WillOnce(testing::Return(Error::Api::Result<void>{}));
        EXPECT_CALL(controller, IsPowered())
            .WillOnce(testing::Return(true));
        EXPECT_CALL(controller, GetDutyCycle())
            .WillOnce(testing::Return(0.25f));
        EXPECT_CALL(controller, SetDutyCycle(NormalizedFraction{0.5f}))
            .WillOnce(testing::Return(Error::Api::Result<void>{}));
        EXPECT_CALL(controller, GetMinimumEffectiveDutyCycle())
            .WillOnce(testing::Return(0.1f));

        EXPECT_TRUE(controller.SetPowered(true).has_value());
        EXPECT_TRUE(controller.IsPowered().value());
        EXPECT_FLOAT_EQ(controller.GetDutyCycle().value(), 0.25f);
        EXPECT_TRUE(controller.SetDutyCycle(NormalizedFraction{0.5f}).has_value());
        EXPECT_FLOAT_EQ(controller.GetMinimumEffectiveDutyCycle().value(), 0.1f);
    }
}
