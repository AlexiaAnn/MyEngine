//
//  GraphicsContext.hpp
//  OpenglLearn
//
//  Created by 弋倩龙 on 2022/4/25.
//

#ifndef GraphicsContext_hpp
#define GraphicsContext_hpp
#include "Base.hpp"
namespace Hazel{
class GraphicsContext{
public:
    virtual ~GraphicsContext() = default;
    virtual void Init()=0;
    virtual void SwapBuffers() = 0;
    static Scope<GraphicsContext> Create(void* Window);
};
}

#endif /* GraphicsContext_hpp */
