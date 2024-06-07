#include "Glory/Event/EventListenerRegister.hpp"

namespace Glory
{

    void EventListenerRegister::UnregisterEventListener(const ID_t &id)
    {
        m_Listeners.erase(
            std::remove_if(m_Listeners.begin(), m_Listeners.end(), [id](const auto &listener)
                           { return id == listener->GetID(); }),
            m_Listeners.end());
    }

} // namespace Glory
