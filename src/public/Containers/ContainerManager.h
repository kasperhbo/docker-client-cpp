//
// Created by Kasper de bruin on 13/06/2024.
//

#ifndef DOCKER_CLIENT_CONTAINERMANAGER_H
#define DOCKER_CLIENT_CONTAINERMANAGER_H

#include <iostream>
#include <utility>
#include <vector>
#include "Containers/Container.h"

namespace KBDocker::Containers {

    class ContainerManager {
    public:
        explicit ContainerManager(std::string ip, float refreshInterval = 1.0f) : m_Ip(std::move(ip)),
                                                                                  m_RefreshInterval(refreshInterval) {}

        ~ContainerManager() = default;

    public:
        void Refresh();

        [[nodiscard]]std::vector<Container> GetContainers() const {
            return m_Containers;
        }

        [[nodiscard]]const std::string &GetIp() const {
            return m_Ip;
        }

    private:
        void FetchContainersFromAPI() const;

    public:
        std::string m_Ip;
        const float m_RefreshInterval = 1.0f;

        std::vector<Container> m_Containers = {};

    private:
        inline static std::string s_containerUrl = "/container";
    };

} // Containers
// KBDocker

#endif //DOCKER_CLIENT_CONTAINERMANAGER_H
