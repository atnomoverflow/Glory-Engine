#pragma once

#include "pchge.hpp"

#include "Glory/Core.hpp"

namespace Glory
{
    class GLORY_API Layer
    {
    public:
        Layer(){};
        virtual ~Layer(){};
        virtual void OnUpdate() {};
        virtual void OnDetatch() {};
        virtual void OnAtatch() {};
    };
} // namespace Glory
