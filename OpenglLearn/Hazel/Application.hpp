//
//  Application.hpp
//  OpenglLearn
//
//  Created by 弋倩龙 on 2022/4/24.
//

#ifndef Application_hpp
#define Application_hpp
#include <iostream>
#include "Events/ApplicationEvent.hpp"
#include "Log.hpp"
namespace Hazel {
class Application{
public:
    Application();
    virtual ~Application();
    void Run();
};
//to be defined in client
Application* CreateApplication();
}

#endif /* Application_hpp */
