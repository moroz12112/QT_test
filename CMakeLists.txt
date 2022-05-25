cmake_minimum_required(VERSION 3.5)
project(qt_test)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS} -std=c++1y")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5 COMPONENTS SerialPort REQUIRED)
#find_package(Qt5Core REQUIRED)
#find_package(Qt5SerialPort REQUIRED)

file (GLOB CPPS "sources/*.cpp")
file (GLOB UI "forms/*.ui")
file (GLOB HEAD "headlines/*.h")

#include_directories("${PROJECT_SOURCE_DIR}/headlines")

include_directories(${Qt5Widgets_INCLUDES})
include_directories(${Qt5SerialPort_INCLUDES})

add_definitions(${Qt5Widgets_DEFINITIONS})
add_definitions(${Qt5SerialPort_DEFINITIONS})

#set(CMAKE_CXX_FLAGS "${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

add_executable(${PROJECT_NAME}  ${CPPS}  ${UI}  ${HEAD})

target_link_libraries(${PROJECT_NAME} ${Qt5Widgets_LIBRARIES})

 #qt5_use_modules(${PROJECT_NAME} Core SerialPort)





