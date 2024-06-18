cmake_minimum_required(VERSION 3.15)
project(calc C)

# Set C standard to C99
set(CMAKE_C_STANDARD 99)

# Define source files
set(SOURCES main.c)

# Define raylib and raygui versions
set(RAYLIB_VERSION 4.2.0)
set(RAYGUI_VERSION 3.2)

# Download and build raylib
include(FetchContent)
FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG ${RAYLIB_VERSION}
)
FetchContent_MakeAvailable(raylib)

# Download and build raygui
FetchContent_Declare(
    raygui
    GIT_REPOSITORY https://github.com/raysan5/raygui.git
    GIT_TAG ${RAYGUI_VERSION}
)
FetchContent_MakeAvailable(raygui)

# Create executable
add_executable(calc ${SOURCES})

# Link libraries
target_link_libraries(calc raylib)


# Platform-specific settings
if (WIN32)
    set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")
    target_link_libraries(calc winmm.lib)
elseif (UNIX)
    target_link_libraries(calc m)
    if (APPLE)
        target_link_libraries(calc "-framework CoreVideo" "-framework IOKit" "-framework Cocoa" "-framework GLUT" "-framework OpenGL")
    else()
        target_link_libraries(calc GL GLU X11)
    endif()
endif()

# Copy raygui files to build directory
add_custom_command(TARGET calc POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${raygui_SOURCE_DIR}/src ${CMAKE_BINARY_DIR}/src)

# Include directories for raylib and raygui
target_include_directories(calc PRIVATE
    ${raylib_SOURCE_DIR}/src
    ${raygui_SOURCE_DIR}/src
)
# Set the working directory to the location of the executable
set_target_properties(calc PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_BINARY_DIR}")
