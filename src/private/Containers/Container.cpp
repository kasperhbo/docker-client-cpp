//
// Created by Kasper de bruin on 12/06/2024.
//

#include <Containers/Container.h>
#include <nlohmann/json.hpp>
#include <iostream>

namespace KBDocker {
    Container::State
    Container::GetStateFromString(const std::string &state) {
        if (state == "running") {
            return State::Running;
        } else if (state == "stopped") {
            return State::Stopped;
        } else if (state == "paused") {
            return State::Paused;
        } else if (state == "restarting") {
            return State::Restarting;
        } else if (state == "removing") {
            return State::Removing;
        } else if (state == "exited") {
            return State::Exited;
        } else if (state == "dead") {
            return State::Dead;
        } else {
            return State::Unknown;
        }
    }

    Container
    Container::CreateContainerListItem(const std::string &id, const std::string &name, const std::string &image,
                                       const std::string &status, const State &state) {
        Container container(id, name, image, status, state);
        return container;
    }

    Container
    Container::CreateContainerListItemFromJson(const std::string &json) {
        try {
            auto j = nlohmann::json::parse(json);
            const std::string name = j["name"];
            const std::string id = j["id"];
            const std::string image = j["image"];
            const std::string status = j["status"];
            const State state = GetStateFromString(j["state"]);

            return CreateContainerListItem(id, name, image, status, state);
        } catch (nlohmann::json::parse_error &e) {
            std::cerr << "JSON parse error: " << e.what() << std::endl;
        } catch (nlohmann::json::type_error &e) {
            std::cerr << "JSON type error: " << e.what() << std::endl;
        }

        return Container("error", "error", "error", "error", State::Unknown);
    }
} // KBDocker