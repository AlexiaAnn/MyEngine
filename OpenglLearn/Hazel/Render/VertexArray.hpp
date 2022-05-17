//
//  VertexArray.hpp
//  OpenglLearn
//
//  Created by 弋倩龙 on 2022/5/6.
//

#ifndef VertexArray_hpp
#define VertexArray_hpp

#include "Buffer.hpp"
namespace Hazel{
class VertexArray{
public:
    virtual ~VertexArray()=default;
    virtual void Bind() const=0;
    virtual void Unbind() const=0;
    
    virtual void AddVertexBuffer (const Ref<VertexBuffer>& vertexBuffer)=0;
    virtual void SetIndexBuffer (const Ref<IndexBuffer>& indexBuffer)=0;
    
    virtual const std::vector<Ref<VertexBuffer>>& GetVertexBuffer() const = 0;
    virtual const Ref<IndexBuffer>& GetIndexBuffer() const = 0;
    
    static Ref<VertexArray> Create();
};
}

#endif /* VertexArray_hpp */
