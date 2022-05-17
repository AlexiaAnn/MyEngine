//
//  Application.cpp
//  OpenglLearn
//
//  Created by 弋倩龙 on 2022/4/24.
//

#include "Application.hpp"
namespace Hazel{
Application* Application::s_Instance=nullptr;
#define BIND_EVENT_FN(x) std::bind(&Application::x, this,std::placeholders::_1)
Application::Application(){
    s_Instance = this;
    m_Window = Window::Create();
    m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
}
void Application::OnEvent(Event &e){
    return;
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
    Ref<VertexArray> vao = VertexArray::Create();
    float vertices[]={
        0,0.5,0,1,0,0,
        -0.5,-0.5,0,0,1,0,
        0.5,-0.5,0,0,0,1
    };
    Ref<VertexBuffer> vbo = VertexBuffer::Create(vertices, sizeof(vertices));
    BufferLayout layout={
        BufferElement(ShaderDataType::Float3, std::string("aPos")),
        BufferElement(ShaderDataType::Float3,std::string("aColor"))
    };
    vbo->SetLayout(layout);
    vao->AddVertexBuffer(vbo);
    Ref<Shader> shader = Shader::Create("shader", "Shader/vertex.glsl", "Shader/fragment.glsl");
    while(m_Running){
        glClearColor(1.f,0.f,1.f,1.f);
        glClear(GL_COLOR_BUFFER_BIT);
        shader->Bind();
        vao->Bind();
        glDrawArrays(GL_TRIANGLES,0,3);
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
