#pragma once
#include "pchge.hpp"

#include "Glory/Core.hpp"
#include "Glory/window.hpp"
#include "Glory/Event/EventManager.hpp"
#include "Glory/Event/Types/ApplicationEvent.hpp"
#include "Glory/Event/Types/KeyEvent.hpp"
#include "GLFW/glfw3.h"

namespace Glory
{

    class LinuxWLWindow : public Window
    {

    public:
        LinuxWLWindow(const WindowProps &props);
        virtual ~LinuxWLWindow();
        void OnUpdate() override;
        inline unsigned int GetWidth() const override { return m_Data.Width; }
        inline unsigned int GetHeight() const override { return m_Data.Height; }

        inline void SetEventCallback(const EventCallbackFn &callback) override { m_Data.Callback = callback; };
        bool SetVsync(bool enabled) override;
        bool IsVsync() const override;

    private:
        virtual void Init(const WindowProps &props);
        virtual void ShutDown();
    private:
        GLFWwindow *m_Window;
        struct WindowData
        {
            std::string Title;
            unsigned int Width, Height;
            bool VSync;

            EventCallbackFn Callback;
        };
        WindowData m_Data;
    };
} // namespace Glory
