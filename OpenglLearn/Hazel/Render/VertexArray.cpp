//
//  VertexArray.cpp
//  OpenglLearn
//
//  Created by 弋倩龙 on 2022/5/6.
//

#include "VertexArray.hpp"
#include "OpenGLVertexArray.hpp"
#include "Renderer.hpp"
namespace Hazel{
Ref<VertexArray> VertexArray::Create(){
    switch (Renderer::GetAPI()) {
        case RendererAPI::API::None:
            HZ_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
        case RendererAPI::API::OpenGL:
            return CreateRef<OpenGLVertexArray>();
    }
    HZ_CORE_ASSERT(false, "Unknown RendererAPI!");
    return nullptr;
}
}
