#include "legendsWindow.hpp"

void LegendsWindow::draw(int windowX, int windowY) {
    auto soybeanColor = ImVec4(0 / 255.0f, 50 / 255.0f, 35 / 255.0f, 255 / 255.0f); // 0, 50, 35
    auto nectarColor = ImVec4(187 / 255.0f, 205 / 255.0f, 17 / 255.0f, 255 / 255.0f); //sf::Color(187, 205, 17);
    auto pollenColor = ImVec4(247 / 255.0f, 215 / 255.0f, 90 / 255.0f, 255 / 255.0f); // (247, 215, 90)
    auto hiveColor = ImVec4(255 / 255.0f, 0 / 255.0f, 0 / 255.0f, 255 / 255.0f);
    //auto hiveColor = ImVec4();
    ImGui::Begin("Display Options");
    // 1. Plant options
    ImGui::ColorEdit3("Soybean", (float*)&soybeanColor, ImGuiColorEditFlags_NoInputs);
    ImGui::SameLine(); 
    if (ImGui::Button("Reset##1")) {

    }

    // 2. nectar options
    // TODO: header
    // TODO: reset color
    // todo: toggle overlay display (radio buttons
    ImGui::ColorEdit3("Soybean with max nectar", (float*)&nectarColor, ImGuiColorEditFlags_NoInputs);
    ImGui::SameLine();
    if (ImGui::Button("Reset##2")) {

    };
    
    // 3. pollen options
    // TODO: header
    // TODO: reset color
    // todo: toggle overlay display
    ImGui::ColorEdit3("Pollinated soybean", (float*)&pollenColor, ImGuiColorEditFlags_NoInputs);
    ImGui::SameLine();
    if (ImGui::Button("Reset##3")) {

    };
    /*ImGui::RadioButton("None##3", &e, 0); ImGui::SameLine();
    ImGui::RadioButton("Small square", &e, 1); ImGui::SameLine();
    ImGui::RadioButton("Full square", &e, 2);*/

    // 4. Hive options
    ImGui::ColorEdit3("Hive", (float*)&hiveColor, ImGuiColorEditFlags_NoInputs);
    ImGui::SameLine();
    if (ImGui::Button("Reset##4")) {

    };
    // 5. bee options?

    ImGui::End();
}
