#pragma once
#include "pchge.hpp"
#include "Glory/Core.hpp"
#include "Glory/Event/Event.hpp"
#include "Glory/Event/EventListener.hpp"
#include "Glory/Event/EventQueue.hpp"
#include "Glory/Event/EventListenerRegister.hpp"
#include "Glory/Event/EventBus.hpp"

namespace Glory
{

    class GLORY_API EventManager
    {

    public:
        static EventManager &GetInstance()
        {
            static EventManager instance;
            return instance;
        }

        EventManager(const EventManager &) = delete;
        EventManager &operator=(const EventManager &) = delete;
        template <typename EventType>
            requires std::derived_from<EventType, Event> // C++20
        ID_t RegisterEventListenerFor(const typename EventListener<EventType>::EventHandler &callBack)
        {
            return m_EventBuss.RegisterEventListenerFor<EventType>(callBack);
        }
        void UnregisterEventListener(const ID_t &id);

        void PublishEvent();
        template <typename T, typename... Args>
            requires std::derived_from<T, Event> // C++20
        void PushEvent(Args &&...args)
        {
            m_EventQueue.Push(std::make_unique<T>(std::forward<Args>(args)...));
        }

    private:
        EventManager() = default;
        ~EventManager() = default;
        EventBuss m_EventBuss;
        EventQueue m_EventQueue;
    };

} // namespace Glory
