find_library(TOOLS libio_tools.so ${LIBRARY_OUTPUT_PATH})
add_library(image image.cpp)

add_executable(lib libio_tools.so)
add_executable(bin_main main.cpp)

target_link_libraries(bin_main 
					${TOOLS}
					image)


