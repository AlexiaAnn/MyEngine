//
//  Application.cpp
//  OpenglLearn
//
//  Created by 弋倩龙 on 2022/4/24.
//

#include "Application.hpp"
namespace Hazel{
Application::Application(){}
Application::~Application(){}
void Application::Run(){
    std::cout<<"application is running"<<std::endl;
    WindowResizeEvent e(100, 200);
    HZ_TRACE(e.ToString());
}
};
