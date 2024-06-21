#Chunks
cmake_minimum_required(VERSION 3.5)

add_sources(Debug Chunk.cpp AbandonedTownChunk.cpp)
target_include_directories(Debug PRIVATE .)

#[[
add_library(Chunks Chunk.cpp AbandonedTownChunk.cpp)
target_link_libraries(Chunks
	PUBLIC Tiles Items Game
	PRIVATE MyToolkit)
target_include_directories(Chunks
	PUBLIC .
	PRIVATE /usr/local/include/MyToolkit)
]]

# Include directories are inherited via linkage
#target_include_directories(Chunks PUBLIC ${TileWanderer3_SOURCE_DIR}/Tiles ${MyToolkit_SOURCE_DIR})
