# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = /home/douglas/.local/lib/python3.10/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /home/douglas/.local/lib/python3.10/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/moos-ivp-douglas

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/moos-ivp-douglas/build

# Include any dependencies generated for this target.
include src/pIMU/CMakeFiles/xbow440.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/pIMU/CMakeFiles/xbow440.dir/compiler_depend.make

# Include the progress variables for this target.
include src/pIMU/CMakeFiles/xbow440.dir/progress.make

# Include the compile flags for this target's objects.
include src/pIMU/CMakeFiles/xbow440.dir/flags.make

src/pIMU/CMakeFiles/xbow440.dir/src/xbow440.cpp.o: src/pIMU/CMakeFiles/xbow440.dir/flags.make
src/pIMU/CMakeFiles/xbow440.dir/src/xbow440.cpp.o: /home/moos-ivp-douglas/src/pIMU/src/xbow440.cpp
src/pIMU/CMakeFiles/xbow440.dir/src/xbow440.cpp.o: src/pIMU/CMakeFiles/xbow440.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/moos-ivp-douglas/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/pIMU/CMakeFiles/xbow440.dir/src/xbow440.cpp.o"
	cd /home/moos-ivp-douglas/build/src/pIMU && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/pIMU/CMakeFiles/xbow440.dir/src/xbow440.cpp.o -MF CMakeFiles/xbow440.dir/src/xbow440.cpp.o.d -o CMakeFiles/xbow440.dir/src/xbow440.cpp.o -c /home/moos-ivp-douglas/src/pIMU/src/xbow440.cpp

src/pIMU/CMakeFiles/xbow440.dir/src/xbow440.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/xbow440.dir/src/xbow440.cpp.i"
	cd /home/moos-ivp-douglas/build/src/pIMU && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/moos-ivp-douglas/src/pIMU/src/xbow440.cpp > CMakeFiles/xbow440.dir/src/xbow440.cpp.i

src/pIMU/CMakeFiles/xbow440.dir/src/xbow440.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/xbow440.dir/src/xbow440.cpp.s"
	cd /home/moos-ivp-douglas/build/src/pIMU && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/moos-ivp-douglas/src/pIMU/src/xbow440.cpp -o CMakeFiles/xbow440.dir/src/xbow440.cpp.s

# Object files for target xbow440
xbow440_OBJECTS = \
"CMakeFiles/xbow440.dir/src/xbow440.cpp.o"

# External object files for target xbow440
xbow440_EXTERNAL_OBJECTS =

/home/moos-ivp-douglas/lib/libxbow440.a: src/pIMU/CMakeFiles/xbow440.dir/src/xbow440.cpp.o
/home/moos-ivp-douglas/lib/libxbow440.a: src/pIMU/CMakeFiles/xbow440.dir/build.make
/home/moos-ivp-douglas/lib/libxbow440.a: src/pIMU/CMakeFiles/xbow440.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/moos-ivp-douglas/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library /home/moos-ivp-douglas/lib/libxbow440.a"
	cd /home/moos-ivp-douglas/build/src/pIMU && $(CMAKE_COMMAND) -P CMakeFiles/xbow440.dir/cmake_clean_target.cmake
	cd /home/moos-ivp-douglas/build/src/pIMU && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/xbow440.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/pIMU/CMakeFiles/xbow440.dir/build: /home/moos-ivp-douglas/lib/libxbow440.a
.PHONY : src/pIMU/CMakeFiles/xbow440.dir/build

src/pIMU/CMakeFiles/xbow440.dir/clean:
	cd /home/moos-ivp-douglas/build/src/pIMU && $(CMAKE_COMMAND) -P CMakeFiles/xbow440.dir/cmake_clean.cmake
.PHONY : src/pIMU/CMakeFiles/xbow440.dir/clean

src/pIMU/CMakeFiles/xbow440.dir/depend:
	cd /home/moos-ivp-douglas/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/moos-ivp-douglas /home/moos-ivp-douglas/src/pIMU /home/moos-ivp-douglas/build /home/moos-ivp-douglas/build/src/pIMU /home/moos-ivp-douglas/build/src/pIMU/CMakeFiles/xbow440.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/pIMU/CMakeFiles/xbow440.dir/depend
