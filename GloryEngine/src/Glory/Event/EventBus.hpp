#pragma once
#include "Glory/Event/Event.hpp"
#include "Glory/Event/EventListener.hpp"
#include "Glory/Event/EventQueue.hpp"
#include "Glory/Event/EventListenerRegister.hpp"

namespace Glory
{
    class EventBuss
    {
    public:
        template <typename EventType>
        ListenerID RegisterEventListenerFor(const typename EventListener<EventType>::EventHandler &callBack);
        void UnregisterEventListener(const ListenerID &id);
        void PublishEvent(EventQueue &eventQueue) const;

    private:
        EventListenerRegister m_Register;
    };
} // namespace Glory