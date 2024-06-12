//
// Created by Kasper de bruin on 12/06/2024.
//

#ifndef DOCKER_CLIENT_CONTAINER_H
#define DOCKER_CLIENT_CONTAINER_H

#include <string>
#include <utility>
#include <optional>
#include <vector>
#include <map>
#include <nlohmann/json.hpp>

namespace KBDocker {

    class Container {
    public:
        explicit Container(std::string name) : name(std::move(name)){

        }

        ~Container() = default;

        static Container FromJson(const std::string& json){
            return Container("test");
        }
    public:
        [[nodiscard]] const std::string& GetName() const{
            return name;
        }

    private:
        std::string name;
        std::string command;
        std::optional<long> created;
        std::string id;
        std::string image;
        std::optional<std::string> imageId;
        std::vector<std::string> names;
//        std::vector<ContainerPort> ports;
        std::map<std::string, std::string> labels;
        std::string status;
        std::string state;
        std::optional<long> sizeRw;
        std::optional<long> sizeRootFs;
//        std::optional<ContainerHostConfig> hostConfig;
//        std::optional<ContainerNetworkSettings> networkSettings;
//        std::vector<ContainerMount> mounts;

    };

} // KBDocker

#endif //DOCKER_CLIENT_CONTAINER_H
