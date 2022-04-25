#pragma one

#include "Event.hpp"
#include "Core/KeyCodes.hpp"

namespace Hazel{
class KeyEvent:public Event{
public:
    KeyCode GetKeyCode() const {return m_Keycode;}
    EVENT_CLASS_CATEGORY(EventCategoryKeyboard|EventCategoryInput)
protected:
    KeyEvent(const KeyCode keycode):m_Keycode(keycode){}
    KeyCode m_Keycode;
};
class KeyPressedEvent:public KeyEvent{
public:
    KeyPressedEvent(const KeyCode keycode,const uint16_t repeatCount)
    :KeyEvent(keycode),m_RepeatCount(repeatCount){}

    uint16_t GetRepeatCount() const {return m_RepeatCount;}

    std::string ToString() const override{
        std::stringstream ss;
        ss<<"KeyPressedEvent:"<<m_Keycode<<"("<<m_RepeatCount<<" repeats)";
        return ss.str();
    };

    EVENT_CLASS_TYPE(KeyPressed)
private:
    uint16_t m_RepeatCount;
};
class KeyReleasedEvent:public KeyEvent{
public:
    KeyReleasedEvent(cosnt KeyCode keycode):KeyEvent(KeyCode){}
    std::string ToString() const override{
        std::stringstream ss;
        ss<<"KeyReleasedEvent: "<<m_Keycode;
        return ss.str();
    };
    EVENT_CLASS_TYPE(KeyReleased);
};
class KeyTypedEvent : public KeyEvent
	{
	public:
		KeyTypedEvent(const KeyCode keycode)
			: KeyEvent(keycode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyTypedEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyTyped)
	};
};
