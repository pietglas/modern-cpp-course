add_subdirectory(io_strategies)

add_library(image image.cpp)
add_executable(main main.cpp)

find_package(PNG REQUIRED)
include_directories(${PNG_INCLUDE_DIRS})

target_link_libraries(main
					  ${PNG_LIBRARIES}
					  strategies
					  image)

