//
// Created by Kasper de bruin on 13/06/2024.
//

#ifndef DOCKER_CLIENT_CONTAINERWINDOW_H
#define DOCKER_CLIENT_CONTAINERWINDOW_H


#include "Containers/Container.h"

namespace KBDocker::UI {

    class ContainerWindow {
    public:
        static void Begin(const Container &container, bool isChild = false);
    };

} // UI
// KBDocker

#endif //DOCKER_CLIENT_CONTAINERWINDOW_H
