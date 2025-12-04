cmake_minimum_required(VERSION 3.15)
project(Gravity)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
include(FetchContent)
set(THREEPP_BUILD_TESTS OFF)
set(THREEPP_BUILD_EXAMPLES OFF)
FetchContent_Declare(
        threepp
        GIT_REPOSITORY https://github.com/markaren/threepp.git
        GIT_TAG 619cdaacc2e7dc6ea709d8c7f482e2994af7349d
)
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.4.0
)

FetchContent_MakeAvailable(Catch2)
enable_testing()

FetchContent_MakeAvailable(threepp)

add_executable(GravSim runSim.cpp)


add_subdirectory(tests)
target_link_libraries(GravSim PUBLIC threepp::threepp)
target_include_directories(GravSim PUBLIC include)

#target_compile_definitions(GravSim PUBLIC DATA_DIR="${CMAKE_BINARY_DIR}/bin")

