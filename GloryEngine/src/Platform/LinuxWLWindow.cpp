#include "LinuxWLWindow.hpp"

namespace Glory
{

    static bool s_GLFWInitialized = false;

    static void GLFWErrorCallback(int error_code, const char *description)
    {
        GLORY_CORE_ERROR("GLFW ERROR ({0}): {1}", error_code, description);
    }

    Window *Window::Create(const WindowProps &props)
    {
        return new LinuxWLWindow(props);
    }

    LinuxWLWindow::LinuxWLWindow(const WindowProps &props)
    {
        Init(props);
    }

    LinuxWLWindow::~LinuxWLWindow()
    {
        ShutDown();
    }

    void LinuxWLWindow::OnUpdate()
    {
        glfwPollEvents();
        glfwSwapBuffers(m_Window);
    }

    bool LinuxWLWindow::SetVsync(bool enabled)
    {
        return false;
    }

    bool LinuxWLWindow::IsVsync() const
    {
        return false;
    }

    void LinuxWLWindow::Init(const WindowProps &props)
    {
        m_Data.Title = props.Title;
        m_Data.Width = props.Width;
        m_Data.Height = props.Height;
        /* Initialize the library */
        if (!s_GLFWInitialized)
        {
            glfwInitHint(GLFW_PLATFORM, GLFW_PLATFORM_WAYLAND);
            int success = glfwInit();
            GLORY_CORE_ASSERT(success, "Failed to initialize GLFW!");
            glfwSetErrorCallback(GLFWErrorCallback);
            s_GLFWInitialized = true;
        }

        /* Create a windowed mode window and its OpenGL context */
        m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, props.Title.c_str(), NULL, NULL);
        glfwMakeContextCurrent(m_Window);
        glfwSetWindowUserPointer(m_Window, &m_Data);

        glfwSetWindowSizeCallback(
            m_Window,
            [](GLFWwindow *window, int width, int height)
            {
                WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);
                data.Width = width;
                data.Height = height;
                // this should push event to the queu

                EventManager::GetInstance().PushEvent<WindowResizeEvent>(width, height);
                WindowResizeEvent event(width, height);
                data.Callback(event);
            });
        glfwSetKeyCallback(
            m_Window,
            [](GLFWwindow *window, int key, int scancode, int action, int mods)
            {
                WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);
                switch (action)
                {
                case GLFW_PRESS:
                {
                    KeyPressedEvent event(scancode, 0);
                    EventManager::GetInstance().PushEvent<KeyPressedEvent>(scancode, 0);
                    data.Callback(event);
                    break;
                }
                case GLFW_RELEASE:
                {
                    KeyReleasedEvent event(scancode);
                    EventManager::GetInstance().PushEvent<KeyReleasedEvent>(scancode);
                    data.Callback(event);

                    break;
                }
                case GLFW_REPEAT:
                    KeyPressedEvent event(scancode, 1);
                    EventManager::GetInstance().PushEvent<KeyPressedEvent>(scancode, 1);
                    data.Callback(event);
                    break;
                }
            });
        glfwSetWindowCloseCallback(
            m_Window,
            [](GLFWwindow *window)
            {
                WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);
                EventManager::GetInstance().PushEvent<WindowCloseEvent>();
                WindowCloseEvent event;
                // WindowCloseEvent event;
                data.Callback(event);
            });
    }

    void LinuxWLWindow::ShutDown()
    {
        glfwDestroyWindow(m_Window);
    }

} // namespace Glory