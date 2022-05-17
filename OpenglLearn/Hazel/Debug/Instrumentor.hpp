//
//  Instrumentor.hpp
//  OpenglLearn
//
//  Created by 弋倩龙 on 2022/5/6.
//

#ifndef Instrumentor_hpp
#define Instrumentor_hpp

#define HZ_PROFILE 0
#if HZ_PROFILE
    // Resolve which function signature macro will be used. Note that this only
    // is resolved when the (pre)compiler starts, so the syntax highlighting
    // could mark the wrong one in your editor!
    #if defined(__GNUC__) || (defined(__MWERKS__) && (__MWERKS__ >= 0x3000)) || (defined(__ICC) && (__ICC >= 600)) || defined(__ghs__)
        #define HZ_FUNC_SIG __PRETTY_FUNCTION__
    #elif defined(__DMC__) && (__DMC__ >= 0x810)
        #define HZ_FUNC_SIG __PRETTY_FUNCTION__
    #elif (defined(__FUNCSIG__) || (_MSC_VER))
        #define HZ_FUNC_SIG __FUNCSIG__
    #elif (defined(__INTEL_COMPILER) && (__INTEL_COMPILER >= 600)) || (defined(__IBMCPP__) && (__IBMCPP__ >= 500))
        #define HZ_FUNC_SIG __FUNCTION__
    #elif defined(__BORLANDC__) && (__BORLANDC__ >= 0x550)
        #define HZ_FUNC_SIG __FUNC__
    #elif defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901)
        #define HZ_FUNC_SIG __func__
    #elif defined(__cplusplus) && (__cplusplus >= 201103)
        #define HZ_FUNC_SIG __func__
    #else
        #define HZ_FUNC_SIG "HZ_FUNC_SIG unknown!"
    #endif

    #define HZ_PROFILE_BEGIN_SESSION(name, filepath) ::Hazel::Instrumentor::Get().BeginSession(name, filepath)
    #define HZ_PROFILE_END_SESSION() ::Hazel::Instrumentor::Get().EndSession()
    #define HZ_PROFILE_SCOPE_LINE2(name, line) constexpr auto fixedName##line = ::Hazel::InstrumentorUtils::CleanupOutputString(name, "__cdecl ");\
                                               ::Hazel::InstrumentationTimer timer##line(fixedName##line.Data)
    #define HZ_PROFILE_SCOPE_LINE(name, line) HZ_PROFILE_SCOPE_LINE2(name, line)
    #define HZ_PROFILE_SCOPE(name) HZ_PROFILE_SCOPE_LINE(name, __LINE__)
    #define HZ_PROFILE_FUNCTION() HZ_PROFILE_SCOPE(HZ_FUNC_SIG)
#else
    #define HZ_PROFILE_BEGIN_SESSION(name, filepath)
    #define HZ_PROFILE_END_SESSION()
    #define HZ_PROFILE_SCOPE(name)
    #define HZ_PROFILE_FUNCTION()
#endif

#endif /* Instrumentor_hpp */
