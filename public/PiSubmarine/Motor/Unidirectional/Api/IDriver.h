#pragma once

#include "PiSubmarine/NormalizedFraction.h"

namespace PiSubmarine::Motor::Unidirectional::Api
{
    class IDriver
    {
public:
        virtual ~IDriver() = default;
        virtual void SetPowered(bool enabled) = 0;
        [[nodiscard]] virtual bool IsPowered() const = 0;
        [[nodiscard]] virtual NormalizedFraction GetDutyCycle() const = 0;
        virtual void SetDutyCycle(NormalizedFraction dutyCycle) = 0;
    };
}

