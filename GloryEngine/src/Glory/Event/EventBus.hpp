#pragma once
#include "Glory/Event/Event.hpp"
#include "Glory/Event/EventListener.hpp"
#include "Glory/Event/EventQueue.hpp"
#include "Glory/Event/EventListenerRegister.hpp"

namespace Glory
{
    class GLORY_API EventBuss
    {
    public:
        template <typename EventType>
            requires std::derived_from<EventType, Event> // C++20
        ID_t RegisterEventListenerFor(const typename EventListener<EventType>::EventHandler &callBack)
        {
            return m_Register.RegisterEventListenerFor<EventType>(callBack);
        }
        void UnregisterEventListener(const ID_t &id);
        void PublishEvent(EventQueue &eventQueue) const;

    private:
        EventListenerRegister m_Register;
    };
} // namespace Glory