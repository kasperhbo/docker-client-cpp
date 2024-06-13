//
// Created by Kasper de bruin on 13/06/2024.
//

#include "ApiRequester.h"
#include <curl/curl.h>


namespace KBDocker {
    // This callback function is called by libcurl as soon as there is data received that needs to be saved
    size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
        ((std::string*)userp)->append((char*)contents, size * nmemb);
        return size * nmemb;
    }
    static std::string GetUrl(const std::string &ip) {
        std::string fullUrl = "http://" + ip + ":8080" + "/api/docker";
        return fullUrl;
    }

    std::string ApiRequester::Get(const std::string &ip, const std::string &urlData) {
        CURL* curl;
        CURLcode res;
        std::string readBuffer;

        const std::string url = GetUrl(ip) + urlData;

        curl = curl_easy_init();
        if (curl) {
            // Set the URL for the GET request
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

            // Set the write callback function
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);

            // Set the user pointer for the write callback function
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

            // Perform the request, res will get the return code
            res = curl_easy_perform(curl);

            // Check for errors
            if (res != CURLE_OK) {
                std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
            }

            // Clean up
            curl_easy_cleanup(curl);
        }
        return readBuffer;
    }
} // KBDocker