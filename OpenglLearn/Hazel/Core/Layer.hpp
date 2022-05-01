//
//  Layer.hpp
//  OpenglLearn
//
//  Created by 弋倩龙 on 2022/5/1.
//

#ifndef Layer_hpp
#define Layer_hpp

#include "Base.hpp"
#include "Event.hpp"
namespace Hazel{
class Layer{
public:
    Layer(const std::string& name = "Layer"):m_DebugName(name){}
    virtual ~Layer()=default;
    virtual void OnAttach(){}
    virtual void OnDetach(){}
    virtual void OnUpdate(){}
    virtual void OnImGuiRender(){}
    virtual void OnEvent(Event& event){}
    const std::string& GetName()const{return m_DebugName;}
private:
    std::string m_DebugName;
};
}

#endif /* Layer_hpp */
