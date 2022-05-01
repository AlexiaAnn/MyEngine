//
//  Event.hpp
//  OpenglLearn
//
//  Created by 弋倩龙 on 2022/4/24.
//

#ifndef Event_hpp
#define Event_hpp

#include <functional>
#include <sstream>
namespace Hazel{
#define BIT(x) (1<<x)
enum class EventType{
    None = 0,
    WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
    AppTick, AppUpdate, AppRender,
    KeyPressed, KeyReleased, KeyTyped,
    MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
};
enum EventCategory
{
    None = 0,
    EventCategoryApplication    = BIT(0),
    EventCategoryInput          = BIT(1),
    EventCategoryKeyboard       = BIT(2),
    EventCategoryMouse          = BIT(3),
    EventCategoryMouseButton    = BIT(4)
};
#define EVENT_CLASS_TYPE(type)\
static EventType GetStaticType(){return EventType::type;}\
virtual EventType GetEventType() const override{return GetStaticType();}\
virtual const char* GetName() const override{return #type;}
#define EVENT_CLASS_CATEGORY(category)\
virtual int GetCategoryFlags() const override{return category;}
class Event{
public:
    bool Handled = false;
    
    virtual ~Event()=default;
    virtual EventType GetEventType() const =0;
    virtual const char* GetName() const=0;
    virtual int GetCategoryFlags() const=0;
    virtual std::string ToString() const {return GetName();}
};
class EventDispatcher{
public:
    EventDispatcher(Event& event):m_Event(event){}
    template<typename T,typename F>
    bool Dispatch(const F& func){
        if(m_Event.GetEventType()==T::GetStaticType()){
            m_Event.Handled|=func(static_cast<T&>(m_Event));
            return true;
        }
        return false;
    }
private:
    Event& m_Event;
};

}

#endif /* Event_hpp */
