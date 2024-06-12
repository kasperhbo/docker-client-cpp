//
// Created by Kasper de bruin on 12/06/2024.
//

#include <VulkanWindow.h>
#include <Containers/Container.h>
#include <Containers/UI/ContainerListWindow.h>
int main() {
    WindowProperties properties =  WindowProperties(1920, 1080, "Docker-ImGui-Test-Window, Vulkan!", ImVec4(0.45f, 0.55f, 0.60f, 1.00f));
    KBUI::VulkanWindow mainWindow(properties);
    const KBDocker::Container container("Container 1");
    while(!mainWindow.ShouldClose()){
        mainWindow.StartFrame();

        KBDocker::ContainerListWindow::Begin(container);
        KBDocker::ContainerListWindow::End();

        mainWindow.EndFrame();
    }
    return 0;
}