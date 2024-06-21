cmake_minimum_required(VERSION 3.5)
project(TileWanderer3 VERSION 0.1 LANGUAGES CXX)

function(add_sources target)
	foreach(source IN LISTS ARGN)
		set_property(TARGET ${target} APPEND PROPERTY SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/${source})
	endforeach()
endfunction()

add_executable(Debug main.cpp World.cpp Player.cpp Database.cpp InputBindings.cpp TileMediator.cpp GameManager.cpp)
target_include_directories(Debug PRIVATE . /usr/local/include/MyToolkit)
target_link_libraries(Debug MyToolkit)

#add_subdirectory(/home/evan/projects/c++/MyToolkit/source MyToolkit)
add_subdirectory(Tiles)
add_subdirectory(Items)
add_subdirectory(Chunks)
