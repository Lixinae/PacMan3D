cmake_minimum_required(VERSION 2.8)

project(Pacman3D)

find_package(SDL REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

set(EXECUTABLE_OUTPUT_PATH bin/)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -std=c++11 -g")


include_directories(${SDL_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR} ${GLEW_INCLUDE_DIR} include/ /usr/include/ glimac/include third-party/include)

set(ALL_LIBRARIES ${SDL_LIBRARY} ${OPENGL_LIBRARIES} ${GLEW_LIBRARY})

add_subdirectory(glimac)

file(GLOB_RECURSE source_files src/*)
file(GLOB_RECURSE SHADER_FILES *.glsl)
file(GLOB HEADER_FILES *.hpp)
	
add_executable(
    Pacman3D
    ${source_files}
	${HEADER_FILES}
	${SHADER_FILES}
	
)

target_link_libraries (
    Pacman3D
    ${ALL_LIBRARIES}
)

file(COPY shaders DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY textures DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
