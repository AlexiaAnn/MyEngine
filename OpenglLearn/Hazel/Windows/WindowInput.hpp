//
//  WindowInput.hpp
//  OpenglLearn
//
//  Created by 弋倩龙 on 2022/5/1.
//

#ifndef WindowInput_hpp
#define WindowInput_hpp

#include "Base.hpp"
#include "Input.hpp"
namespace Hazel{
class MacWindowInput:public Input{
protected:
    bool IsKeyPressedImpl(int keycode) override;
    bool IsMouseButtonPressedImpl(int button) override;
    std::pair<float,float> GetMousePositionImpl() override;
    float GetMouseXImpl() override;
    float GetMouseYImpl() override;
};
}
#endif /* WindowInput_hpp */
