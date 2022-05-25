cmake_minimum_required(VERSION 3.5)
project(qt_test)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS} -std=c++1y")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5 COMPONENTS SerialPort REQUIRED)

file (GLOB CPPS "sources/*.cpp")
file (GLOB UI "forms/*.ui")
file (GLOB HEAD "headlines/*.h")

#include_directories("${PROJECT_SOURCE_DIR}/headlines")

include_directories(${Qt5Widgets_INCLUDE_DIRS})
include_directories(${Qt5SerialPort_INCLUDE_DIRS})

add_definitions(${Qt5Widgets_DEFINITIONS})
add_definitions(${Qt5SerialPort_DEFINITIONS})

macro(print_all_variables)
    message(STATUS "print_all_variables------------------------------------------{")
    get_cmake_property(_variableNames VARIABLES)
    foreach (_variableName ${_variableNames})
        message(STATUS "${_variableName}=${${_variableName}}")
    endforeach()
    message(STATUS "print_all_variables------------------------------------------}")
endmacro()

#print_all_variables()

#set(CMAKE_CXX_FLAGS "${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

add_executable(${PROJECT_NAME}  ${CPPS}  ${UI}  ${HEAD})

target_link_libraries(${PROJECT_NAME} ${Qt5Widgets_LIBRARIES})

 #qt5_use_modules(${PROJECT_NAME} Core SerialPort)

