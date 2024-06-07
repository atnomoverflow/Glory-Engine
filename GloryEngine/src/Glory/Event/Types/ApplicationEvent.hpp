#pragma once

#include "pchge.hpp"

#include "Glory/Core.hpp"
#include "Glory/Event/Event.hpp"

namespace Glory
{

    class GLORY_API WindowResizeEvent : public Event
    {
    public:
        WindowResizeEvent(unsigned int width, unsigned int height) : m_Width(width), m_Height(height) {}
        inline unsigned int GetWidth() { return m_Width; }
        inline unsigned int GetHeight() { return m_Height; }
        virtual std::string ToString() const override
        {
            std::stringstream ss;
            ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
            return ss.str();
        }

        EVENT_CLASS_METADATA(WindowResize)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)

    private:
        unsigned int m_Width, m_Height;
    };

    class GLORY_API WindowCloseEvent : public Event
    {
    public:
        WindowCloseEvent(){};
        EVENT_CLASS_METADATA(WindowClose)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class GLORY_API WindowTickEvent : public Event
    {

    public:
        WindowTickEvent(){};
        EVENT_CLASS_METADATA(WindowTick)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class GLORY_API WindowUpdateEvent : public Event
    {

    public:
        WindowUpdateEvent(){};
        EVENT_CLASS_METADATA(WindowUpdate)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class GLORY_API WindowRenderEvent : public Event
    {

    public:
        WindowRenderEvent(){};
        EVENT_CLASS_METADATA(WindowRender)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

} // namespace Glory
