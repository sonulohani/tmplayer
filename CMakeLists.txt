cmake_minimum_required(VERSION 3.1)

cmake_policy(SET CMP0048 NEW)

project(tmplayer VERSION 0.1)

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

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_BINARY_DIR})


set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# set(tmplayer_HDRS)

set(tmplayer_SRCS
    src/main.cpp)
	
add_executable(tmplayer ${tmplayer_SRCS})
target_link_libraries(tmplayer Qt5::Core)