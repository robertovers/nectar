#include "legendsWindow.hpp"

void LegendsWindow::draw(int windowX, int windowY) {
    auto nectarColor = ImVec4(187 / 255.0f, 205 / 255.0f, 17 / 255.0f, 255 / 255.0f); //sf::Color(187, 205, 17);
    ImGui::Begin("Display Options");
    ImGui::ColorEdit3("MyColor##1", (float*)&nectarColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
    /*ImGui::SameLine(); HelpMarker(
        "With the ImGuiColorEditFlags_NoInputs flag you can hide all the slider/text inputs.\n"
        "With the ImGuiColorEditFlags_NoLabel flag you can pass a non-empty label which will only "
        "be used for the tooltip and picker popup.");*/
    ImGui::End();
}
