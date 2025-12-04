add_executable(testyTests testyTests.cpp)
#Below:Given by copilot
target_link_libraries(testyTests PRIVATE Catch2::Catch2WithMain)
target_include_directories(testyTests PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(testyTests PUBLIC threepp::threepp)
#target_compile_definitions(testyTests PUBLIC DATA_DIR="${CMAKE_BINARY_DIR}/bin")#did not work in actions T_T
add_test(NAME testyTests COMMAND testyTests)

