#pragma once

#include "pchge.hpp"

#include "Glory/Core.hpp"
#include "Glory/Event/Event.hpp"
#include "Glory/Layer.hpp"

namespace Glory
{
    class LayerStack
    {
    public:
        LayerStack();
        ~LayerStack();

        void PushLayer(Layer *layer);
        void PushOverlay(Layer *overlay);
        void PopLayer(Layer *layer);
        void PopOverlay(Layer *overlay);

        auto begin() { return m_LayerStack.begin(); }
        auto begin() const { return m_LayerStack.begin(); }
        auto end() { return m_LayerStack.end(); }
        auto end() const { return m_LayerStack.end(); }
    private:
        std::vector<Layer *> m_LayerStack;
        std::vector<Layer *>::iterator m_LayerInsertPos;
    };

} // namespace Glory
