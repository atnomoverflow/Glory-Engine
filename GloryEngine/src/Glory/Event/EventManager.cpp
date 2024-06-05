#include "Glory/Event/EventManager.hpp"
#include "EventManager.hpp"

namespace Glory
{

    template <typename EventType>
    ListenerID EventManager::RegisterEventListenerFor(const typename EventListener<EventType>::EventHandler &callBack)
    {
        return m_EventBuss.RegisterEventListenerFor(callBack);
    }

    void EventManager::UnregisterEventListener(const ListenerID &id)
    {
        m_EventBuss.UnregisterEventListener(id);
    }

    void EventManager::PublishEvent()
    {
        m_EventBuss.PublishEvent(m_EventQueue);
    }

    template <typename T, typename... Args>
        requires std::derived_from<T, Event> // C++20
    void EventManager::PushEvent(Args &&...args)
    {
        m_EventQueue.Push(std::make_unique<T>(std::forward<Args>(args)...));
    }
} // namespace Glory
