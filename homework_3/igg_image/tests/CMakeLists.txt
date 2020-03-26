add_subdirectory(/usr/src/gtest
                 ${PROJECT_BINARY_DIR}/gtest)
include(CTest) # Include testing cmake package.
set(TEST_BINARY ${PROJECT_NAME}_test)

add_executable(test_image tests.cpp)

target_link_libraries(test_image
					  ${PNG_LIBRARIES}
					  strategies
					  image
					  gtest gtest_main)

add_test(test_image ${PROJECT_SOURCE_DIR}/bin/test_image)

