/**
 * FIT3161/3162 Computer Science Project
 * Insect Simulation for Improved Pollination and Pest Control
 * Group CS6
 *
 * @file menu.cpp
 * @brief Abstract imgui-based window class  that displays within the main application window
 * @date 2022-09-20
 */
#include "menu.hpp"

void Menu::moveUnseenWindow(int windowX, int windowY) {
    auto statsWindowPos = ImGui::GetWindowPos();
    if (statsWindowPos.x > windowX or statsWindowPos.y > windowY) {
        ImGui::SetWindowPos(defaultPosition);
    }
}
