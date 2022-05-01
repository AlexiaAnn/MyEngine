//
//  Renderer.hpp
//  OpenglLearn
//
//  Created by 弋倩龙 on 2022/4/25.
//

#ifndef Renderer_hpp
#define Renderer_hpp

#include "RenderAPI.hpp"
namespace Hazel{
class Renderer{
public:
    static RendererAPI::API GetAPI(){return RendererAPI::GetAPI();}
};
}

#endif /* Renderer_hpp */
