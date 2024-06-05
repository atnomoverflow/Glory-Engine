#pragma once
#include "pchge.hpp"
#include "Glory/Core.hpp"
#include "Glory/Event/Event.hpp"
namespace Glory
{

    class GLORY_API EventQueue
    {
    public:
        void Push(std::unique_ptr<Event> event)
        {
            m_EventQueue.push(std::move(event));
        }
        std::unique_ptr<Event> Pop();

    private:
        std::queue<std::unique_ptr<Event>> m_EventQueue;
    };

} // namespace Glory
