//
//  Window.cpp
//  OpenglLearn
//
//  Created by 弋倩龙 on 2022/4/25.
//

#include "Window.hpp"
#include "MacWindow.hpp"
namespace Hazel{
Scope<Window> Window::Create(const WindowProps& props){
    return CreateScope<MacWindow>(props);
}
}
