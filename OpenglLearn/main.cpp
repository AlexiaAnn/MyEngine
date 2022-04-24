#include "Hazel/Hazel.hpp"

class Sandbox:public Hazel::Application{
public:
    Sandbox(){}
    ~Sandbox(){}
};
Hazel::Application* Hazel::CreateApplication(){
    return new Sandbox();
}
