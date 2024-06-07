#pragma once
#include "pchge.hpp"
#include "Glory/Core.hpp"
#include "Glory/Event/Event.hpp"
#include "Glory/Event/EventListener.hpp"

namespace Glory
{

    class GLORY_API EventListenerRegister
    {

    public:
        using ListenerList = std::vector<std::unique_ptr<BaseEventListener>>;
        template <typename EventType>
            requires std::derived_from<EventType, Event> // C++20
        ID_t RegisterEventListenerFor(const typename EventListener<EventType>::EventHandler &callback)
        {
            static size_t id = 0;
            ID_t ID(id);
            ++id;
            std::unique_ptr<BaseEventListener> listener = std::make_unique<EventListener<EventType>>(callback, ID);
            m_Listeners.push_back(std::move(listener));
            return ID;
        }
        void UnregisterEventListener(const ID_t &id);

        auto begin() { return m_Listeners.begin(); }
        auto begin() const { return m_Listeners.begin(); }
        auto end() { return m_Listeners.end(); }
        auto end() const { return m_Listeners.end(); }

    private:
        ListenerList m_Listeners;
    };

} // namespace Glory
