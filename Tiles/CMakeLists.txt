#Tiles
cmake_minimum_required(VERSION 3.5)

add_sources(Debug Tile.cpp EmptyTile.cpp)
target_include_directories(Debug PRIVATE . )

add_subdirectory(EnemyTiles)
