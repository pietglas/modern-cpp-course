find_library(TOOLS NAMES io_tools PATHS ${LIBRARY_OUTPUT_PATH})
add_library(image image.cpp)

add_library(io_tools SHARED IMPORTED)
set_property(TARGET io_tools PROPERTY IMPORTED_LOCATION "${TOOLS}")

add_executable(bin_main main.cpp)

target_link_libraries(bin_main 
					image
					io_tools)


