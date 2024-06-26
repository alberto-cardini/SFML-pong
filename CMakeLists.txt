cmake_minimum_required(VERSION 3.16)
project(SFML-pong LANGUAGES CXX)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_Declare(googletest
        # Specify the commit you depend on and update it regularly.
        GIT_REPOSITORY https://github.com/google/googletest
        GIT_TAG v1.14.0
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
FetchContent_MakeAvailable(SFML)

include_directories(inc)
include_directories(src)
include_directories(test)

set(SOURCE_FILE

        src/Game.cpp
        src/User.cpp
        src/Ball.cpp
        src/Entity.cpp
        src/HUD.cpp
        src/AssetManager.cpp

        test/RunAllTest.cpp

)

set(INCLUDE_FILE

        inc/Game.hpp
        inc/Ball.hpp
        inc/User.hpp
        inc/Entity.hpp
        inc/HUD.hpp
        inc/AssetManager.hpp

)

add_executable(${PROJECT_NAME}
        main.cpp
        ${SOURCE_FILE}
        ${INCLUDE_FILE}
)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics)
target_link_libraries(${PROJECT_NAME} PRIVATE gtest_main)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
add_test(NAME example_test COMMAND example)

if(WIN32)
    add_custom_command(
        TARGET SFML-pong
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:SFML-pong>
        VERBATIM)
endif()

install(TARGETS ${PROJECT_NAME})
