#include "Glory/Event/EventQueue.hpp"
#include "Event.hpp"

namespace Glory
{
    std::unique_ptr<Event> EventQueue::Pop()
    {
        if (m_EventQueue.empty())
            return nullptr;

        // remove ownership
        std::unique_ptr<Event> event = std::move(m_EventQueue.front());
        // then remove item
        m_EventQueue.pop();
        return event;
    }

} // namespace Glory
