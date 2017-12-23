cmake_minimum_required(VERSION 2.8)

project(Pacman3D)

find_package(OpenGL REQUIRED)
find_package(SDL REQUIRED)
find_package(GLEW REQUIRED)

if (WIN32)
    #Set the windows variables
    #Set the variables used for glew
    set(GLEW_INCLUDE_DIR "D:/OpenGlUtils/glew-2.1.0/include")
    set(GLEW_LIBRARY "D:/OpenGlUtils/glew-2.1.0/lib/Release/Win32/glew32.lib")
    set(SDL_INCLUDE_DIR "D:/OpenGlUtils/SDL-1.2.15/include")
    set(SDL_LIBRARY "D:/OpenGlUtils/SDL-1.2.15/lib/libSDL.dll.a;D:/OpenGlUtils/SDL-1.2.15/lib/libSDLmain.a")

else (WIN32)
    # Set the linux variables
    find_package(SDL REQUIRED)
    find_package(GLEW REQUIRED)

endif (WIN32)
# Set all the library files
set(ALL_LIBRARIES
        glimac
        ${SDL_LIBRARY}
        ${OPENGL_LIBRARIES}
        ${GLEW_LIBRARY}
        assimp
        freetype
        )
set(EXECUTABLE_OUTPUT_PATH bin/)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -std=c++11 -g")

include_directories(
        ${SDL_INCLUDE_DIR}
        ${OPENGL_INCLUDE_DIR}
        ${GLEW_INCLUDE_DIR}
        include/
        /usr/include/
        glimac/include
        third-party/assimp/include/
        third-party/freetype-2.8.1/include
        third-party/include)

add_subdirectory(glimac)

#Flag pour la librairie assimp
set(ZLIB_LIBRARIES zlibstatic)
set(ENABLE_BOOST_WORKAROUND ON)
set(BUILD_STATIC_LIB ON)
set(BUILD_ASSIMP_TOOLS OFF)
set(SYSTEM_IRRXML OFF)
set(ASSIMP_BUILD_STATIC_LIB ON)

add_subdirectory(third-party/assimp/)
add_subdirectory(third-party/freetype-2.8.1/)

file(GLOB_RECURSE source_files src/*)
file(GLOB_RECURSE SHADER_FILES *.glsl)
file(GLOB HEADER_FILES *.hpp)

add_executable(
        Pacman3D
        ${source_files}
        ${HEADER_FILES}
        ${SHADER_FILES}
)

target_link_libraries(
        Pacman3D
        ${ALL_LIBRARIES}
)

file(COPY shaders DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
