# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/moos-ivp-douglas

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/moos-ivp-douglas/build

# Include any dependencies generated for this target.
include src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/compiler_depend.make

# Include the progress variables for this target.
include src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/progress.make

# Include the compile flags for this target's objects.
include src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/flags.make

src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/BHV_SimpleWaypoint.cpp.o: src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/flags.make
src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/BHV_SimpleWaypoint.cpp.o: ../src/lib_behaviors-test/BHV_SimpleWaypoint.cpp
src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/BHV_SimpleWaypoint.cpp.o: src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/moos-ivp-douglas/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/BHV_SimpleWaypoint.cpp.o"
	cd /home/moos-ivp-douglas/build/src/lib_behaviors-test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/BHV_SimpleWaypoint.cpp.o -MF CMakeFiles/BHV_SimpleWaypoint.dir/BHV_SimpleWaypoint.cpp.o.d -o CMakeFiles/BHV_SimpleWaypoint.dir/BHV_SimpleWaypoint.cpp.o -c /home/moos-ivp-douglas/src/lib_behaviors-test/BHV_SimpleWaypoint.cpp

src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/BHV_SimpleWaypoint.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BHV_SimpleWaypoint.dir/BHV_SimpleWaypoint.cpp.i"
	cd /home/moos-ivp-douglas/build/src/lib_behaviors-test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/moos-ivp-douglas/src/lib_behaviors-test/BHV_SimpleWaypoint.cpp > CMakeFiles/BHV_SimpleWaypoint.dir/BHV_SimpleWaypoint.cpp.i

src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/BHV_SimpleWaypoint.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BHV_SimpleWaypoint.dir/BHV_SimpleWaypoint.cpp.s"
	cd /home/moos-ivp-douglas/build/src/lib_behaviors-test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/moos-ivp-douglas/src/lib_behaviors-test/BHV_SimpleWaypoint.cpp -o CMakeFiles/BHV_SimpleWaypoint.dir/BHV_SimpleWaypoint.cpp.s

src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/AOF_SimpleWaypoint.cpp.o: src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/flags.make
src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/AOF_SimpleWaypoint.cpp.o: ../src/lib_behaviors-test/AOF_SimpleWaypoint.cpp
src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/AOF_SimpleWaypoint.cpp.o: src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/moos-ivp-douglas/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/AOF_SimpleWaypoint.cpp.o"
	cd /home/moos-ivp-douglas/build/src/lib_behaviors-test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/AOF_SimpleWaypoint.cpp.o -MF CMakeFiles/BHV_SimpleWaypoint.dir/AOF_SimpleWaypoint.cpp.o.d -o CMakeFiles/BHV_SimpleWaypoint.dir/AOF_SimpleWaypoint.cpp.o -c /home/moos-ivp-douglas/src/lib_behaviors-test/AOF_SimpleWaypoint.cpp

src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/AOF_SimpleWaypoint.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BHV_SimpleWaypoint.dir/AOF_SimpleWaypoint.cpp.i"
	cd /home/moos-ivp-douglas/build/src/lib_behaviors-test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/moos-ivp-douglas/src/lib_behaviors-test/AOF_SimpleWaypoint.cpp > CMakeFiles/BHV_SimpleWaypoint.dir/AOF_SimpleWaypoint.cpp.i

src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/AOF_SimpleWaypoint.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BHV_SimpleWaypoint.dir/AOF_SimpleWaypoint.cpp.s"
	cd /home/moos-ivp-douglas/build/src/lib_behaviors-test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/moos-ivp-douglas/src/lib_behaviors-test/AOF_SimpleWaypoint.cpp -o CMakeFiles/BHV_SimpleWaypoint.dir/AOF_SimpleWaypoint.cpp.s

# Object files for target BHV_SimpleWaypoint
BHV_SimpleWaypoint_OBJECTS = \
"CMakeFiles/BHV_SimpleWaypoint.dir/BHV_SimpleWaypoint.cpp.o" \
"CMakeFiles/BHV_SimpleWaypoint.dir/AOF_SimpleWaypoint.cpp.o"

# External object files for target BHV_SimpleWaypoint
BHV_SimpleWaypoint_EXTERNAL_OBJECTS =

../lib/libBHV_SimpleWaypoint.so: src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/BHV_SimpleWaypoint.cpp.o
../lib/libBHV_SimpleWaypoint.so: src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/AOF_SimpleWaypoint.cpp.o
../lib/libBHV_SimpleWaypoint.so: src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/build.make
../lib/libBHV_SimpleWaypoint.so: src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/moos-ivp-douglas/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX shared library ../../../lib/libBHV_SimpleWaypoint.so"
	cd /home/moos-ivp-douglas/build/src/lib_behaviors-test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BHV_SimpleWaypoint.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/build: ../lib/libBHV_SimpleWaypoint.so
.PHONY : src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/build

src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/clean:
	cd /home/moos-ivp-douglas/build/src/lib_behaviors-test && $(CMAKE_COMMAND) -P CMakeFiles/BHV_SimpleWaypoint.dir/cmake_clean.cmake
.PHONY : src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/clean

src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/depend:
	cd /home/moos-ivp-douglas/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/moos-ivp-douglas /home/moos-ivp-douglas/src/lib_behaviors-test /home/moos-ivp-douglas/build /home/moos-ivp-douglas/build/src/lib_behaviors-test /home/moos-ivp-douglas/build/src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/lib_behaviors-test/CMakeFiles/BHV_SimpleWaypoint.dir/depend

