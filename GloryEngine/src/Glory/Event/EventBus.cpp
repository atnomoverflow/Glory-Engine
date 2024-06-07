#include "Glory/Event/EventBus.hpp"

namespace Glory
{

    void EventBuss::UnregisterEventListener(const ID_t &id)
    {
        m_Register.UnregisterEventListener(id);
    }

    void EventBuss::PublishEvent(EventQueue &eventQueue) const
    {
        while (auto event = eventQueue.Pop())
        {
            for (const auto &listener : m_Register)
            {
                if (listener->IsEventType(*event))
                    if (listener->DispatchEvent(*event))
                        break;
            }
        }
    }
} // namespace Glory