add_library(digit_counting digit_counting.cpp)

add_executable(main main.cpp)

target_link_libraries(main
					  digit_counting)