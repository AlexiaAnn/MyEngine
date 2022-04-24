//
//  EntryPoint.hpp
//  OpenglLearn
//
//  Created by 弋倩龙 on 2022/4/24.
//

#ifndef EntryPoint_hpp
#define EntryPoint_hpp

extern Hazel::Application* Hazel::CreateApplication();

int main(){
    Hazel::Log::Init();
    HZ_CORE_WARN("initialized log!");
    HZ_INFO("HELLO!");
    auto app = Hazel::CreateApplication();
    app->Run();
    delete app;
}
#endif /* EntryPoint_hpp */
