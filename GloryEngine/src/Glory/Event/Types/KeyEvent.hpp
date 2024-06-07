#pragma once

#include "pchge.hpp"

#include "Glory/Core.hpp"
#include "Glory/Event/Event.hpp"

namespace Glory
{

    class GLORY_API KeyEvent : public Event
    {
    protected:
        KeyEvent(int keycode) : m_KeyCode(keycode){};
        int m_KeyCode;

    public:
        inline int GetKeyCode() const { return m_KeyCode; }
        EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
    };

    class GLORY_API KeyReleasedEvent : public KeyEvent
    {

    public:
        KeyReleasedEvent(int keycode) : KeyEvent(keycode){};
        virtual std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << m_KeyCode;
            return ss.str();
        }
        EVENT_CLASS_METADATA(KeyReleased)
    };

    class GLORY_API KeyPressedEvent : public KeyEvent
    {
    public:
        KeyPressedEvent(int keycode, int repeatCount)
            : KeyEvent(keycode), m_RepeatCount(repeatCount) {}

        inline int GetRepeatCount() const { return m_RepeatCount; }
        virtual std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
            return ss.str();
        }
        EVENT_CLASS_METADATA(KeyPressed)
    private:
        int m_RepeatCount;
    };

} // namespace Glory
