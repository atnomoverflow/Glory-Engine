#include "Glory/Event/EventListenerRegister.hpp"

namespace Glory
{

    template <typename EventType>
    inline ListenerID EventListenerRegister::RegisterEventListenerFor(const typename EventListener<EventType>::EventHandler &callback)
    {
        static ListenerID ID(0);

        m_Listeners.emplace_back(std::make_unique<EventListener<EventType>>(callback, ID));

        return ID++;
    }

    void EventListenerRegister::UnregisterEventListener(const ListenerID &id)
    {
        m_Listeners.erase(
            std::remove_if(m_Listeners.begin(), m_Listeners.end(), [id](const auto &listener)
                           { return id == listener->GetID(); }),
            m_Listeners.end());
    }

} // namespace Glory
