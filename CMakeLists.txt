cmake_minimum_required(VERSION 3.5)
project(qt_test)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS} -std=c++1y")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Widgets REQUIRED)

file (GLOB CPPS "sources/*.cpp")
file (GLOB UI "forms/*.ui")
file (GLOB HEAD "headlines/*.h")

#include_directories("${PROJECT_SOURCE_DIR}/headlines")

include_directories(${Qt5Widgets_INCLUDES})

add_definitions(${Qt5Widgets_DEFINITIONS})

set(CMAKE_CXX_FLAGS "${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

add_executable(${PROJECT_NAME}  ${CPPS}  ${UI}  ${HEAD})

target_link_libraries(${PROJECT_NAME} ${Qt5Widgets_LIBRARIES})


