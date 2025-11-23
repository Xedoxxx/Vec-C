add_executable(test_vec vec_test.c)
target_link_libraries(test_vec vec_t)
target_include_directories(test_vec PRIVATE ${CMAKE_SOURCE_DIR}/include)

add_test(NAME VecTests COMMAND test_vec)