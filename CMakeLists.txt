cmake_minimum_required(VERSION 3.25)
project(battstat)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(battstat battstat.cpp battstat.h)
target_link_libraries(battstat
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

