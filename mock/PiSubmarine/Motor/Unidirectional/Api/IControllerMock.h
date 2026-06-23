#pragma once

#include <gmock/gmock.h>

#include "PiSubmarine/Motor/Unidirectional/Api/IController.h"

namespace PiSubmarine::Motor::Unidirectional::Api
{
    class IControllerMock : public IController
    {
    public:
        MOCK_METHOD((Error::Api::Result<void>), SetPowered, (bool enabled), (override));
        MOCK_METHOD((Error::Api::Result<bool>), IsPowered, (), (const, override));
        MOCK_METHOD((Error::Api::Result<NormalizedFraction>), GetDutyCycle, (), (const, override));
        MOCK_METHOD((Error::Api::Result<void>), SetDutyCycle, (NormalizedFraction dutyCycle), (override));
        MOCK_METHOD((Error::Api::Result<NormalizedFraction>), GetMinimumEffectiveDutyCycle, (), (const, override));
    };
}
