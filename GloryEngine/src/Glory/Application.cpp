#include "Application.hpp"

namespace Glory
{
    Application *Application::s_application = nullptr;

    Application::Application()
    {
        if (s_application != nullptr)
            return;
        s_application = this;
    }

    Application::~Application()
    {
    }

    void Application::Run()
    {
        while (true);
    }

} // namespace Glory
