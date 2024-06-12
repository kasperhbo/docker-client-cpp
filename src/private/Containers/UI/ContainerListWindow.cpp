//
// Created by Kasper de bruin on 12/06/2024.
//

#include "Containers/Container.h"
#include "Containers/UI/ContainerListWindow.h"
#include <imgui.h>

namespace KBDocker {
    void ContainerListWindow::Begin(const Container& container){
        ImGui::Begin(container.GetName().c_str());

    }

    void ContainerListWindow::End(){
        ImGui::End();
    }
} // KBDocker