//
//  OpenGLContext.hpp
//  OpenglLearn
//
//  Created by 弋倩龙 on 2022/4/25.
//

#ifndef OpenGLContext_hpp
#define OpenGLContext_hpp
#include "GraphicsContext.hpp"
#include "Assert.hpp"
#include "Log.hpp"
namespace Hazel {
class OpenGLContext : public GraphicsContext
{
public:
    OpenGLContext(GLFWwindow* windowHandle);

    virtual void Init() override;
    virtual void SwapBuffers() override;
private:
    GLFWwindow* m_WindowHandle;
};

}

#endif /* OpenGLContext_hpp */
