# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
include test/lib/googlemock/CMakeFiles/gmock_main.dir/depend.make

# Include the progress variables for this target.
include test/lib/googlemock/CMakeFiles/gmock_main.dir/progress.make

# Include the compile flags for this target's objects.
include test/lib/googlemock/CMakeFiles/gmock_main.dir/flags.make

test/lib/googlemock/CMakeFiles/gmock_main.dir/__/googletest/src/gtest-all.cc.o: test/lib/googlemock/CMakeFiles/gmock_main.dir/flags.make
test/lib/googlemock/CMakeFiles/gmock_main.dir/__/googletest/src/gtest-all.cc.o: test/lib/googletest/src/gtest-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fred/CLionProjects/CMPT135/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/lib/googlemock/CMakeFiles/gmock_main.dir/__/googletest/src/gtest-all.cc.o"
	cd /home/fred/CLionProjects/CMPT135/test/lib/googlemock && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gmock_main.dir/__/googletest/src/gtest-all.cc.o -c /home/fred/CLionProjects/CMPT135/test/lib/googletest/src/gtest-all.cc

test/lib/googlemock/CMakeFiles/gmock_main.dir/__/googletest/src/gtest-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmock_main.dir/__/googletest/src/gtest-all.cc.i"
	cd /home/fred/CLionProjects/CMPT135/test/lib/googlemock && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fred/CLionProjects/CMPT135/test/lib/googletest/src/gtest-all.cc > CMakeFiles/gmock_main.dir/__/googletest/src/gtest-all.cc.i

test/lib/googlemock/CMakeFiles/gmock_main.dir/__/googletest/src/gtest-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmock_main.dir/__/googletest/src/gtest-all.cc.s"
	cd /home/fred/CLionProjects/CMPT135/test/lib/googlemock && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fred/CLionProjects/CMPT135/test/lib/googletest/src/gtest-all.cc -o CMakeFiles/gmock_main.dir/__/googletest/src/gtest-all.cc.s

test/lib/googlemock/CMakeFiles/gmock_main.dir/src/gmock-all.cc.o: test/lib/googlemock/CMakeFiles/gmock_main.dir/flags.make
test/lib/googlemock/CMakeFiles/gmock_main.dir/src/gmock-all.cc.o: test/lib/googlemock/src/gmock-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fred/CLionProjects/CMPT135/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object test/lib/googlemock/CMakeFiles/gmock_main.dir/src/gmock-all.cc.o"
	cd /home/fred/CLionProjects/CMPT135/test/lib/googlemock && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gmock_main.dir/src/gmock-all.cc.o -c /home/fred/CLionProjects/CMPT135/test/lib/googlemock/src/gmock-all.cc

test/lib/googlemock/CMakeFiles/gmock_main.dir/src/gmock-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmock_main.dir/src/gmock-all.cc.i"
	cd /home/fred/CLionProjects/CMPT135/test/lib/googlemock && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fred/CLionProjects/CMPT135/test/lib/googlemock/src/gmock-all.cc > CMakeFiles/gmock_main.dir/src/gmock-all.cc.i

test/lib/googlemock/CMakeFiles/gmock_main.dir/src/gmock-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmock_main.dir/src/gmock-all.cc.s"
	cd /home/fred/CLionProjects/CMPT135/test/lib/googlemock && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fred/CLionProjects/CMPT135/test/lib/googlemock/src/gmock-all.cc -o CMakeFiles/gmock_main.dir/src/gmock-all.cc.s

test/lib/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o: test/lib/googlemock/CMakeFiles/gmock_main.dir/flags.make
test/lib/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o: test/lib/googlemock/src/gmock_main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fred/CLionProjects/CMPT135/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object test/lib/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o"
	cd /home/fred/CLionProjects/CMPT135/test/lib/googlemock && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gmock_main.dir/src/gmock_main.cc.o -c /home/fred/CLionProjects/CMPT135/test/lib/googlemock/src/gmock_main.cc

test/lib/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmock_main.dir/src/gmock_main.cc.i"
	cd /home/fred/CLionProjects/CMPT135/test/lib/googlemock && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fred/CLionProjects/CMPT135/test/lib/googlemock/src/gmock_main.cc > CMakeFiles/gmock_main.dir/src/gmock_main.cc.i

test/lib/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmock_main.dir/src/gmock_main.cc.s"
	cd /home/fred/CLionProjects/CMPT135/test/lib/googlemock && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fred/CLionProjects/CMPT135/test/lib/googlemock/src/gmock_main.cc -o CMakeFiles/gmock_main.dir/src/gmock_main.cc.s

# Object files for target gmock_main
gmock_main_OBJECTS = \
"CMakeFiles/gmock_main.dir/__/googletest/src/gtest-all.cc.o" \
"CMakeFiles/gmock_main.dir/src/gmock-all.cc.o" \
"CMakeFiles/gmock_main.dir/src/gmock_main.cc.o"

# External object files for target gmock_main
gmock_main_EXTERNAL_OBJECTS =

lib/libgmock_main.a: test/lib/googlemock/CMakeFiles/gmock_main.dir/__/googletest/src/gtest-all.cc.o
lib/libgmock_main.a: test/lib/googlemock/CMakeFiles/gmock_main.dir/src/gmock-all.cc.o
lib/libgmock_main.a: test/lib/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o
lib/libgmock_main.a: test/lib/googlemock/CMakeFiles/gmock_main.dir/build.make
lib/libgmock_main.a: test/lib/googlemock/CMakeFiles/gmock_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fred/CLionProjects/CMPT135/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library ../../../lib/libgmock_main.a"
	cd /home/fred/CLionProjects/CMPT135/test/lib/googlemock && $(CMAKE_COMMAND) -P CMakeFiles/gmock_main.dir/cmake_clean_target.cmake
	cd /home/fred/CLionProjects/CMPT135/test/lib/googlemock && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gmock_main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/lib/googlemock/CMakeFiles/gmock_main.dir/build: lib/libgmock_main.a

.PHONY : test/lib/googlemock/CMakeFiles/gmock_main.dir/build

test/lib/googlemock/CMakeFiles/gmock_main.dir/clean:
	cd /home/fred/CLionProjects/CMPT135/test/lib/googlemock && $(CMAKE_COMMAND) -P CMakeFiles/gmock_main.dir/cmake_clean.cmake
.PHONY : test/lib/googlemock/CMakeFiles/gmock_main.dir/clean

test/lib/googlemock/CMakeFiles/gmock_main.dir/depend:
	cd /home/fred/CLionProjects/CMPT135 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fred/CLionProjects/CMPT135 /home/fred/CLionProjects/CMPT135/test/lib/googlemock /home/fred/CLionProjects/CMPT135 /home/fred/CLionProjects/CMPT135/test/lib/googlemock /home/fred/CLionProjects/CMPT135/test/lib/googlemock/CMakeFiles/gmock_main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/lib/googlemock/CMakeFiles/gmock_main.dir/depend

