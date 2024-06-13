#include "Containers/Container.h"
#include "Containers/UI/ContainerListWindow.h"
#include "Containers/UI/ContainerWindow.h"
#include <imgui.h>

namespace KBDocker::UI {
    void ContainerListWindow::Begin(const std::vector<Container> &containers) {
        static int selectedIdx = -1;
        ImGui::Begin("Docker Containers", nullptr, ImGuiWindowFlags_MenuBar);

        // Setup menu bar
        if (ImGui::BeginMenuBar()) {
            if (ImGui::Button("Refresh")) {
                // containers = GetDockerContainers(); // Refresh the containers list
            }
            ImGui::EndMenuBar();
        }

        // Split the window into two parts using BeginChild
        ImGui::Columns(2, "containerColumnsSplit", false); // False to not include borders between columns

        // Left panel for listing containers
        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding,
                            ImVec2(0, 0));
        ImGui::BeginChild("ContainerList", ImVec2(0, 0), ImGuiChildFlags_Border,
                          ImGuiWindowFlags_HorizontalScrollbar); // Adjust size as needed

        if (ImGui::BeginTable("ContainersTable", 4,
                              ImGuiTableFlags_Borders |
                              ImGuiTableFlags_RowBg |
                              ImGuiTableFlags_Resizable)) {
            ImGui::TableSetupColumn("Name");
            ImGui::TableSetupColumn("Image");
            ImGui::TableSetupColumn("Status");
            ImGui::TableSetupColumn("ID");

            ImGui::TableHeadersRow();

            for (int i = 0; i < containers.size(); ++i) {
                ImGui::TableNextRow();
                ImGui::TableSetColumnIndex(0);
                if (ImGui::Selectable(containers[i].GetName().c_str(), i == selectedIdx,
                                      ImGuiSelectableFlags_SpanAllColumns)) {
                    selectedIdx = i;
                }
                ImGui::TableSetColumnIndex(1);
                ImGui::Text("%s", containers[i].GetImage().c_str());
                ImGui::TableSetColumnIndex(2);
                ImGui::Text("%s", containers[i].GetStatus().c_str());
                ImGui::TableSetColumnIndex(3);
                ImGui::Text("%s", containers[i].GetID().c_str());
            }
            ImGui::EndTable();
        }
        ImGui::Columns(1);
        ImGui::EndChild(); // End left panel
        ImGui::PopStyleVar();

        // Right panel for showing selected container details
        ImGui::NextColumn();
//        ImGui::BeginChild("ContainerDetails", ImVec2(0, 0), true); // Adjust size as needed
        if (selectedIdx != -1) {
            if(selectedIdx < containers.size())
                ContainerWindow::Begin(&containers[selectedIdx], true);
        }
//        ImGui::EndChild(); // End right panel

        ImGui::Columns(1); // Reset columns before finishing
    }

    void ContainerListWindow::End() {
        ImGui::End();
    }
} // KBDocker
