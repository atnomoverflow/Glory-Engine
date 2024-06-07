#pragma once
#include "pchge.hpp"

#include "Glory/Core.hpp"
#include "Glory/window.hpp"
#include "Glory/Event/EventManager.hpp"
#include "Glory/Event/Types/ApplicationEvent.hpp"
#include "Glory/LayerStack.hpp"
namespace Glory
{

    class GLORY_API Application
    {

    public:
        Application();
        virtual ~Application();
        inline static Application &Get() { return *s_application; }
        bool OnEvent(Event &e);
        void Run();
        bool OnWindowClose(const WindowCloseEvent &e);
        
        void PushLayer(Layer* layer);
        void PopLayer(Layer* layer);
        
        void PushOverlay(Layer* overlay);
        void PopOverlay(Layer* overlay);

    private:
        LayerStack m_LayerStack;
        static Application *s_application;
        std::unique_ptr<Window> m_Window;
        bool m_Running;
    };
    Application *CreateApplication();
} // namespace Glory
