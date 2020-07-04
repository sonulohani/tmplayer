cmake_minimum_required(VERSION 3.1)

cmake_policy(SET CMP0048 NEW)

project(tmplayer VERSION 1.0.0)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_BUILD_TYPE Release)

find_package(Qt5Core REQUIRED)
# find_package(Qt5Network REQUIRED)

if (Qt5Core_FOUND)
    if (Qt5Core_VERSION VERSION_LESS 5.15.0)
        message(FATAL_ERROR "Minimum supported Qt5 version is 5.15.0!")
    endif()
else()
    message(SEND_ERROR "The Qt5Core library could not be found!")
endif(Qt5Core_FOUND)


set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)

configure_file(include/config.h.in generated/config.h)

set(tmplayer_HDRS
	include/config.h.in)

set(tmplayer_SRCS
    src/main.cpp)

add_executable(tmplayer ${tmplayer_SRCS} ${tmplayer_HDRS})
target_link_libraries(tmplayer PRIVATE Qt5::Core)
target_include_directories(tmplayer PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include 
                                            ${CMAKE_CURRENT_BINARY_DIR}/generated)