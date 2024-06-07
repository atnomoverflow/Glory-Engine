#pragma once
#include "pchge.hpp"
#include "Glory/Core.hpp"
#include "Glory/Event/Event.hpp"
namespace Glory
{
    struct WindowProps
    {
        std::string Title;
        unsigned int Width, Height;
        WindowProps(const std::string &title = "Glory Engine",
                    unsigned int width = 1280,
                    unsigned int heign = 720)
            : Title(title), Width(width), Height(heign)
        {
        }
    };
    class GLORY_API Window
    {
    public:
        using EventCallbackFn = std::function<bool(Event &)>;
        virtual ~Window(){};

        virtual void OnUpdate() = 0;

        virtual unsigned int GetWidth() const = 0;
        virtual unsigned int GetHeight() const = 0;

        virtual void SetEventCallback(const EventCallbackFn &callback) = 0;
        virtual bool SetVsync(bool enabled) = 0;
        virtual bool IsVsync() const = 0;

        static Window *Create(const WindowProps &props = WindowProps());
    };

} // namespace Glory
