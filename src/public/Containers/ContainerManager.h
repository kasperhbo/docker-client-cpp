//
// Created by Kasper de bruin on 13/06/2024.
//

#ifndef DOCKER_CLIENT_CONTAINERMANAGER_H
#define DOCKER_CLIENT_CONTAINERMANAGER_H

#include <iostream>
#include <utility>
#include <vector>
#include <thread>
#include "Containers/Container.h"

namespace KBDocker::Containers {

    class ContainerManager {
    public:
        explicit ContainerManager(std::string ip, int refreshInterval = 1) : m_Ip(std::move(ip)),
                                                                             m_IntervalSeconds(refreshInterval),
                                                                             m_Running(false) {
            Start();
        }

        void Stop();

        ~ContainerManager(){
            if(m_Running.load())
                Stop();
        }

    public:

        void Start();

        void Refresh();

        [[nodiscard]]std::vector<Container> GetContainers() const {
            return m_Containers;
        }

        [[nodiscard]]const std::string &GetIp() const {
            return m_Ip;
        }

    private:
        std::vector<Container> FetchContainersFromAPI() const;

    private:
        std::string m_Ip;
        int m_IntervalSeconds;
        std::vector<Container> m_Containers{};
        std::atomic<bool> m_Running{};
        std::thread m_Thread;

        inline static std::string s_containerUrl = "/container";


    };

} // Containers
// KBDocker

#endif //DOCKER_CLIENT_CONTAINERMANAGER_H
