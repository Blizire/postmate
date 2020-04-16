cmake_minimum_required(VERSION 3.16.0)

# ensure debug symbols are added
set(CMAKE_BUILD_TYPE Debug)

# point to header files
include_directories(libs/curl/include)

# set project name
project(postmate)

# compile as executable
add_executable (postmate src/postmate.c src/config.c)

# add imported library
add_library(libcurl STATIC IMPORTED)

# point imported target to actual files
set_property(TARGET libcurl PROPERTY 
				IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/libs/curl/lib/libcurl.dll.a)

target_link_libraries(postmate libcurl)

# set location of binary
add_custom_command(TARGET postmate
                   POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:postmate> ${PROJECT_SOURCE_DIR}/bin)