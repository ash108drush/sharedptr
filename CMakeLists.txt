cmake_minimum_required(VERSION 3.16)

project(sharedptr LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(sharedptr main.cpp
    canvas.h common.h shapes.h texture.h)

include(GNUInstallDirs)
install(TARGETS sharedptr
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
