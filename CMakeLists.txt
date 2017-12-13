cmake_minimum_required(VERSION 2.8)

project(Pacman3D)


find_package(OpenGL REQUIRED)

if (WIN32)
	set(GLEW_INCLUDE_DIR "D:/OpenGlUtils/glew-2.1.0/include")
	set(GLEW_LIBRARY "D:/OpenGlUtils/glew-2.1.0/lib/Release/Win32/glew32.lib")
	set(SDL_INCLUDE_DIR "D:/OpenGlUtils/SDL-1.2.15/include")
	set(SDL_LIBRARY "D:/OpenGlUtils/SDL-1.2.15/lib/libSDL.dll.a;D:/OpenGlUtils/SDL-1.2.15/lib/libSDLmain.a")
else (WIN32)
	find_package(SDL REQUIRED)
	find_package(GLEW REQUIRED)
endif (WIN32)

find_package(SDL REQUIRED)
find_package(GLEW REQUIRED)
set(EXECUTABLE_OUTPUT_PATH bin/)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -std=c++11 -g")

include_directories(${SDL_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR} ${GLEW_INCLUDE_DIR} include/ /usr/include/ glimac/include third-party/include)

set(ALL_LIBRARIES glimac ${SDL_LIBRARY} ${OPENGL_LIBRARIES} ${GLEW_LIBRARY})

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
file(COPY assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
