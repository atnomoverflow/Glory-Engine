#include "Glory/Event/EventBus.hpp"

namespace Glory
{
    template <typename EventType>
    inline ListenerID EventBuss::RegisterEventListenerFor(const typename EventListener<EventType>::EventHandler &callBack)
    {
        return m_Register.RegisterEventListenerFor<EventType>(callBack);
    }

    void EventBuss::UnregisterEventListener(const ListenerID &id)
    {
        m_Register.UnregisterEventListener(id);
    }

    void EventBuss::PublishEvent(EventQueue &eventQueue) const
    {
        while (const auto &event = eventQueue.Pop())
        {
            for (const auto &listener : m_Register)
            {
                if (event->IsHandled())
                    break;
                if (listener->IsEventType(*event))
                    listener->DispatchEvent(*event);
            }
        }
    }
} // namespace Glory