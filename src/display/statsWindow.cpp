#include "statsWindow.hpp"
#include "statsWindow.hpp"

#include <sstream>
#include <string>
#include <SFML/Graphics.hpp>
#include "imgui.h"
#include "imgui-SFML.h"

StatsWindow::StatsWindow(shared_ptr<Metrics> metrics) {
    this->metrics = metrics;
}

void StatsWindow::display() {
    // create info strings
    std::stringstream runTimeInfo;
    std::stringstream hiveNectarInfo;
    std::stringstream pollinationCountInfo;

    runTimeInfo << "Runtime: " << metrics->timeString();
    hiveNectarInfo << "Nectar in hive: " << metrics->hive_nectar;
    pollinationCountInfo << "Flowers pollinated: " << metrics->pollinated_count;

    // configure window
    ImGui::SetNextWindowSize(ImVec2(0.0, 0.0));  // auto resize
    ImGui::Begin("Simulation statistics");
    ImGui::Text(runTimeInfo.str().c_str());
    ImGui::Text(hiveNectarInfo.str().c_str());
    ImGui::Text(pollinationCountInfo.str().c_str());
    ImGui::End();
}
