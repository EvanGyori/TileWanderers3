#Tiles
cmake_minimum_required(VERSION 3.5)

add_library(Tiles Tile.cpp EmptyTile.cpp)
target_include_directories(Tiles PUBLIC . ${CMAKE_SOURCE_DIR})
