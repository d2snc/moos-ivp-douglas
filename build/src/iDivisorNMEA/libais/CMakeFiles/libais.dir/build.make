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
include src/iDivisorNMEA/libais/CMakeFiles/libais.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/iDivisorNMEA/libais/CMakeFiles/libais.dir/compiler_depend.make

# Include the progress variables for this target.
include src/iDivisorNMEA/libais/CMakeFiles/libais.dir/progress.make

# Include the compile flags for this target's objects.
include src/iDivisorNMEA/libais/CMakeFiles/libais.dir/flags.make

src/iDivisorNMEA/libais/CMakeFiles/libais.dir/ais.cpp.o: src/iDivisorNMEA/libais/CMakeFiles/libais.dir/flags.make
src/iDivisorNMEA/libais/CMakeFiles/libais.dir/ais.cpp.o: /home/moos-ivp-douglas/src/iDivisorNMEA/libais/ais.cpp
src/iDivisorNMEA/libais/CMakeFiles/libais.dir/ais.cpp.o: src/iDivisorNMEA/libais/CMakeFiles/libais.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/moos-ivp-douglas/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/iDivisorNMEA/libais/CMakeFiles/libais.dir/ais.cpp.o"
	cd /home/moos-ivp-douglas/build/src/iDivisorNMEA/libais && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/iDivisorNMEA/libais/CMakeFiles/libais.dir/ais.cpp.o -MF CMakeFiles/libais.dir/ais.cpp.o.d -o CMakeFiles/libais.dir/ais.cpp.o -c /home/moos-ivp-douglas/src/iDivisorNMEA/libais/ais.cpp

src/iDivisorNMEA/libais/CMakeFiles/libais.dir/ais.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libais.dir/ais.cpp.i"
	cd /home/moos-ivp-douglas/build/src/iDivisorNMEA/libais && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/moos-ivp-douglas/src/iDivisorNMEA/libais/ais.cpp > CMakeFiles/libais.dir/ais.cpp.i

src/iDivisorNMEA/libais/CMakeFiles/libais.dir/ais.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libais.dir/ais.cpp.s"
	cd /home/moos-ivp-douglas/build/src/iDivisorNMEA/libais && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/moos-ivp-douglas/src/iDivisorNMEA/libais/ais.cpp -o CMakeFiles/libais.dir/ais.cpp.s

src/iDivisorNMEA/libais/CMakeFiles/libais.dir/ais_bitset.cpp.o: src/iDivisorNMEA/libais/CMakeFiles/libais.dir/flags.make
src/iDivisorNMEA/libais/CMakeFiles/libais.dir/ais_bitset.cpp.o: /home/moos-ivp-douglas/src/iDivisorNMEA/libais/ais_bitset.cpp
src/iDivisorNMEA/libais/CMakeFiles/libais.dir/ais_bitset.cpp.o: src/iDivisorNMEA/libais/CMakeFiles/libais.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/moos-ivp-douglas/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/iDivisorNMEA/libais/CMakeFiles/libais.dir/ais_bitset.cpp.o"
	cd /home/moos-ivp-douglas/build/src/iDivisorNMEA/libais && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/iDivisorNMEA/libais/CMakeFiles/libais.dir/ais_bitset.cpp.o -MF CMakeFiles/libais.dir/ais_bitset.cpp.o.d -o CMakeFiles/libais.dir/ais_bitset.cpp.o -c /home/moos-ivp-douglas/src/iDivisorNMEA/libais/ais_bitset.cpp

src/iDivisorNMEA/libais/CMakeFiles/libais.dir/ais_bitset.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libais.dir/ais_bitset.cpp.i"
	cd /home/moos-ivp-douglas/build/src/iDivisorNMEA/libais && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/moos-ivp-douglas/src/iDivisorNMEA/libais/ais_bitset.cpp > CMakeFiles/libais.dir/ais_bitset.cpp.i

src/iDivisorNMEA/libais/CMakeFiles/libais.dir/ais_bitset.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libais.dir/ais_bitset.cpp.s"
	cd /home/moos-ivp-douglas/build/src/iDivisorNMEA/libais && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/moos-ivp-douglas/src/iDivisorNMEA/libais/ais_bitset.cpp -o CMakeFiles/libais.dir/ais_bitset.cpp.s

src/iDivisorNMEA/libais/CMakeFiles/libais.dir/ais1_2_3.cpp.o: src/iDivisorNMEA/libais/CMakeFiles/libais.dir/flags.make
src/iDivisorNMEA/libais/CMakeFiles/libais.dir/ais1_2_3.cpp.o: /home/moos-ivp-douglas/src/iDivisorNMEA/libais/ais1_2_3.cpp
src/iDivisorNMEA/libais/CMakeFiles/libais.dir/ais1_2_3.cpp.o: src/iDivisorNMEA/libais/CMakeFiles/libais.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/moos-ivp-douglas/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/iDivisorNMEA/libais/CMakeFiles/libais.dir/ais1_2_3.cpp.o"
	cd /home/moos-ivp-douglas/build/src/iDivisorNMEA/libais && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/iDivisorNMEA/libais/CMakeFiles/libais.dir/ais1_2_3.cpp.o -MF CMakeFiles/libais.dir/ais1_2_3.cpp.o.d -o CMakeFiles/libais.dir/ais1_2_3.cpp.o -c /home/moos-ivp-douglas/src/iDivisorNMEA/libais/ais1_2_3.cpp

src/iDivisorNMEA/libais/CMakeFiles/libais.dir/ais1_2_3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libais.dir/ais1_2_3.cpp.i"
	cd /home/moos-ivp-douglas/build/src/iDivisorNMEA/libais && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/moos-ivp-douglas/src/iDivisorNMEA/libais/ais1_2_3.cpp > CMakeFiles/libais.dir/ais1_2_3.cpp.i

src/iDivisorNMEA/libais/CMakeFiles/libais.dir/ais1_2_3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libais.dir/ais1_2_3.cpp.s"
	cd /home/moos-ivp-douglas/build/src/iDivisorNMEA/libais && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/moos-ivp-douglas/src/iDivisorNMEA/libais/ais1_2_3.cpp -o CMakeFiles/libais.dir/ais1_2_3.cpp.s

# Object files for target libais
libais_OBJECTS = \
"CMakeFiles/libais.dir/ais.cpp.o" \
"CMakeFiles/libais.dir/ais_bitset.cpp.o" \
"CMakeFiles/libais.dir/ais1_2_3.cpp.o"

# External object files for target libais
libais_EXTERNAL_OBJECTS =

/home/moos-ivp-douglas/lib/liblibais.a: src/iDivisorNMEA/libais/CMakeFiles/libais.dir/ais.cpp.o
/home/moos-ivp-douglas/lib/liblibais.a: src/iDivisorNMEA/libais/CMakeFiles/libais.dir/ais_bitset.cpp.o
/home/moos-ivp-douglas/lib/liblibais.a: src/iDivisorNMEA/libais/CMakeFiles/libais.dir/ais1_2_3.cpp.o
/home/moos-ivp-douglas/lib/liblibais.a: src/iDivisorNMEA/libais/CMakeFiles/libais.dir/build.make
/home/moos-ivp-douglas/lib/liblibais.a: src/iDivisorNMEA/libais/CMakeFiles/libais.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/moos-ivp-douglas/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library /home/moos-ivp-douglas/lib/liblibais.a"
	cd /home/moos-ivp-douglas/build/src/iDivisorNMEA/libais && $(CMAKE_COMMAND) -P CMakeFiles/libais.dir/cmake_clean_target.cmake
	cd /home/moos-ivp-douglas/build/src/iDivisorNMEA/libais && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/libais.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/iDivisorNMEA/libais/CMakeFiles/libais.dir/build: /home/moos-ivp-douglas/lib/liblibais.a
.PHONY : src/iDivisorNMEA/libais/CMakeFiles/libais.dir/build

src/iDivisorNMEA/libais/CMakeFiles/libais.dir/clean:
	cd /home/moos-ivp-douglas/build/src/iDivisorNMEA/libais && $(CMAKE_COMMAND) -P CMakeFiles/libais.dir/cmake_clean.cmake
.PHONY : src/iDivisorNMEA/libais/CMakeFiles/libais.dir/clean

src/iDivisorNMEA/libais/CMakeFiles/libais.dir/depend:
	cd /home/moos-ivp-douglas/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/moos-ivp-douglas /home/moos-ivp-douglas/src/iDivisorNMEA/libais /home/moos-ivp-douglas/build /home/moos-ivp-douglas/build/src/iDivisorNMEA/libais /home/moos-ivp-douglas/build/src/iDivisorNMEA/libais/CMakeFiles/libais.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/iDivisorNMEA/libais/CMakeFiles/libais.dir/depend

