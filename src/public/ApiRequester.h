//
// Created by Kasper de bruin on 13/06/2024.
//

#ifndef DOCKER_CLIENT_APIREQUESTER_H
#define DOCKER_CLIENT_APIREQUESTER_H
#include <iostream>
namespace KBDocker {

    class ApiRequester {
    public:
        ApiRequester() = default;

        virtual ~ApiRequester() = default;

        static std::string Get(const std::string& url, const std::string& data);
    };

} // KBDocker

#endif //DOCKER_CLIENT_APIREQUESTER_H
