# Enemy Tiles
cmake_minimum_required(VERSION 3.5)

add_sources(Debug EnemyTile.cpp EnemyTileImpl.cpp EnemyTileDecorator.cpp)
target_include_directories(Debug PRIVATE .)
