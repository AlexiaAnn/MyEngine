//
//  WindowInput.cpp
//  OpenglLearn
//
//  Created by 弋倩龙 on 2022/5/1.
//

#include "WindowInput.hpp"
#include "Application.hpp"
namespace Hazel{
Input* Input::s_InputInstance = new MacWindowInput();
bool MacWindowInput::IsKeyPressedImpl(int keycode){
    auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
    auto state = glfwGetKey(window, keycode);
    return state==GLFW_PRESS||state==GLFW_REPEAT;
}
bool MacWindowInput::IsMouseButtonPressedImpl(int button){
    auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
    auto state = glfwGetKey(window, static_cast<int32_t>(button));
    return state==GLFW_PRESS;
}
std::pair<float,float> MacWindowInput::GetMousePositionImpl(){
    auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
    double xpos,ypos;
    glfwGetCursorPos(window, &xpos, &ypos);
    return {(float)xpos,(float)ypos};
}
float MacWindowInput::GetMouseXImpl(){
    return GetMousePositionImpl().first;
}
float MacWindowInput::GetMouseYImpl(){
    return GetMousePositionImpl().second;
}

}
