//
//  OpenGLBuffer.cpp
//  OpenglLearn
//
//  Created by 弋倩龙 on 2022/5/7.
//

#include "OpenGLBuffer.hpp"
namespace Hazel{
//OpenGLVertexBuffer//////////////////////////////////////////////////
OpenGLVertexBuffer::OpenGLVertexBuffer(uint32_t size){
    HZ_PROFILE_FUNCTION();
    glGenBuffers(1,&m_RendererID);
    glBindBuffer(GL_ARRAY_BUFFER,m_RendererID);
    glBufferData(GL_ARRAY_BUFFER,size,nullptr,GL_DYNAMIC_DRAW);
}
OpenGLVertexBuffer::OpenGLVertexBuffer(float* vertices,uint32_t size){
    HZ_PROFILE_FUNCTION();
    glGenBuffers(1,&m_RendererID);
    glBindBuffer(GL_ARRAY_BUFFER,m_RendererID);
    glBufferData(GL_ARRAY_BUFFER,size,vertices,GL_STATIC_DRAW);
}
OpenGLVertexBuffer::~OpenGLVertexBuffer(){
    HZ_PROFILE_FUNCTION();
    glDeleteBuffers(1,&m_RendererID);
}
void OpenGLVertexBuffer::Bind() const{
    HZ_PROFILE_FUNCTION();
    glBindBuffer(GL_ARRAY_BUFFER,m_RendererID);
};
void OpenGLVertexBuffer::Unbind() const{
    HZ_PROFILE_FUNCTION();
    glBindBuffer(GL_ARRAY_BUFFER,0);
}
void OpenGLVertexBuffer::SetData(const void *data, uint32_t size){
    HZ_PROFILE_FUNCTION();
    glBindBuffer(GL_ARRAY_BUFFER,m_RendererID);
    glBufferSubData(GL_ARRAY_BUFFER,0,size,data);
}
//OpenGLIndexBuffer//////////////////////////////////////////////////
OpenGLIndexBuffer::OpenGLIndexBuffer(uint32_t* indices,uint32_t count):m_Count(count){
    HZ_PROFILE_FUNCTION();
    glGenBuffers(1,&m_RendererID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,m_RendererID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,count*sizeof(uint32_t),indices,GL_STATIC_DRAW);
}
OpenGLIndexBuffer::~OpenGLIndexBuffer(){
    HZ_PROFILE_FUNCTION();
    glDeleteBuffers(1,&m_RendererID);
}
void OpenGLIndexBuffer::Bind() const{
    HZ_PROFILE_FUNCTION();
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,m_RendererID);
}
void OpenGLIndexBuffer::Unbind() const{
    HZ_PROFILE_FUNCTION();
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
}
}
