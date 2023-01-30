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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/moos-ivp-douglas

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/moos-ivp-douglas/build

# Include any dependencies generated for this target.
include src/lib/graphics/CMakeFiles/graphics.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/lib/graphics/CMakeFiles/graphics.dir/compiler_depend.make

# Include the progress variables for this target.
include src/lib/graphics/CMakeFiles/graphics.dir/progress.make

# Include the compile flags for this target's objects.
include src/lib/graphics/CMakeFiles/graphics.dir/flags.make

src/lib/graphics/CMakeFiles/graphics.dir/vibes/vibes.cpp.o: src/lib/graphics/CMakeFiles/graphics.dir/flags.make
src/lib/graphics/CMakeFiles/graphics.dir/vibes/vibes.cpp.o: /home/moos-ivp-douglas/src/lib/graphics/vibes/vibes.cpp
src/lib/graphics/CMakeFiles/graphics.dir/vibes/vibes.cpp.o: src/lib/graphics/CMakeFiles/graphics.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/moos-ivp-douglas/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/lib/graphics/CMakeFiles/graphics.dir/vibes/vibes.cpp.o"
	cd /home/moos-ivp-douglas/build/src/lib/graphics && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/lib/graphics/CMakeFiles/graphics.dir/vibes/vibes.cpp.o -MF CMakeFiles/graphics.dir/vibes/vibes.cpp.o.d -o CMakeFiles/graphics.dir/vibes/vibes.cpp.o -c /home/moos-ivp-douglas/src/lib/graphics/vibes/vibes.cpp

src/lib/graphics/CMakeFiles/graphics.dir/vibes/vibes.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graphics.dir/vibes/vibes.cpp.i"
	cd /home/moos-ivp-douglas/build/src/lib/graphics && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/moos-ivp-douglas/src/lib/graphics/vibes/vibes.cpp > CMakeFiles/graphics.dir/vibes/vibes.cpp.i

src/lib/graphics/CMakeFiles/graphics.dir/vibes/vibes.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graphics.dir/vibes/vibes.cpp.s"
	cd /home/moos-ivp-douglas/build/src/lib/graphics && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/moos-ivp-douglas/src/lib/graphics/vibes/vibes.cpp -o CMakeFiles/graphics.dir/vibes/vibes.cpp.s

# Object files for target graphics
graphics_OBJECTS = \
"CMakeFiles/graphics.dir/vibes/vibes.cpp.o"

# External object files for target graphics
graphics_EXTERNAL_OBJECTS =

/home/moos-ivp-douglas/lib/libgraphics.a: src/lib/graphics/CMakeFiles/graphics.dir/vibes/vibes.cpp.o
/home/moos-ivp-douglas/lib/libgraphics.a: src/lib/graphics/CMakeFiles/graphics.dir/build.make
/home/moos-ivp-douglas/lib/libgraphics.a: src/lib/graphics/CMakeFiles/graphics.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/moos-ivp-douglas/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library /home/moos-ivp-douglas/lib/libgraphics.a"
	cd /home/moos-ivp-douglas/build/src/lib/graphics && $(CMAKE_COMMAND) -P CMakeFiles/graphics.dir/cmake_clean_target.cmake
	cd /home/moos-ivp-douglas/build/src/lib/graphics && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/graphics.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/lib/graphics/CMakeFiles/graphics.dir/build: /home/moos-ivp-douglas/lib/libgraphics.a
.PHONY : src/lib/graphics/CMakeFiles/graphics.dir/build

src/lib/graphics/CMakeFiles/graphics.dir/clean:
	cd /home/moos-ivp-douglas/build/src/lib/graphics && $(CMAKE_COMMAND) -P CMakeFiles/graphics.dir/cmake_clean.cmake
.PHONY : src/lib/graphics/CMakeFiles/graphics.dir/clean

src/lib/graphics/CMakeFiles/graphics.dir/depend:
	cd /home/moos-ivp-douglas/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/moos-ivp-douglas /home/moos-ivp-douglas/src/lib/graphics /home/moos-ivp-douglas/build /home/moos-ivp-douglas/build/src/lib/graphics /home/moos-ivp-douglas/build/src/lib/graphics/CMakeFiles/graphics.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/lib/graphics/CMakeFiles/graphics.dir/depend

