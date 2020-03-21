# If you are not on Linux, you will need to download the source of the
# googletest framework manually and provide the folder to which you have
# - downloaded it by copying this link into your browser:
#   https://github.com/google/googletest/archive/release-1.8.0.zip
# - unpack it into some <FOLDER>
# - use this <FOLDER> instead of /usr/src/gtest in the line below.
add_subdirectory(/usr/src/gtest
                 ${PROJECT_BINARY_DIR}/gtest)
include(CTest) # Include testing cmake package.
set(TEST_BINARY ${PROJECT_NAME}_test)

# find library
find_library(TOOLS NAMES io_tools PATHS ${LIBRARY_OUTPUT_PATH})
add_library(io_tools SHARED IMPORTED)
set_property(TARGET io_tools PROPERTY IMPORTED_LOCATION "${TOOLS}")

# executable that runs the test
add_executable(test_image test_image.cpp)

# link the executable to the libraries that we want to test 
target_link_libraries(test_image
					  image
					  io_tools
					  gtest gtest_main)

# Add gtest to be able to run ctest
add_test(test_image ${PROJECT_SOURCE_DIR}/bin/test_image) 

                                                     