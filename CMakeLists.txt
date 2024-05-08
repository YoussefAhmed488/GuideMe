cmake_minimum_required(VERSION 3.27)
project(GuideMe)

set(CMAKE_CXX_STANDARD 14)

include_directories(build-GuideMe-Qt_6_7_0_for_macOS-Debug)
include_directories(GuideMe)

add_executable(GuideMe
        build-GuideMe-Qt_6_7_0_for_macOS-Debug/moc_filesystem.cpp
        build-GuideMe-Qt_6_7_0_for_macOS-Debug/moc_mainwindow.cpp
        build-GuideMe-Qt_6_7_0_for_macOS-Debug/ui_mainwindow.h
        GuideMe/file_mangment.cpp
        GuideMe/file_mangment.h
        GuideMe/filesystem.cpp
        GuideMe/filesystem.h
        GuideMe/main.cpp
        GuideMe/mainwindow.cpp
        GuideMe/mainwindow.h)
