#include "Hazel/Hazel.hpp"

class ExampleLayer:public Hazel::Layer{
public:
    ExampleLayer():Layer("Example"){}
    void OnUpdate() override{
        HZ_INFO("ExampleLayer::Update");
    }
    void OnEvent(Hazel::Event& event) override{
        HZ_TRACE("ExampleLayer {0}",event.ToString());
    }
};
class Sandbox:public Hazel::Application{
public:
    Sandbox(){}
    ~Sandbox(){}
};
Hazel::Application* Hazel::CreateApplication(){
    return new Sandbox();
}
