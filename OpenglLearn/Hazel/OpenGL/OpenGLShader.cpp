//
//  OpenGLShader.cpp
//  OpenglLearn
//
//  Created by 弋倩龙 on 2022/5/6.
//

#include "OpenGLShader.hpp"
#include <glm/gtc/type_ptr.hpp>
namespace Hazel{
std::string OpenGLShader::ReadFile(const std::string &filepath){
    std::string code;
    std::ifstream shaderFile;
    shaderFile.exceptions(std::ifstream::failbit|std::ifstream::badbit);
    try{
        shaderFile.open(filepath);
        std::stringstream shaderStream;
        shaderStream<<shaderFile.rdbuf();
        shaderFile.close();
        code = shaderStream.str();
        
    }catch(std::ifstream::failure& e){
        HZ_CORE_ERROR("ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ");
    }
    return code;
}
void OpenGLShader::CheckCompileError(GLuint shader, std::string type){
    GLint success;
    GLchar infoLog[1024];
    if(type != "PROGRAM")
    {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if(!success)
        {
            glGetShaderInfoLog(shader, 1024, NULL, infoLog);
            std::stringstream ss;
            ss<< "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog;
            HZ_CORE_ERROR(ss.str());
        }
    }
    else{
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
        if(!success)
        {
            glGetProgramInfoLog(shader, 1024, NULL, infoLog);
            std::stringstream ss;
            ss << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog;
            HZ_CORE_ERROR(ss.str());
        }
    }
}
OpenGLShader::OpenGLShader(const std::string& name,const std::string& vertexSrc,const std::string& fragmentSrc):m_Name(name){
    std::string vertexCode = ReadFile(vertexSrc);
    std::string fragmentCode = ReadFile(fragmentSrc);
    const char* vCode = vertexCode.c_str();
    const char* fCode = fragmentCode.c_str();
    unsigned int vertex,fragment;
    //vertex shader
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex,1,&vCode,NULL);
    glCompileShader(vertex);
    CheckCompileError(vertex, "VERTEX");
    //fragment shader
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment,1,&fCode,NULL);
    glCompileShader(fragment);
    CheckCompileError(fragment, "FRAGMENT");
    //create and link
    m_RendererID = glCreateProgram();
    glAttachShader(m_RendererID,vertex);
    glAttachShader(m_RendererID,fragment);
    glLinkProgram(m_RendererID);
    CheckCompileError(m_RendererID, "PROGRAM");
    glDeleteShader(vertex);
    glDeleteShader(fragment);
}
OpenGLShader::~OpenGLShader(){
    HZ_PROFILE_FUNCTION();
    glDeleteProgram(m_RendererID);
}
void OpenGLShader::Bind() const{
    HZ_PROFILE_FUNCTION();
    glUseProgram(m_RendererID);
}
void OpenGLShader::Unbind() const{
    HZ_PROFILE_FUNCTION();
    glUseProgram(0);
}
void OpenGLShader::SetInt(const std::string &name, int value){
    HZ_PROFILE_FUNCTION();
    glUniform1i(glGetUniformLocation(m_RendererID,name.c_str()),value);
}
void OpenGLShader::SetIntArray(const std::string &name, int *values, uint32_t count){
    HZ_PROFILE_FUNCTION();
    glUniform1iv(glGetUniformLocation(m_RendererID,name.c_str()),count,values);
}
void OpenGLShader::SetFloat(const std::string &name, float value){
    HZ_PROFILE_FUNCTION();
    glUniform1f(glGetUniformLocation(m_RendererID,name.c_str()),value);
}
void OpenGLShader::SetFloat2(const std::string &name, const glm::vec2 &value){
    HZ_PROFILE_FUNCTION();
    glUniform2f(glGetUniformLocation(m_RendererID,name.c_str()),value.x,value.y);
}
void OpenGLShader::SetFloat3(const std::string &name, const glm::vec3 &value){
    HZ_PROFILE_FUNCTION();
    glUniform3f(glGetUniformLocation(m_RendererID,name.c_str()),value.x,value.y,value.z);
}
void OpenGLShader::SetFloat4(const std::string &name, const glm::vec4 &value){
    HZ_PROFILE_FUNCTION();
    glUniform4f(glGetUniformLocation(m_RendererID,name.c_str()),value.x,value.y,value.z,value.w);
}
void OpenGLShader::SetMat4(const std::string &name, const glm::mat4 &value){
    HZ_PROFILE_FUNCTION();
    GLint location = glGetUniformLocation(m_RendererID,name.c_str());
    glUniformMatrix4fv(location,1,GL_FALSE,glm::value_ptr(value));
}

}
