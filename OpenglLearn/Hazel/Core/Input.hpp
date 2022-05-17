#pragma once

#include "Base.hpp"
namespace Hazel{
class Input{
public:
    static bool IsKeyPressed(int keycode){return s_InputInstance->IsKeyPressedImpl(keycode);}
    static bool IsMouseButtonPressed(int button){return s_InputInstance->IsMouseButtonPressedImpl(button);}
    static std::pair<float,float> GetMousePosition(){return s_InputInstance->GetMousePositionImpl();}
    static float GetMouseX(){return s_InputInstance->GetMouseXImpl();}
    static float GetMouseY(){return s_InputInstance->GetMouseYImpl();}
protected:
    virtual bool IsKeyPressedImpl(int keycode)=0;
    virtual bool IsMouseButtonPressedImpl(int button)=0;
    virtual std::pair<float, float> GetMousePositionImpl()=0;
    virtual float GetMouseXImpl()=0;
    virtual float GetMouseYImpl()=0;
private:
    static Input* s_InputInstance;
};
}
