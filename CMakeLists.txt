cmake_minimum_required(VERSION 2.8)
project(fishengine C CXX)

#LIST OF FILES
file(GLOB LIBSRC ${CMAKE_SOURCE_DIR}/src/*.cpp ${CMAKE_SOURCE_DIR}/src/*.h)
file(GLOB LIBINC ${CMAKE_SOURCE_DIR}/src/*.h)

#SET FLAGS FOR C++11 STD
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#CREATE THE LIBRARY
add_library(fishengine ${LIBSRC})

#MAKE"lib" AND "inc" DIRECTORY
add_custom_command(TARGET fishengine POST_BUILD COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_SOURCE_DIR}/inc)
add_custom_command(TARGET fishengine POST_BUILD COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_SOURCE_DIR}/lib)

#COPY ALL HEADERS FROM "src" to "inc"
foreach(file_i ${LIBINC})
	add_custom_command(TARGET fishengine POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${file_i} ../inc)
endforeach(file_i)

#COPY THE LIBRARY TO "lib"
add_custom_command(TARGET fishengine POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy libfishengine.a $<TARGET_FILE:fishengine> ../lib)
