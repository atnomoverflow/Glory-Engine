#pragma once
#include "Core.hpp"

namespace Glory
{

    class GLORY_API Application
    {
    public:
        Application();
        virtual ~Application();
        inline static Application &Get() { return *s_application; }
        void Run();
    private:
        static Application *s_application;
    };
    Application *CreateApplication();
} // namespace Glory
