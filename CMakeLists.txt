cmake_minimum_required(VERSION 3.28)
project(CMakeSFMLProject LANGUAGES CXX)

# Set the output directory for binaries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Option to build shared or static libraries
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

# Include FetchContent module to pull SFML from GitHub
include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM
)
FetchContent_MakeAvailable(SFML)

# Add executable for your main.cpp
add_executable(main src/main.cpp
        src/customPhysics.cpp
        src/customPhysics.h)

# Link SFML graphics, window, and system modules
target_link_libraries(main PRIVATE sfml-graphics sfml-window sfml-system)

# Use C++17 features
target_compile_features(main PRIVATE cxx_std_17)

# Add platform-specific dependencies (Linux)
if(UNIX AND NOT APPLE)
    find_package(X11 REQUIRED)     # Find X11 libraries
    target_link_libraries(main PRIVATE X11) # Link X11 to the project
    target_link_libraries(main PRIVATE pthread dl rt freetype udev) # Link other required system libraries
endif()

# On Windows, copy the OpenAL DLL for audio (only necessary for Windows)
if(WIN32)
    add_custom_command(
            TARGET main
            COMMENT "Copy OpenAL DLL"
            PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy
            ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll
            $<TARGET_FILE_DIR:main>
            VERBATIM
    )
endif()
