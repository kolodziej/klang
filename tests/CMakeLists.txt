find_package(Catch2 REQUIRED)

add_executable(lexer_tests lexer_tests.cpp)
target_link_libraries(lexer_tests Catch2::Catch2 klang)
