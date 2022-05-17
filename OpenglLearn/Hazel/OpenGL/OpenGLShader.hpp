//
//  OpenGLShader.hpp
//  OpenglLearn
//
//  Created by 弋倩龙 on 2022/5/6.
//

#ifndef OpenGLShader_hpp
#define OpenGLShader_hpp

#include "Shader.hpp"
#include "Base.hpp"
#include "Log.hpp"
#include "Instrumentor.hpp"
namespace Hazel{
class OpenGLShader:public Shader{
public:
    OpenGLShader(const std::string& name,const std::string& vertexSrc,const std::string& fragmentSrc);
    virtual ~OpenGLShader();
    virtual void Bind() const override;
    virtual void Unbind() const override;
            

    virtual void SetInt(const std::string& name, int value) override;
    virtual void SetIntArray(const std::string& name, int* values, uint32_t count) override;
    virtual void SetFloat(const std::string& name, float value) override;
    virtual void SetFloat2(const std::string& name, const glm::vec2& value) override;
    virtual void SetFloat3(const std::string& name, const glm::vec3& value) override;
    virtual void SetFloat4(const std::string& name, const glm::vec4& value) override;
    virtual void SetMat4(const std::string& name, const glm::mat4& value) override;

    virtual const std::string& GetName() const override { return m_Name; }
private:
    std::string ReadFile(const std::string& filepath);
    void CheckCompileError(GLuint shader,std::string type);
private:
    uint32_t m_RendererID;
    std::string m_Name;
};
}

#endif /* OpenGLShader_hpp */
