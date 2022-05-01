//
//  OpenGLContext.cpp
//  OpenglLearn
//
//  Created by 弋倩龙 on 2022/4/25.
//

#include "OpenGLContext.hpp"
namespace Hazel{
OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
        : m_WindowHandle(windowHandle)
{
        HZ_CORE_ASSERT(windowHandle, "Window handle is null!")
}
void OpenGLContext::Init()
{
        glfwMakeContextCurrent(m_WindowHandle);
        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        HZ_CORE_ASSERT(status,"Failed to initialize Glad!");
        HZ_CORE_INFO("OpenGL Info:");
        HZ_CORE_INFO("  Vendor:{0}",glGetString(GL_VENDOR));
        HZ_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
	HZ_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));

        HZ_CORE_ASSERT(GLVersion.major > 4 || (GLVersion.major == 4 && GLVersion.minor >= 5), "Hazel requires at least OpenGL version 4.5!");
}

void OpenGLContext::SwapBuffers()
{
        glfwSwapBuffers(m_WindowHandle);
}
}
