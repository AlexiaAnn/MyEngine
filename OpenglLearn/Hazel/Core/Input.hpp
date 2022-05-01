#pragma once

#include <glm/glm.hpp>
#include "KeyCodes.hpp"
#include "MouseCodes.hpp"

namespace Hazel{
class Input{
public:
    static bool IsKeyPressed(KeyCode key);
    static bool IsMouseButtonPressed(MouseCode button);
    static glm::vec2 GetMousePosition();
    static float GetMouseX();
    static float GetMouseY();
};
}