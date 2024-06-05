#pragma once
#include "pchge.hpp"
#include "Glory/Core.hpp"

namespace Glory
{

    enum class EventType
    {
        None = 0,
        ApplicationUpdate,
        ApplicationRender,
        KeyPressed,
        KeyReleased
    };

    enum EventCategory
    {
        None = 0,
        EventCategoryApplication = BIT(0),
        EventCategoryKeyboard = BIT(1),

    };

    struct EventMetadata
    {
        EventType type;
        std::string name;
    };

    class GLORY_API Event
    {

    public:
        virtual EventMetadata GetEventMetadata() const = 0;
        virtual int GetCategoryFlags() const = 0;
        inline bool IsCategory(const EventCategory catergory)
        {
            return GetCategoryFlags() & catergory;
        }
        bool IsHandled() { return m_Handled; }
        void Handel() { m_Handled = true; }

    private:
        bool m_Handled = false;
    };



} // namespace Glory
