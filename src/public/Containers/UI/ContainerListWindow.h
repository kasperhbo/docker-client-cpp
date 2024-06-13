//
// Created by Kasper de bruin on 12/06/2024.
//

#ifndef DOCKER_CLIENT_CONTAINERLISTWINDOW_H
#define DOCKER_CLIENT_CONTAINERLISTWINDOW_H
#include <vector>

namespace KBDocker {
    class Container;
}

namespace KBDocker::UI {


    class ContainerListWindow {
    public:
        static void Begin(const std::vector<Container>& containers);

        static void End();
    };
}
// KBDocker

#endif //DOCKER_CLIENT_CONTAINERLISTWINDOW_H
