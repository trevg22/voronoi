cmake_minimum_required(VERSION 3.14)
project(voronoi LANGUAGES C)

add_library(voronoi STATIC)
add_subdirectory(src)
