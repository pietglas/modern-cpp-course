add_subdirectory(/usr/src/gtest
                 ${PROJECT_BINARY_DIR}/gtest)
include(CTest) 
set(TEST_BINARY ${PROJECT_NAME}_test)

add_executable(test_digit tests.cpp)

target_link_libraries(test_digit
					  gtest gtest_main)

add_test(test_image ${PROJECT_SOURCE_DIR}/bin/test_digit)