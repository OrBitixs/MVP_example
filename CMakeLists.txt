# CMakeList.txt : CMake project for lab2, include source and define
# project specific logic here.
#
cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(lab2)

add_subdirectory(C:/maks/libs/wxWidgets/3.2.2.1_source libs/wxWidgets)
# Add source to this project's executable.
add_executable (lab2 "lab2.cpp" "lab2.h" "model.hpp" "model.cpp" "presenter.cpp" "presenter.hpp" "view.cpp" "view.hpp" "model.fwd.hpp" "view.fwd.hpp" "presenter.fwd.hpp" "wxWidgetsView.cpp")
target_link_libraries(lab2 wx::net wx::core wx::base)
# TODO: Add tests and install targets if needed.
