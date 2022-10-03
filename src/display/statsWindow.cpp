/**
 * FIT3161/3162 Computer Science Project
 * Insect Simulation for Improved Pollination and Pest Control
 * Group CS6
 *
 * @file statsWindow.cpp
 * @brief In-window menu displaying general simulation statistics.
 * @date 2022-09-15
 */

#include "statsWindow.hpp"
#include "statsWindow.hpp"

#include <sstream>
#include <string>
#include <SFML/Graphics.hpp>


StatsWindow::StatsWindow(shared_ptr<Metrics> metrics) {
    this->metrics = metrics;
    defaultPosition = ImVec2(20, 20);
}

void StatsWindow::draw() {
    // create info strings
    std::stringstream runTimeInfo;
    std::stringstream hiveNectarInfo;
    std::stringstream pollinationCountInfo;

    runTimeInfo << "Runtime: " << metrics->timeString();
    hiveNectarInfo << "Nectar in hive: " << metrics->hive_nectar;
    pollinationCountInfo << "Soybeans pollinated: " << metrics->pollinated_count;

    // configure window
    ImGui::SetNextWindowPos(defaultPosition, ImGuiCond_Once);  // set up initial position
    ImGui::SetNextWindowSize(ImVec2(0.0, 0.0));  // auto resize
    ImGui::Begin("Simulation statistics");

    // move window if needed, and outside visible area
    bool checkWindowPosition = windowX != -1 and windowY != -1;
    if (checkWindowPosition) {
        moveUnseenWindow(windowX, windowY);
    }
    
    // set up window contents
    ImGui::Text(runTimeInfo.str().c_str());
    ImGui::Text(hiveNectarInfo.str().c_str());
    ImGui::Text(pollinationCountInfo.str().c_str());
    ImGui::End();
}
