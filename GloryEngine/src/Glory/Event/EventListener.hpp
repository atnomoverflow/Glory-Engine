#pragma once
#include "pchge.hpp"
#include "Glory/Core.hpp"
#include "Glory/Event/Event.hpp"
namespace Glory
{
    template <typename size>
    class GLORY_API ListenerID
    {
    private:
        size m_Id;

    public:
        ListenerID(size id) : m_Id(id){};
        bool operator==(const ListenerID<size> &other) const
        {
            return m_Id == other.m_Id;
        }

        bool operator!=(const ListenerID<size> &other) const
        {
            return m_Id != other.m_Id;
        }

        size GetID() const
        {
            return m_Id;
        }
    };
    using ID_t = ListenerID<size_t>;

    class GLORY_API BaseEventListener
    {
    public:
        virtual ~BaseEventListener() = default;
        virtual bool DispatchEvent(Event &event) const = 0;
        virtual bool IsEventType(const Event &event) const = 0;
        virtual ID_t GetID() const = 0;
    };
    template <typename EventType>
    class GLORY_API EventListener : public BaseEventListener
    {
    public:
        using EventHandler = std::function<bool(EventType &)>;

        EventListener(EventHandler handler, ID_t id) : m_Callback(handler), m_ID(id) {}
        virtual ~EventListener()
        {
        }

        virtual bool DispatchEvent(Event &event) const override
        {
            if (IsEventType(event) && m_Callback != nullptr)
                return m_Callback(dynamic_cast<EventType &>(event));
            return false;
        }

        virtual bool IsEventType(const Event &event) const override
        {
            return dynamic_cast<const EventType *>(&event) != nullptr;
        }
        virtual ID_t GetID() const override { return m_ID; }

    private:
        EventHandler m_Callback;
        ID_t m_ID;
    };
} // namespace Glory
