#include "LayerStack.hpp"

namespace Glory
{

    LayerStack::LayerStack(/* args */)
    {
        m_LayerInsertPos = m_LayerStack.begin();
    }

    LayerStack::~LayerStack()
    {
        for (auto *layer : m_LayerStack)
            delete layer;
        m_LayerStack.clear();
    }

    void LayerStack::PushLayer(Layer *layer)
    {
        m_LayerStack.emplace(m_LayerInsertPos, layer);
    }

    void LayerStack::PushOverlay(Layer *overlay)
    {
        m_LayerStack.push_back(overlay);
    }

    void LayerStack::PopLayer(Layer *layer)
    {
        auto it = std::find(m_LayerStack.begin(), m_LayerStack.end(), layer);
        if (it == m_LayerStack.end())
            return;
        m_LayerStack.erase(it);
        m_LayerInsertPos--;
    }

    void LayerStack::PopOverlay(Layer *overlay)
    {
        auto it = std::find(m_LayerStack.begin(), m_LayerStack.end(), overlay);
        if (it == m_LayerStack.end())
            return;
        m_LayerStack.erase(it);
    }

} // namespace Glory
