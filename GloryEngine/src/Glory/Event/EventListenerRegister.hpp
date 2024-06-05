#pragma once
#include "pchge.hpp"
#include "Glory/Core.hpp"
#include "Glory/Event/Event.hpp"
#include "Glory/Event/EventListener.hpp"

namespace Glory
{

    class EventListenerRegister
    {

    public:
        using ListenerList = std::vector<std::unique_ptr<BaseEventListener>>;
        template <typename EventType>
        ListenerID RegisterEventListenerFor(const typename EventListener<EventType>::EventHandler &callBack);
        void UnregisterEventListener(const ListenerID &id);

        auto begin() { return m_Listeners.begin(); }
        auto begin() const { return m_Listeners.begin(); }
        auto end() { return m_Listeners.end(); }
        auto end() const { return m_Listeners.end(); }

    private:
        ListenerList m_Listeners;
    };

} // namespace Glory
