//
// Created by Kasper de bruin on 12/06/2024.
//

#ifndef DOCKER_CLIENT_CONTAINERLISTWINDOW_H
#define DOCKER_CLIENT_CONTAINERLISTWINDOW_H


namespace KBDocker {
    class Container;

    class ContainerListWindow {
    public:
        static void Begin(const Container& container);
        static void End();
    };

} // KBDocker

#endif //DOCKER_CLIENT_CONTAINERLISTWINDOW_H
