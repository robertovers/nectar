#include "legendsWindow.hpp"
#include "legendsWindow.hpp"
#include "legendsWindow.hpp"
#include "legendsWindow.hpp"
#include "legendsWindow.hpp"

void LegendsWindow::draw(int windowX, int windowY) {
    // convert sf::colors to vectors used by imgui color picker
    static auto soybeanColor = colorToImVec4(*envColours.soybeanColour);
    static auto nectarColor = colorToImVec4(*envColours.nectarColour);
    static auto pollenColor = colorToImVec4(*envColours.pollenColour);
    static int pollenOption = 1;
    static int nectarOption = 2;
    static auto hiveColor = colorToImVec4(*envColours.hiveColour);
    static auto locationColour = colorToImVec4(*envColours.locationColour);

    // display window
    ImGui::Begin("Display Options");
    // 1. Plant options
    ImGui::ColorEdit3("Soybean", (float*)&soybeanColor, ImGuiColorEditFlags_NoInputs); /*ImGui::SameLine();
    if (ImGui::Button("Reset##1")) {

    }*/

    // 2. nectar options
    // TODO: header
    // TODO: reset color
    // todo: toggle overlay display (radio buttons
    ImGui::ColorEdit3("Soybean with max nectar", (float*)&nectarColor, ImGuiColorEditFlags_NoInputs); /*ImGui::SameLine();
    if (ImGui::Button("Reset##2")) {

    };*/
    ImGui::RadioButton("None##2", &nectarOption, 0); ImGui::SameLine();
    ImGui::RadioButton("Small square##2", &nectarOption, 1); ImGui::SameLine();
    ImGui::RadioButton("Overlay##2", &nectarOption, 2);
    
    // 3. pollen options
    // TODO: header
    // TODO: reset color
    // todo: toggle overlay display
    ImGui::ColorEdit3("Pollinated soybean", (float*)&pollenColor, ImGuiColorEditFlags_NoInputs); /*ImGui::SameLine();
    if (ImGui::Button("Reset##3")) {

    };*/
    ImGui::RadioButton("None##3", &pollenOption, 0); ImGui::SameLine();
    ImGui::RadioButton("Small square##3", &pollenOption, 1); ImGui::SameLine();
    ImGui::RadioButton("Overlay##3", &pollenOption, 2);

    // 4. Hive options
    ImGui::ColorEdit3("Hive", (float*)&hiveColor, ImGuiColorEditFlags_NoInputs); /*ImGui::SameLine();
    if (ImGui::Button("Reset##4")) {

    };*/
    // 5. location options
    ImGui::ColorEdit3("Empty location", (float*)&locationColour, ImGuiColorEditFlags_NoInputs); /*ImGui::SameLine();
    if (ImGui::Button("Reset##5")) {

    };*/

    // 6. bee options?

    ImGui::End();
    
    // convert colour vectors back to colours
    copyColor(envColours.soybeanColour, ImVec4ToColor(soybeanColor));
    copyColor(envColours.nectarColour, ImVec4ToColor(nectarColor));
    copyColor(envColours.pollenColour, ImVec4ToColor(pollenColor));
    copyColor(envColours.hiveColour, ImVec4ToColor(hiveColor));
    copyColor(envColours.locationColour, ImVec4ToColor(locationColour));

    // set chosen overlay
    changeOverlay(soybeanOverlays.nectar, nectarOption);
    changeOverlay(soybeanOverlays.pollen, pollenOption);
}

ImVec4 LegendsWindow::colorToImVec4(sf::Color color) {
    return ImVec4(color.r / 255.0f, color.g / 255.0f, color.b / 255.0f, color.a / 255.0f);
}

sf::Color LegendsWindow::ImVec4ToColor(ImVec4 vector) {
    return sf::Color(vector.x * 255, vector.y * 255, vector.z * 255, vector.w * 255);
}

void LegendsWindow::copyColor(shared_ptr<sf::Color> oldColour, sf::Color newColour) {
    oldColour->r = newColour.r;
    oldColour->g = newColour.g;
    oldColour->b = newColour.b;
    oldColour->a = newColour.a;
}

void LegendsWindow::changeOverlay(shared_ptr<sf::Shape> overlay, int overlayType) {
    if (overlayType == 1) {
        //auto overlay = std::shared_ptr<sf::RectangleShape>(std::make_shared<sf::RectangleShape>());
        overlay->setScale(sf::Vector2f(.3, .3));
        //return overlay;
    }
    else if (overlayType == 2) {
        //auto overlay = std::shared_ptr<sf::RectangleShape>(std::make_shared<sf::RectangleShape>());
        overlay->setScale(sf::Vector2f(1, 1));
        //return overlay;
    }
    else {
        overlay->setScale(sf::Vector2f(0, 0));
    }
}
