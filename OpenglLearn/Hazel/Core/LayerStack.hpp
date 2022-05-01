//
//  LayerStack.hpp
//  OpenglLearn
//
//  Created by 弋倩龙 on 2022/5/1.
//

#ifndef LayerStack_hpp
#define LayerStack_hpp

#include "Base.hpp"
#include "Layer.hpp"

namespace Hazel{
class LayerStack{
public:
    LayerStack()=default;
    ~LayerStack();
    
    void PushLayer(Layer* layer);
    void PushOverlay(Layer* layer);
    void PopLayer(Layer* layer);
    void PopOverlay(Layer* layer);
    
    std::vector<Layer*>::iterator begin(){return m_Layers.begin();}
    std::vector<Layer*>::iterator end(){return m_Layers.end();}
private:
    std::vector<Layer*> m_Layers;
    unsigned int m_LayerInsertIndex = 0;
};
}
#endif /* LayerStack_hpp */
