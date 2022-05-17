//
//  Base.hpp
//  OpenglLearn
//
//  Created by 弋倩龙 on 2022/4/25.
//

#ifndef Base_hpp
#define Base_hpp
#include <memory>
#include <iostream>
#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <map>
#include <unordered_map>

#include <sstream>
#include <fstream>
#include <string>

namespace Hazel{
template <typename T>
using Scope = std::unique_ptr<T>;
template <typename T,typename ... Args>
constexpr Scope<T> CreateScope(Args&& ... args){
    return std::make_unique<T>(std::forward<Args>(args)...);
}
template <typename T>
using Ref = std::shared_ptr<T>;
template<typename T,typename ... Args>
constexpr Ref<T> CreateRef(Args&& ... args){
    return std::make_shared<T>(std::forward<Args>(args)...);
}
}

#include "Log.hpp"
#include "Assert.hpp"
#include "Instrumentor.hpp"
#endif /* Base_hpp */
