#include "Glory/Event/EventListener.hpp"

namespace Glory
{
    template <typename EventType>
    EventListener<EventType>::~EventListener()
    {
    }

    template <typename EventType>
    inline void EventListener<EventType>::DispatchEvent(const Event &event) const
    {
        if (IsEventType(event) && m_Callback != nullptr)
            callBack(static_cast<const EventType &>(event));
    }

    template <typename EventType>
    bool EventListener<EventType>::IsEventType(const Event &event) const
    {
        return dynamic_cast<const EventType *>(&event) != nullptr;
    }

} // namespace Glory
