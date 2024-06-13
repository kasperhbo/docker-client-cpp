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
        enum class State {
            Running,
            Stopped,
            Paused,
            Restarting,
            Removing,
            Exited,
            Dead,
            Unknown = -1
        };

        explicit Container(
                std::string id,
                std::string name,
                std::string image,
                std::string status,
                const State &state
        ) :
                m_ID(std::move(id)),
                m_Name(std::move(name)),
                m_Image(std::move(image)),
                m_Status(std::move(status)),
                m_State(state) {}

        ~Container() = default;

        static Container CreateContainerListItemFromJson(const std::string &json);

        static Container
        CreateContainerListItem(const std::string &id, const std::string &name, const std::string &image,
                                const std::string &status, const State &state);

        static State GetStateFromString(const std::string &state);

    public:
        const std::string &GetID() const {
            return m_ID;
        }

        const std::string &GetName() const {
            return m_Name;
        }

        const std::string &GetImage() const {
            return m_Image;
        }

        const std::string &GetStatus() const {
            return m_Status;
        }

        State GetState() const {
            return m_State;
        }

    private:
        std::string m_ID;
        std::string m_Name;
        std::string m_Image;
        std::string m_Status;
        State m_State;
    };

} // KBDocker

#endif //DOCKER_CLIENT_CONTAINER_H
