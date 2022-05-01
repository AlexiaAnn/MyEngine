//
//  RenderAPI.hpp
//  OpenglLearn
//
//  Created by 弋倩龙 on 2022/4/25.
//

#ifndef RenderAPI_hpp
#define RenderAPI_hpp

namespace Hazel{
class RendererAPI{
public:
    enum class API{None=0,OpenGL=1};
    static API GetAPI(){return s_API;}
private:
    static API s_API;
};
};

#endif /* RenderAPI_hpp */
