# CMakeList.txt : CMake project for lab2, include source and define
# project specific logic here.
#
cmake_minimum_required(VERSION 3.24)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(lab2)

set(wxWidgets_ROOT_DIR C:/maks/libs/wxWidgets-3.2.2.1/binaries)
set(wxWidgets_LIB_DIR C:/maks/libs/wxWidgets-3.2.2.1/binaries/lib/vc14x_x64_dll)
find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})

add_executable (lab2 "lab2.cpp" "lab2.h" "model.hpp" "model.cpp" "presenter.cpp" "presenter.hpp" "view.cpp" "view.hpp" "model.fwd.hpp" "view.fwd.hpp" "presenter.fwd.hpp" "wxWidgetsView.cpp")
target_link_libraries(lab2 ${wxWidgets_LIBRARIES})
