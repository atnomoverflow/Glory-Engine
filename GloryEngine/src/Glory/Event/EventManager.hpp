#pragma once
#include "Glory/Event/Event.hpp"
#include "Glory/Event/EventListener.hpp"
#include "Glory/Event/EventQueue.hpp"
#include "Glory/Event/EventListenerRegister.hpp"
#include "Glory/Event/EventBus.hpp"

namespace Glory
{

    class EventManager
    {

    public:
        template <typename EventType>
        ListenerID RegisterEventListenerFor(const typename EventListener<EventType>::EventHandler &callBack);
        void UnregisterEventListener(const ListenerID &id);
        void PublishEvent();
        template <typename T, typename... Args>
            requires std::derived_from<T, Event> // C++20
        void PushEvent(Args &&...args);

    private:
        EventBuss m_EventBuss;
        EventQueue m_EventQueue;
    };

} // namespace Glory
