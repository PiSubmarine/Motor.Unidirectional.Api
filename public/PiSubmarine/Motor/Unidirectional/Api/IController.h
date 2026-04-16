#pragma once

#include "PiSubmarine/NormalizedFraction.h"
#include "PiSubmarine/Error/Api/Result.h"

namespace PiSubmarine::Motor::Unidirectional::Api
{
    class IController
    {
public:
        virtual ~IController() = default;
        [[nodiscard]] virtual Error::Api::Result<void> SetPowered(bool enabled) = 0;
        [[nodiscard]] virtual Error::Api::Result<bool> IsPowered() const = 0;
        [[nodiscard]] virtual Error::Api::Result<NormalizedFraction> GetDutyCycle() const = 0;
        [[nodiscard]] virtual Error::Api::Result<void> SetDutyCycle(NormalizedFraction dutyCycle) = 0;
        [[nodiscard]] virtual Error::Api::Result<NormalizedFraction> GetMinimumEffectiveDutyCycle() const = 0;
    };
}

