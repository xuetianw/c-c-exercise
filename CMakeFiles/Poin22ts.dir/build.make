# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_BINARY_DIR = /home/fred/CLionProjects/CMPT135

# Include any dependencies generated for this target.
include CMakeFiles/Poin22ts.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Poin22ts.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Poin22ts.dir/flags.make

CMakeFiles/Poin22ts.dir/swapping.cpp.o: CMakeFiles/Poin22ts.dir/flags.make
CMakeFiles/Poin22ts.dir/swapping.cpp.o: swapping.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fred/CLionProjects/CMPT135/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Poin22ts.dir/swapping.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Poin22ts.dir/swapping.cpp.o -c /home/fred/CLionProjects/CMPT135/swapping.cpp

CMakeFiles/Poin22ts.dir/swapping.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Poin22ts.dir/swapping.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fred/CLionProjects/CMPT135/swapping.cpp > CMakeFiles/Poin22ts.dir/swapping.cpp.i

CMakeFiles/Poin22ts.dir/swapping.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Poin22ts.dir/swapping.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fred/CLionProjects/CMPT135/swapping.cpp -o CMakeFiles/Poin22ts.dir/swapping.cpp.s

# Object files for target Poin22ts
Poin22ts_OBJECTS = \
"CMakeFiles/Poin22ts.dir/swapping.cpp.o"

# External object files for target Poin22ts
Poin22ts_EXTERNAL_OBJECTS =

bin/Poin22ts: CMakeFiles/Poin22ts.dir/swapping.cpp.o
bin/Poin22ts: CMakeFiles/Poin22ts.dir/build.make
bin/Poin22ts: CMakeFiles/Poin22ts.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fred/CLionProjects/CMPT135/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin/Poin22ts"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Poin22ts.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Poin22ts.dir/build: bin/Poin22ts

.PHONY : CMakeFiles/Poin22ts.dir/build

CMakeFiles/Poin22ts.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Poin22ts.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Poin22ts.dir/clean

CMakeFiles/Poin22ts.dir/depend:
	cd /home/fred/CLionProjects/CMPT135 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fred/CLionProjects/CMPT135 /home/fred/CLionProjects/CMPT135 /home/fred/CLionProjects/CMPT135 /home/fred/CLionProjects/CMPT135 /home/fred/CLionProjects/CMPT135/CMakeFiles/Poin22ts.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Poin22ts.dir/depend
