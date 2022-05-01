//
//  Application.hpp
//  OpenglLearn
//
//  Created by 弋倩龙 on 2022/4/24.
//

#ifndef Application_hpp
#define Application_hpp
#include "Base.hpp"
#include "Events/ApplicationEvent.hpp"
#include "Log.hpp"
#include "Window.hpp"
#include "LayerStack.hpp"
namespace Hazel {
class Application{
public:
    Application();
    virtual ~Application();
    void PushLayer(Layer* layer);
    void PushOverLay(Layer* layer);
    
    void Run();
    void OnEvent(Event& e);
    bool OnWindowClose(WindowCloseEvent& e);
private:
    Scope<Window> m_Window;
    LayerStack m_LayerStack;
    bool m_Running=true;
};
//to be defined in client
Application* CreateApplication();
}

#endif /* Application_hpp */
