# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /home/fred/clion-2018.3.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/fred/clion-2018.3.3/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/fred/CLionProjects/CMPT135

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fred/CLionProjects/CMPT135/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/swapping.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/swapping.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/swapping.dir/flags.make

CMakeFiles/swapping.dir/swapping.cpp.o: CMakeFiles/swapping.dir/flags.make
CMakeFiles/swapping.dir/swapping.cpp.o: ../swapping.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fred/CLionProjects/CMPT135/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/swapping.dir/swapping.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/swapping.dir/swapping.cpp.o -c /home/fred/CLionProjects/CMPT135/swapping.cpp

CMakeFiles/swapping.dir/swapping.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/swapping.dir/swapping.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fred/CLionProjects/CMPT135/swapping.cpp > CMakeFiles/swapping.dir/swapping.cpp.i

CMakeFiles/swapping.dir/swapping.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/swapping.dir/swapping.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fred/CLionProjects/CMPT135/swapping.cpp -o CMakeFiles/swapping.dir/swapping.cpp.s

# Object files for target swapping
swapping_OBJECTS = \
"CMakeFiles/swapping.dir/swapping.cpp.o"

# External object files for target swapping
swapping_EXTERNAL_OBJECTS =

swapping: CMakeFiles/swapping.dir/swapping.cpp.o
swapping: CMakeFiles/swapping.dir/build.make
swapping: CMakeFiles/swapping.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fred/CLionProjects/CMPT135/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable swapping"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/swapping.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/swapping.dir/build: swapping

.PHONY : CMakeFiles/swapping.dir/build

CMakeFiles/swapping.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/swapping.dir/cmake_clean.cmake
.PHONY : CMakeFiles/swapping.dir/clean

CMakeFiles/swapping.dir/depend:
	cd /home/fred/CLionProjects/CMPT135/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fred/CLionProjects/CMPT135 /home/fred/CLionProjects/CMPT135 /home/fred/CLionProjects/CMPT135/cmake-build-debug /home/fred/CLionProjects/CMPT135/cmake-build-debug /home/fred/CLionProjects/CMPT135/cmake-build-debug/CMakeFiles/swapping.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/swapping.dir/depend

