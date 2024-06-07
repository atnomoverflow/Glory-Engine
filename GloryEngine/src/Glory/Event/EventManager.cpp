#include "Glory/Event/EventManager.hpp"

namespace Glory
{

    void EventManager::UnregisterEventListener(const ID_t &id)
    {
        m_EventBuss.UnregisterEventListener(id);
    }

    void EventManager::PublishEvent()
    {
        m_EventBuss.PublishEvent(m_EventQueue);
    }

} // namespace Glory
