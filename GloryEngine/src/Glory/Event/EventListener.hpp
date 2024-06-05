#pragma once
#include "pchge.hpp"
#include "Glory/Core.hpp"
#include "Glory/Event/Event.hpp"
namespace Glory
{
    class ListenerID
    {
    private:
        long int m_Id;

    public:
        ListenerID(long int id) : m_Id(id){};
        bool operator==(const ListenerID &other) const
        {
            return m_Id == other.m_Id;
        }

        bool operator!=(const ListenerID &other) const
        {
            return m_Id != other.m_Id;
        }

        ListenerID &operator++()
        {
            ++m_Id;
            return *this;
        }

        ListenerID operator++(int)
        {
            ListenerID temp = *this;
            ++(*this);
            return temp;
        }

        ListenerID &operator--()
        {
            --m_Id;
            return *this;
        }

        ListenerID operator--(int)
        {
            ListenerID temp = *this;
            --(*this);
            return temp;
        }

        int GetID() const
        {
            return m_Id;
        }
    };

    class GLORY_API BaseEventListener
    {
    public:
        virtual ~BaseEventListener() = default;
        virtual void DispatchEvent(const Event &event) const = 0;
        virtual bool IsEventType(const Event &event) const = 0;
        virtual ListenerID GetID() const = 0;
    };
    template <typename EventType>
    class GLORY_API EventListener : public BaseEventListener
    {
    public:
        using EventHandler = std::function<bool(EventType &)>;
        EventListener(EventHandler handler, ListenerID id) : m_Callback(handler), m_ID(id) {}
        ~EventListener() override;
        void DispatchEvent(const Event &event) const override;
        bool IsEventType(const Event &event) const override;
        ListenerID GetID() const override { return m_ID; }

    private:
        EventHandler m_Callback;
        ListenerID m_ID;
    };
} // namespace Glory
