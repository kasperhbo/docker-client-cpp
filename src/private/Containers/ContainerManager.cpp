//
// Created by Kasper de bruin on 13/06/2024.
//

#include "Containers/ContainerManager.h"
#include "ApiRequester.h"
#include "Containers/Container.h"
#include "nlohmann/json.hpp"

namespace KBDocker::Containers {
    void ContainerManager::Refresh() {
        m_Containers = FetchContainersFromAPI();
    }

    std::vector<Container> ContainerManager::FetchContainersFromAPI() const {
        const std::string jsonString = ApiRequester::Get(GetIp(), s_containerUrl + "/list");
        std::vector<Container> containers;
        try {
            auto basicJson = nlohmann::json::parse(jsonString);
            for (auto &container : basicJson) {
                containers.push_back(KBDocker::Container::CreateContainerListItemFromJson(container.dump()));
            }
        } catch (nlohmann::json::parse_error &e) {
            std::cerr << "JSON parse error: " << e.what() << std::endl;
        } catch (nlohmann::json::type_error &e) {
            std::cerr << "JSON type error: " << e.what() << std::endl;
        }

        return containers;
    }

} // Containers
// KBDocker