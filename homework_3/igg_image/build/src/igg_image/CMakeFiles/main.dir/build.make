# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/piet/Projects/modern-cpp-course/homework_3/igg_image

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/piet/Projects/modern-cpp-course/homework_3/igg_image/build

# Include any dependencies generated for this target.
include src/igg_image/CMakeFiles/main.dir/depend.make

# Include the progress variables for this target.
include src/igg_image/CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include src/igg_image/CMakeFiles/main.dir/flags.make

src/igg_image/CMakeFiles/main.dir/main.cpp.o: src/igg_image/CMakeFiles/main.dir/flags.make
src/igg_image/CMakeFiles/main.dir/main.cpp.o: ../src/igg_image/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/piet/Projects/modern-cpp-course/homework_3/igg_image/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/igg_image/CMakeFiles/main.dir/main.cpp.o"
	cd /home/piet/Projects/modern-cpp-course/homework_3/igg_image/build/src/igg_image && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/main.cpp.o -c /home/piet/Projects/modern-cpp-course/homework_3/igg_image/src/igg_image/main.cpp

src/igg_image/CMakeFiles/main.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/main.cpp.i"
	cd /home/piet/Projects/modern-cpp-course/homework_3/igg_image/build/src/igg_image && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/piet/Projects/modern-cpp-course/homework_3/igg_image/src/igg_image/main.cpp > CMakeFiles/main.dir/main.cpp.i

src/igg_image/CMakeFiles/main.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/main.cpp.s"
	cd /home/piet/Projects/modern-cpp-course/homework_3/igg_image/build/src/igg_image && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/piet/Projects/modern-cpp-course/homework_3/igg_image/src/igg_image/main.cpp -o CMakeFiles/main.dir/main.cpp.s

src/igg_image/CMakeFiles/main.dir/main.cpp.o.requires:

.PHONY : src/igg_image/CMakeFiles/main.dir/main.cpp.o.requires

src/igg_image/CMakeFiles/main.dir/main.cpp.o.provides: src/igg_image/CMakeFiles/main.dir/main.cpp.o.requires
	$(MAKE) -f src/igg_image/CMakeFiles/main.dir/build.make src/igg_image/CMakeFiles/main.dir/main.cpp.o.provides.build
.PHONY : src/igg_image/CMakeFiles/main.dir/main.cpp.o.provides

src/igg_image/CMakeFiles/main.dir/main.cpp.o.provides.build: src/igg_image/CMakeFiles/main.dir/main.cpp.o


# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/main.cpp.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

../bin/main: src/igg_image/CMakeFiles/main.dir/main.cpp.o
../bin/main: src/igg_image/CMakeFiles/main.dir/build.make
../bin/main: /usr/lib/x86_64-linux-gnu/libpng.so
../bin/main: /usr/lib/x86_64-linux-gnu/libz.so
../bin/main: ../lib/libstrategies.a
../bin/main: ../lib/libimage.a
../bin/main: src/igg_image/CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/piet/Projects/modern-cpp-course/homework_3/igg_image/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../../bin/main"
	cd /home/piet/Projects/modern-cpp-course/homework_3/igg_image/build/src/igg_image && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/igg_image/CMakeFiles/main.dir/build: ../bin/main

.PHONY : src/igg_image/CMakeFiles/main.dir/build

src/igg_image/CMakeFiles/main.dir/requires: src/igg_image/CMakeFiles/main.dir/main.cpp.o.requires

.PHONY : src/igg_image/CMakeFiles/main.dir/requires

src/igg_image/CMakeFiles/main.dir/clean:
	cd /home/piet/Projects/modern-cpp-course/homework_3/igg_image/build/src/igg_image && $(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : src/igg_image/CMakeFiles/main.dir/clean

src/igg_image/CMakeFiles/main.dir/depend:
	cd /home/piet/Projects/modern-cpp-course/homework_3/igg_image/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/piet/Projects/modern-cpp-course/homework_3/igg_image /home/piet/Projects/modern-cpp-course/homework_3/igg_image/src/igg_image /home/piet/Projects/modern-cpp-course/homework_3/igg_image/build /home/piet/Projects/modern-cpp-course/homework_3/igg_image/build/src/igg_image /home/piet/Projects/modern-cpp-course/homework_3/igg_image/build/src/igg_image/CMakeFiles/main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/igg_image/CMakeFiles/main.dir/depend

