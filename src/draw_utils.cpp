#include "draw_utils.h"

void DrawFilledBox(float x, float y, float width, float height, ImU32 color)
{
    ImGui::GetForegroundDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(x + width, y + height), color);
}
