//
//  MacWindow.hpp
//  OpenglLearn
//
//  Created by 弋倩龙 on 2022/4/25.
//

#ifndef MacWindow_hpp
#define MacWindow_hpp

#include "Window.hpp"
#include "Base.hpp"
#include "GraphicsContext.hpp"
namespace Hazel{
class MacWindow:public Window{
public:
    MacWindow(const WindowProps& props);
    virtual ~MacWindow();
    void OnUpdate() override;
    unsigned int GetWidth() const override{return m_Data.Width;}
    unsigned int GetHeight() const override{return m_Data.Height;}

    //window attributes
    void SetEventCallback(const EventCallbackFn& callback) override{m_Data.EventCallback=callback;}
    void SetVSync(bool enabled) override;
    bool IsVSync() const override;
    
    virtual void* GetNativeWindow() const override  {return m_Window;}
private:
    virtual void Init(const WindowProps& props);
    virtual void Shutdown();
private:
    GLFWwindow* m_Window;
    Scope<GraphicsContext> m_Context;
    struct WindowData{
        std::string Title;
        unsigned int Width,Height;
        bool VSync;
        EventCallbackFn EventCallback;
    };
    WindowData m_Data;
    
};
}

#endif /* MacWindow_hpp */
