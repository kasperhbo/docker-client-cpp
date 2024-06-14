//
// Created by Kasper de bruin on 12/06/2024.
//

#include <VulkanWindow.h>
#include <Containers/Container.h>
#include <Containers/UI/ContainerListWindow.h>
#include "Containers/ContainerManager.h"

using namespace nlohmann;

int main() {
    KBUI::Properties::WindowProperties properties = KBUI::Properties::WindowProperties(1920, 1080,
                                                                                       "Docker-ImGui-Test-Window, Vulkan!",
                                                                                       ImVec4(0.45f, 0.55f, 0.60f,
                                                                                              1.00f));
    KBUI::VulkanWindow mainWindow(properties);
    KBDocker::Containers::ContainerManager containerManager("localhost", 1);


    while (!mainWindow.ShouldClose()) {
        mainWindow.StartFrame();

        ImGui::ShowDemoWindow();

        KBDocker::UI::ContainerListWindow::Begin(containerManager.GetContainers());
        KBDocker::UI::ContainerListWindow::End();
        mainWindow.EndFrame();
    }
    return 0;
}