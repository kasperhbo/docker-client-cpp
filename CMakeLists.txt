cmake_minimum_required(VERSION 3.28)
project(Docker-Client C CXX)


if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "" FORCE)
endif ()

set(CMAKE_CXX_STANDARD 17)

set(LIB_NAME ${PROJECT_NAME})
set(EXE_NAME ${PROJECT_NAME}-EXE)

set(SOURCES
        src/private/Containers/Container.cpp
        src/private/Containers/ContainerManager.cpp
        src/private/Containers/UI/ContainerListWindow.cpp
        src/private/Containers/UI/ContainerWindow.cpp
        src/private/ApiRequester.cpp
)

set(PRIVATE_HEADERS

)

set(PUBLIC_HEADERS
)

add_library(
        ${LIB_NAME}
        ${SOURCES}
        ${PUBLIC_HEADERS}
)
target_include_directories(
        ${LIB_NAME} PUBLIC
        src/public
)


#libraries
#kbui
set(KBUI_DIR ../kbui)
add_subdirectory(${KBUI_DIR} binary_dir EXCLUDE_FROM_ALL)
target_link_libraries(
        ${LIB_NAME} PUBLIC
        KBUI
)
#nlohmann json
set(JSON_DIR vendor/nlohmann-json)
add_subdirectory(${JSON_DIR})
target_link_libraries(
        ${LIB_NAME} PUBLIC
        nlohmann_json::nlohmann_json
)

#curl
find_package(CURL REQUIRED)
target_link_libraries(
        ${LIB_NAME} PUBLIC
        CURL::libcurl
)

#nana

#executable for testing
add_executable(
        ${EXE_NAME}
        src/main.cpp
)

target_link_libraries(
        ${EXE_NAME} PRIVATE
        ${LIB_NAME}
)