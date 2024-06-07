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

        WindowResize,
        WindowClose,
        WindowTick,
        WindowUpdate,
        WindowRender,

        KeyPressed,
        KeyReleased
    };

    enum EventCategory
    {
        None = 0,
        EventCategoryApplication = BIT(0),
        EventCategoryKeyboard = BIT(1),
        EventCategoryInput = BIT(2),

    };

    struct EventMetadata
    {
        EventType type;
        std::string name;
    };

#define EVENT_CLASS_CATEGORY(category) \
    virtual int GetCategoryFlags() const override { return category; }
#define EVENT_CLASS_METADATA(type) \
    virtual EventMetadata GetEventMetadata() const override { return {EventType::type, #type}; }
    class GLORY_API Event
    {

    public:
        virtual EventMetadata GetEventMetadata() const = 0;
        virtual int GetCategoryFlags() const = 0;
        inline bool IsCategory(const EventCategory catergory)
        {
            return GetCategoryFlags() & catergory;
        }

        template <typename EventType>
            requires std::derived_from<EventType, Event> // C++20
        std::unique_ptr<EventType> Clone() const
        {
            return std::make_unique<EventType>(*static_cast<const EventType *>(this));
        }
        virtual std::string ToString() const { return GetEventMetadata().name; }

    private:
    };
    inline std::ostream &operator<<(std::ostream &os, const Event &e)
    {
        return os << e.ToString();
    }
} // namespace Glory
