#include "Glory/Application.hpp"
#include "Application.hpp"

namespace Glory
{

    // using WindowEvent = std::variant<WindowCloseEvent, WindowRenderEvent, WindowResizeEvent, WindowUpdateEvent, WindowTickEvent>;
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

    Application *Application::s_application = nullptr;

    Application::Application()
    {
        GLORY_CORE_ASSERT(!s_application, "Failed to start the application");
        s_application = this;
        m_Window = std::unique_ptr<Window>(Window::Create());
        m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
        EventManager::GetInstance().RegisterEventListenerFor<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
    }

    Application::~Application()
    {
    }
    bool Application::OnEvent(Event &e)
    {
        EventManager::GetInstance().PublishEvent();
        return true;
    }
    void Application::Run()
    {
        while (m_Running)
        {
            for (auto layer : m_LayerStack)
                layer->OnUpdate();
            m_Window->OnUpdate();
        }
    }

    bool Application::OnWindowClose(const WindowCloseEvent &e)
    {
        m_Running = false;
        return true;
    }

    void Application::PushLayer(Layer *layer)
    {
        m_LayerStack.PushLayer(layer);
        layer->OnAtatch();
    }

    void Application::PopLayer(Layer *layer)
    {
        m_LayerStack.PopLayer(layer);
        layer->OnDetatch();
    }

    void Application::PushOverlay(Layer *overlay)
    {
        m_LayerStack.PushOverlay(overlay);
        overlay->OnAtatch();
    }

    void Application::PopOverlay(Layer *overlay)
    {
        m_LayerStack.PopOverlay(overlay);
        overlay->OnDetatch();
    }

} // namespace Glory
