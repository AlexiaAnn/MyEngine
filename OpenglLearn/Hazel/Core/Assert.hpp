//
//  Assert.hpp
//  OpenglLearn
//
//  Created by 弋倩龙 on 2022/4/25.
//

#ifndef Assert_hpp
#define Assert_hpp

#include "Base.hpp"
#include "Log.hpp"
#ifdef HZ_ENABLE_ASSERTS
    #define HZ_ASSERT(x,...) {if(!x){HZ_ERROR("Assertion Failed:{0}",__VA_ARGS__);__debugbreak();}}
    #define HZ_CORE_ASSERT(x,...) {if(!x){HZ_CORE_ERROR("Assertion Failed:{0}",__VA_ARGS__);__debugbreak();}}
#else
    #define HZ_ASSERT(...)
    #define HZ_CORE_ASSERT(...)
#endif

#endif /* Assert_hpp */
