//
//  Application.cpp
//  OpenglLearn
//
//  Created by 弋倩龙 on 2022/4/24.
//

#include "Application.hpp"
namespace Hazel{
#define BIND_EVENT_FN(x) std::bind(&Application::x, this,std::placeholders::_1)
Application::Application(){
    m_Window = Window::Create();
    m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
}
void Application::OnEvent(Event &e){
    EventDispatcher dispatcher(e);
    dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));
    
    HZ_CORE_INFO("Application {0}",e.ToString());
    
    for(auto it = m_LayerStack.end();it!=m_LayerStack.begin();){
        (*--it)->OnEvent(e);
        if(e.Handled)break;
    }
}
Application::~Application(){}
void Application::Run(){
    while(m_Running){
        glClearColor(1.f,0.f,1.f,1.f);
        glClear(GL_COLOR_BUFFER_BIT);
        for(auto it=m_LayerStack.begin();it!=m_LayerStack.end();++it)
        (*it)->OnUpdate();
        m_Window->OnUpdate();
        
    }
}

bool Application::OnWindowClose(WindowCloseEvent &e){
    m_Running = false;
    return true;
}

void Application::PushLayer(Layer *layer){
    m_LayerStack.PushLayer(layer);
    layer->OnAttach();
}
void Application::PushOverLay(Layer* layer){
    m_LayerStack.PushOverlay(layer);
    layer->OnAttach();
}
};
