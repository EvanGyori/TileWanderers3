cmake_minimum_required(VERSION 3.5)

add_library(Items Item.cpp Weapon.cpp Shield.cpp)
target_include_directories(Items
	PUBLIC . ${CMAKE_SOURCE_DIR}
	PRIVATE /usr/local/include/MyToolkit)
target_link_libraries(Items PRIVATE MyToolkit)
