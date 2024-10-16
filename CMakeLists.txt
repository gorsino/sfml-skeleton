cmake_minimum_required(VERSION 3.28)
project(sfml-skeleton LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(sfml-skeleton src/main.cpp
        src/Game.cpp
        src/Game.h
        src/Debug/DebugText.cpp
        src/Debug/DebugText.h
        src/ParticleSystem.cpp
        src/ParticleSystem.h
        src/Debug/MousePositionsText.cpp
        src/Debug/MousePositionsText.h
)
target_link_libraries(sfml-skeleton PRIVATE sfml-graphics)
target_compile_features(sfml-skeleton PRIVATE cxx_std_17)

file(COPY resources DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

if (WIN32)
    add_custom_command(
            TARGET sfml-skeleton
            COMMENT "Copy OpenAL DLL"
            PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:sfml-skeleton>
            VERBATIM)
endif ()