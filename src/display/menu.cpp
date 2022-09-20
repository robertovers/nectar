#include "menu.hpp"

void Menu::moveUnseenWindow(int windowX, int windowY) {
    auto statsWindowPos = ImGui::GetWindowPos();
    if (statsWindowPos.x > windowX or statsWindowPos.y > windowY) {
        ImGui::SetWindowPos(defaultPosition);
    }
}
