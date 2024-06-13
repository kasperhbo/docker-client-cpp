//
// Created by Kasper de bruin on 13/06/2024.
//

#include <imgui.h>
#include "Containers/UI/ContainerWindow.h"


namespace KBDocker::UI {
    void ContainerWindow::Begin(const Container *container, bool isChild) {
        if (container == nullptr) { return; }
        if (container->GetID().empty() || container->GetID() == "" || container->GetName().empty()) { return; }

        if (isChild)
            ImGui::BeginChild(container->GetID().c_str());
        else
            ImGui::Begin(container->GetID().c_str());


        ImGui::Text("ID: %s", container->GetID().c_str());
        ImGui::Text("Name: %s", container->GetName().c_str());
        ImGui::Text("Image: %s", container->GetImage().c_str());
        ImGui::Text("Status: %s", container->GetStatus().c_str());

        // Add color to the state display
        std::string stateStr = "Unknown";
        ImVec4 color = ImVec4(1.0f, 1.0f, 1.0f, 1.0f); // Default to white
        switch (container->GetState()) {
            case Container::State::Running:
                stateStr = "Running";
                color = ImVec4(0.0f, 1.0f, 0.0f, 1.0f); // Green
                break;
            case Container::State::Stopped:
                stateStr = "Stopped";
                color = ImVec4(1.0f, 0.0f, 0.0f, 1.0f); // Red
                break;
                // Add other cases with corresponding colors
            case Container::State::Paused:
                stateStr = "Paused";
                color = ImVec4(1.0f, 1.0f, 0.0f, 1.0f); // Yellow
                break;
            case Container::State::Restarting:
                stateStr = "Restarting";
                color = ImVec4(0.0f, 1.0f, 1.0f, 1.0f); // Cyan
                break;
            case Container::State::Removing:
                stateStr = "Removing";
                color = ImVec4(1.0f, 0.0f, 1.0f, 1.0f); // Magenta
                break;
            case Container::State::Exited:
                stateStr = "Exited";
                color = ImVec4(0.0f, 0.0f, 1.0f, 1.0f); // Blue
                break;
            case Container::State::Dead:
                stateStr = "Dead";
                color = ImVec4(1.0f, 0.5f, 0.0f, 1.0f); // Orange
                break;
            case Container::State::Unknown:
                stateStr = "Unknown";
                color = ImVec4(1.0f, 1.0f, 1.0f, 1.0f); // White
                break;
        }
        ImGui::TextColored(color, "State: %s", stateStr.c_str());

        if (isChild)
            ImGui::EndChild();
        else
            ImGui::End();
    }

} // UI
// KBDocker