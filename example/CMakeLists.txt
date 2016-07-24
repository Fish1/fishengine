cmake_minimum_required(VERSION 2.8)
project(fishenginetest C CXX)

include_directories(${CMAKE_SOURCE_DIR}/../inc)
link_directories(${CMAKE_SOURCE_DIR}/../lib)

file(GLOB PROGSRC ${CMAKE_SOURCE_DIR}/src/*cpp ${CMAKE_SOURCE_DIR}/src/*.h)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(fe-app ${CMAKE_SOURCE_DIR}/src/driver.cpp ${PROGSRC})
target_link_libraries(fe-app fishengine sfml-graphics sfml-audio sfml-window sfml-system)

add_custom_command(TARGET fe-app POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy fe-app $<TARGET_FILE:fe-app> ..)
