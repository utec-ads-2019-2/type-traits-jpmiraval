cmake_minimum_required(VERSION 3.12)
project(type_traits_jpmiraval)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(mock)
include_directories(test)

add_executable(type_traits_jpmiraval
        mock/mocker.cpp
        mock/mocker.h
        test/tester.cpp
        test/tester.h
        main.cpp
        node.h
        self_list.h
        traits_list.h)
