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

# Utility rule file for ExperimentalStart.

# Include the progress variables for this target.
include tests/CMakeFiles/ExperimentalStart.dir/progress.make

tests/CMakeFiles/ExperimentalStart:
	cd /home/piet/Projects/modern-cpp-course/homework_3/igg_image/build/tests && /usr/bin/ctest -D ExperimentalStart

ExperimentalStart: tests/CMakeFiles/ExperimentalStart
ExperimentalStart: tests/CMakeFiles/ExperimentalStart.dir/build.make

.PHONY : ExperimentalStart

# Rule to build all files generated by this target.
tests/CMakeFiles/ExperimentalStart.dir/build: ExperimentalStart

.PHONY : tests/CMakeFiles/ExperimentalStart.dir/build

tests/CMakeFiles/ExperimentalStart.dir/clean:
	cd /home/piet/Projects/modern-cpp-course/homework_3/igg_image/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/ExperimentalStart.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/ExperimentalStart.dir/clean

tests/CMakeFiles/ExperimentalStart.dir/depend:
	cd /home/piet/Projects/modern-cpp-course/homework_3/igg_image/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/piet/Projects/modern-cpp-course/homework_3/igg_image /home/piet/Projects/modern-cpp-course/homework_3/igg_image/tests /home/piet/Projects/modern-cpp-course/homework_3/igg_image/build /home/piet/Projects/modern-cpp-course/homework_3/igg_image/build/tests /home/piet/Projects/modern-cpp-course/homework_3/igg_image/build/tests/CMakeFiles/ExperimentalStart.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/ExperimentalStart.dir/depend
