cmake_minimum_required(VERSION 3.5)
project(TileWanderer3 VERSION 0.1 LANGUAGES CXX)

#add_subdirectory(/home/evan/projects/c++/MyToolkit/source MyToolkit)
add_subdirectory(Tiles)
add_subdirectory(Chunks)
add_subdirectory(Items)

add_library(Game World.cpp Player.cpp Database.cpp InputBindings.cpp TileMediator.cpp GameManager.cpp)
target_include_directories(Game
	PUBLIC .
	PUBLIC /usr/local/include/MyToolkit)
target_link_libraries(Game
	PUBLIC Chunks Tiles Items
	PUBLIC MyToolkit)

add_executable(Debug main.cpp)
target_link_libraries(Debug PRIVATE Game)
