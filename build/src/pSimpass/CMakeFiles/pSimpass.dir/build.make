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
include src/pSimpass/CMakeFiles/pSimpass.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/pSimpass/CMakeFiles/pSimpass.dir/compiler_depend.make

# Include the progress variables for this target.
include src/pSimpass/CMakeFiles/pSimpass.dir/progress.make

# Include the compile flags for this target's objects.
include src/pSimpass/CMakeFiles/pSimpass.dir/flags.make

src/pSimpass/CMakeFiles/pSimpass.dir/pSimpass_autogen/mocs_compilation.cpp.o: src/pSimpass/CMakeFiles/pSimpass.dir/flags.make
src/pSimpass/CMakeFiles/pSimpass.dir/pSimpass_autogen/mocs_compilation.cpp.o: src/pSimpass/pSimpass_autogen/mocs_compilation.cpp
src/pSimpass/CMakeFiles/pSimpass.dir/pSimpass_autogen/mocs_compilation.cpp.o: src/pSimpass/CMakeFiles/pSimpass.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/moos-ivp-douglas/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/pSimpass/CMakeFiles/pSimpass.dir/pSimpass_autogen/mocs_compilation.cpp.o"
	cd /home/moos-ivp-douglas/build/src/pSimpass && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/pSimpass/CMakeFiles/pSimpass.dir/pSimpass_autogen/mocs_compilation.cpp.o -MF CMakeFiles/pSimpass.dir/pSimpass_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/pSimpass.dir/pSimpass_autogen/mocs_compilation.cpp.o -c /home/moos-ivp-douglas/build/src/pSimpass/pSimpass_autogen/mocs_compilation.cpp

src/pSimpass/CMakeFiles/pSimpass.dir/pSimpass_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pSimpass.dir/pSimpass_autogen/mocs_compilation.cpp.i"
	cd /home/moos-ivp-douglas/build/src/pSimpass && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/moos-ivp-douglas/build/src/pSimpass/pSimpass_autogen/mocs_compilation.cpp > CMakeFiles/pSimpass.dir/pSimpass_autogen/mocs_compilation.cpp.i

src/pSimpass/CMakeFiles/pSimpass.dir/pSimpass_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pSimpass.dir/pSimpass_autogen/mocs_compilation.cpp.s"
	cd /home/moos-ivp-douglas/build/src/pSimpass && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/moos-ivp-douglas/build/src/pSimpass/pSimpass_autogen/mocs_compilation.cpp -o CMakeFiles/pSimpass.dir/pSimpass_autogen/mocs_compilation.cpp.s

src/pSimpass/CMakeFiles/pSimpass.dir/Console.cpp.o: src/pSimpass/CMakeFiles/pSimpass.dir/flags.make
src/pSimpass/CMakeFiles/pSimpass.dir/Console.cpp.o: /home/moos-ivp-douglas/src/pSimpass/Console.cpp
src/pSimpass/CMakeFiles/pSimpass.dir/Console.cpp.o: src/pSimpass/CMakeFiles/pSimpass.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/moos-ivp-douglas/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/pSimpass/CMakeFiles/pSimpass.dir/Console.cpp.o"
	cd /home/moos-ivp-douglas/build/src/pSimpass && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/pSimpass/CMakeFiles/pSimpass.dir/Console.cpp.o -MF CMakeFiles/pSimpass.dir/Console.cpp.o.d -o CMakeFiles/pSimpass.dir/Console.cpp.o -c /home/moos-ivp-douglas/src/pSimpass/Console.cpp

src/pSimpass/CMakeFiles/pSimpass.dir/Console.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pSimpass.dir/Console.cpp.i"
	cd /home/moos-ivp-douglas/build/src/pSimpass && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/moos-ivp-douglas/src/pSimpass/Console.cpp > CMakeFiles/pSimpass.dir/Console.cpp.i

src/pSimpass/CMakeFiles/pSimpass.dir/Console.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pSimpass.dir/Console.cpp.s"
	cd /home/moos-ivp-douglas/build/src/pSimpass && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/moos-ivp-douglas/src/pSimpass/Console.cpp -o CMakeFiles/pSimpass.dir/Console.cpp.s

src/pSimpass/CMakeFiles/pSimpass.dir/SIMPASS.cpp.o: src/pSimpass/CMakeFiles/pSimpass.dir/flags.make
src/pSimpass/CMakeFiles/pSimpass.dir/SIMPASS.cpp.o: /home/moos-ivp-douglas/src/pSimpass/SIMPASS.cpp
src/pSimpass/CMakeFiles/pSimpass.dir/SIMPASS.cpp.o: src/pSimpass/CMakeFiles/pSimpass.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/moos-ivp-douglas/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/pSimpass/CMakeFiles/pSimpass.dir/SIMPASS.cpp.o"
	cd /home/moos-ivp-douglas/build/src/pSimpass && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/pSimpass/CMakeFiles/pSimpass.dir/SIMPASS.cpp.o -MF CMakeFiles/pSimpass.dir/SIMPASS.cpp.o.d -o CMakeFiles/pSimpass.dir/SIMPASS.cpp.o -c /home/moos-ivp-douglas/src/pSimpass/SIMPASS.cpp

src/pSimpass/CMakeFiles/pSimpass.dir/SIMPASS.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pSimpass.dir/SIMPASS.cpp.i"
	cd /home/moos-ivp-douglas/build/src/pSimpass && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/moos-ivp-douglas/src/pSimpass/SIMPASS.cpp > CMakeFiles/pSimpass.dir/SIMPASS.cpp.i

src/pSimpass/CMakeFiles/pSimpass.dir/SIMPASS.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pSimpass.dir/SIMPASS.cpp.s"
	cd /home/moos-ivp-douglas/build/src/pSimpass && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/moos-ivp-douglas/src/pSimpass/SIMPASS.cpp -o CMakeFiles/pSimpass.dir/SIMPASS.cpp.s

src/pSimpass/CMakeFiles/pSimpass.dir/LatLong.cpp.o: src/pSimpass/CMakeFiles/pSimpass.dir/flags.make
src/pSimpass/CMakeFiles/pSimpass.dir/LatLong.cpp.o: /home/moos-ivp-douglas/src/pSimpass/LatLong.cpp
src/pSimpass/CMakeFiles/pSimpass.dir/LatLong.cpp.o: src/pSimpass/CMakeFiles/pSimpass.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/moos-ivp-douglas/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/pSimpass/CMakeFiles/pSimpass.dir/LatLong.cpp.o"
	cd /home/moos-ivp-douglas/build/src/pSimpass && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/pSimpass/CMakeFiles/pSimpass.dir/LatLong.cpp.o -MF CMakeFiles/pSimpass.dir/LatLong.cpp.o.d -o CMakeFiles/pSimpass.dir/LatLong.cpp.o -c /home/moos-ivp-douglas/src/pSimpass/LatLong.cpp

src/pSimpass/CMakeFiles/pSimpass.dir/LatLong.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pSimpass.dir/LatLong.cpp.i"
	cd /home/moos-ivp-douglas/build/src/pSimpass && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/moos-ivp-douglas/src/pSimpass/LatLong.cpp > CMakeFiles/pSimpass.dir/LatLong.cpp.i

src/pSimpass/CMakeFiles/pSimpass.dir/LatLong.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pSimpass.dir/LatLong.cpp.s"
	cd /home/moos-ivp-douglas/build/src/pSimpass && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/moos-ivp-douglas/src/pSimpass/LatLong.cpp -o CMakeFiles/pSimpass.dir/LatLong.cpp.s

src/pSimpass/CMakeFiles/pSimpass.dir/main.cpp.o: src/pSimpass/CMakeFiles/pSimpass.dir/flags.make
src/pSimpass/CMakeFiles/pSimpass.dir/main.cpp.o: /home/moos-ivp-douglas/src/pSimpass/main.cpp
src/pSimpass/CMakeFiles/pSimpass.dir/main.cpp.o: src/pSimpass/CMakeFiles/pSimpass.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/moos-ivp-douglas/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/pSimpass/CMakeFiles/pSimpass.dir/main.cpp.o"
	cd /home/moos-ivp-douglas/build/src/pSimpass && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/pSimpass/CMakeFiles/pSimpass.dir/main.cpp.o -MF CMakeFiles/pSimpass.dir/main.cpp.o.d -o CMakeFiles/pSimpass.dir/main.cpp.o -c /home/moos-ivp-douglas/src/pSimpass/main.cpp

src/pSimpass/CMakeFiles/pSimpass.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pSimpass.dir/main.cpp.i"
	cd /home/moos-ivp-douglas/build/src/pSimpass && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/moos-ivp-douglas/src/pSimpass/main.cpp > CMakeFiles/pSimpass.dir/main.cpp.i

src/pSimpass/CMakeFiles/pSimpass.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pSimpass.dir/main.cpp.s"
	cd /home/moos-ivp-douglas/build/src/pSimpass && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/moos-ivp-douglas/src/pSimpass/main.cpp -o CMakeFiles/pSimpass.dir/main.cpp.s

src/pSimpass/CMakeFiles/pSimpass.dir/MathUtils.cpp.o: src/pSimpass/CMakeFiles/pSimpass.dir/flags.make
src/pSimpass/CMakeFiles/pSimpass.dir/MathUtils.cpp.o: /home/moos-ivp-douglas/src/pSimpass/MathUtils.cpp
src/pSimpass/CMakeFiles/pSimpass.dir/MathUtils.cpp.o: src/pSimpass/CMakeFiles/pSimpass.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/moos-ivp-douglas/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/pSimpass/CMakeFiles/pSimpass.dir/MathUtils.cpp.o"
	cd /home/moos-ivp-douglas/build/src/pSimpass && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/pSimpass/CMakeFiles/pSimpass.dir/MathUtils.cpp.o -MF CMakeFiles/pSimpass.dir/MathUtils.cpp.o.d -o CMakeFiles/pSimpass.dir/MathUtils.cpp.o -c /home/moos-ivp-douglas/src/pSimpass/MathUtils.cpp

src/pSimpass/CMakeFiles/pSimpass.dir/MathUtils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pSimpass.dir/MathUtils.cpp.i"
	cd /home/moos-ivp-douglas/build/src/pSimpass && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/moos-ivp-douglas/src/pSimpass/MathUtils.cpp > CMakeFiles/pSimpass.dir/MathUtils.cpp.i

src/pSimpass/CMakeFiles/pSimpass.dir/MathUtils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pSimpass.dir/MathUtils.cpp.s"
	cd /home/moos-ivp-douglas/build/src/pSimpass && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/moos-ivp-douglas/src/pSimpass/MathUtils.cpp -o CMakeFiles/pSimpass.dir/MathUtils.cpp.s

src/pSimpass/CMakeFiles/pSimpass.dir/moosconnect.cpp.o: src/pSimpass/CMakeFiles/pSimpass.dir/flags.make
src/pSimpass/CMakeFiles/pSimpass.dir/moosconnect.cpp.o: /home/moos-ivp-douglas/src/pSimpass/moosconnect.cpp
src/pSimpass/CMakeFiles/pSimpass.dir/moosconnect.cpp.o: src/pSimpass/CMakeFiles/pSimpass.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/moos-ivp-douglas/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/pSimpass/CMakeFiles/pSimpass.dir/moosconnect.cpp.o"
	cd /home/moos-ivp-douglas/build/src/pSimpass && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/pSimpass/CMakeFiles/pSimpass.dir/moosconnect.cpp.o -MF CMakeFiles/pSimpass.dir/moosconnect.cpp.o.d -o CMakeFiles/pSimpass.dir/moosconnect.cpp.o -c /home/moos-ivp-douglas/src/pSimpass/moosconnect.cpp

src/pSimpass/CMakeFiles/pSimpass.dir/moosconnect.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pSimpass.dir/moosconnect.cpp.i"
	cd /home/moos-ivp-douglas/build/src/pSimpass && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/moos-ivp-douglas/src/pSimpass/moosconnect.cpp > CMakeFiles/pSimpass.dir/moosconnect.cpp.i

src/pSimpass/CMakeFiles/pSimpass.dir/moosconnect.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pSimpass.dir/moosconnect.cpp.s"
	cd /home/moos-ivp-douglas/build/src/pSimpass && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/moos-ivp-douglas/src/pSimpass/moosconnect.cpp -o CMakeFiles/pSimpass.dir/moosconnect.cpp.s

src/pSimpass/CMakeFiles/pSimpass.dir/NetworkClient.cpp.o: src/pSimpass/CMakeFiles/pSimpass.dir/flags.make
src/pSimpass/CMakeFiles/pSimpass.dir/NetworkClient.cpp.o: /home/moos-ivp-douglas/src/pSimpass/NetworkClient.cpp
src/pSimpass/CMakeFiles/pSimpass.dir/NetworkClient.cpp.o: src/pSimpass/CMakeFiles/pSimpass.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/moos-ivp-douglas/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object src/pSimpass/CMakeFiles/pSimpass.dir/NetworkClient.cpp.o"
	cd /home/moos-ivp-douglas/build/src/pSimpass && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/pSimpass/CMakeFiles/pSimpass.dir/NetworkClient.cpp.o -MF CMakeFiles/pSimpass.dir/NetworkClient.cpp.o.d -o CMakeFiles/pSimpass.dir/NetworkClient.cpp.o -c /home/moos-ivp-douglas/src/pSimpass/NetworkClient.cpp

src/pSimpass/CMakeFiles/pSimpass.dir/NetworkClient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pSimpass.dir/NetworkClient.cpp.i"
	cd /home/moos-ivp-douglas/build/src/pSimpass && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/moos-ivp-douglas/src/pSimpass/NetworkClient.cpp > CMakeFiles/pSimpass.dir/NetworkClient.cpp.i

src/pSimpass/CMakeFiles/pSimpass.dir/NetworkClient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pSimpass.dir/NetworkClient.cpp.s"
	cd /home/moos-ivp-douglas/build/src/pSimpass && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/moos-ivp-douglas/src/pSimpass/NetworkClient.cpp -o CMakeFiles/pSimpass.dir/NetworkClient.cpp.s

src/pSimpass/CMakeFiles/pSimpass.dir/NetworkManager.cpp.o: src/pSimpass/CMakeFiles/pSimpass.dir/flags.make
src/pSimpass/CMakeFiles/pSimpass.dir/NetworkManager.cpp.o: /home/moos-ivp-douglas/src/pSimpass/NetworkManager.cpp
src/pSimpass/CMakeFiles/pSimpass.dir/NetworkManager.cpp.o: src/pSimpass/CMakeFiles/pSimpass.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/moos-ivp-douglas/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object src/pSimpass/CMakeFiles/pSimpass.dir/NetworkManager.cpp.o"
	cd /home/moos-ivp-douglas/build/src/pSimpass && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/pSimpass/CMakeFiles/pSimpass.dir/NetworkManager.cpp.o -MF CMakeFiles/pSimpass.dir/NetworkManager.cpp.o.d -o CMakeFiles/pSimpass.dir/NetworkManager.cpp.o -c /home/moos-ivp-douglas/src/pSimpass/NetworkManager.cpp

src/pSimpass/CMakeFiles/pSimpass.dir/NetworkManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pSimpass.dir/NetworkManager.cpp.i"
	cd /home/moos-ivp-douglas/build/src/pSimpass && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/moos-ivp-douglas/src/pSimpass/NetworkManager.cpp > CMakeFiles/pSimpass.dir/NetworkManager.cpp.i

src/pSimpass/CMakeFiles/pSimpass.dir/NetworkManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pSimpass.dir/NetworkManager.cpp.s"
	cd /home/moos-ivp-douglas/build/src/pSimpass && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/moos-ivp-douglas/src/pSimpass/NetworkManager.cpp -o CMakeFiles/pSimpass.dir/NetworkManager.cpp.s

# Object files for target pSimpass
pSimpass_OBJECTS = \
"CMakeFiles/pSimpass.dir/pSimpass_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/pSimpass.dir/Console.cpp.o" \
"CMakeFiles/pSimpass.dir/SIMPASS.cpp.o" \
"CMakeFiles/pSimpass.dir/LatLong.cpp.o" \
"CMakeFiles/pSimpass.dir/main.cpp.o" \
"CMakeFiles/pSimpass.dir/MathUtils.cpp.o" \
"CMakeFiles/pSimpass.dir/moosconnect.cpp.o" \
"CMakeFiles/pSimpass.dir/NetworkClient.cpp.o" \
"CMakeFiles/pSimpass.dir/NetworkManager.cpp.o"

# External object files for target pSimpass
pSimpass_EXTERNAL_OBJECTS =

/home/moos-ivp-douglas/bin/pSimpass: src/pSimpass/CMakeFiles/pSimpass.dir/pSimpass_autogen/mocs_compilation.cpp.o
/home/moos-ivp-douglas/bin/pSimpass: src/pSimpass/CMakeFiles/pSimpass.dir/Console.cpp.o
/home/moos-ivp-douglas/bin/pSimpass: src/pSimpass/CMakeFiles/pSimpass.dir/SIMPASS.cpp.o
/home/moos-ivp-douglas/bin/pSimpass: src/pSimpass/CMakeFiles/pSimpass.dir/LatLong.cpp.o
/home/moos-ivp-douglas/bin/pSimpass: src/pSimpass/CMakeFiles/pSimpass.dir/main.cpp.o
/home/moos-ivp-douglas/bin/pSimpass: src/pSimpass/CMakeFiles/pSimpass.dir/MathUtils.cpp.o
/home/moos-ivp-douglas/bin/pSimpass: src/pSimpass/CMakeFiles/pSimpass.dir/moosconnect.cpp.o
/home/moos-ivp-douglas/bin/pSimpass: src/pSimpass/CMakeFiles/pSimpass.dir/NetworkClient.cpp.o
/home/moos-ivp-douglas/bin/pSimpass: src/pSimpass/CMakeFiles/pSimpass.dir/NetworkManager.cpp.o
/home/moos-ivp-douglas/bin/pSimpass: src/pSimpass/CMakeFiles/pSimpass.dir/build.make
/home/moos-ivp-douglas/bin/pSimpass: /home/moos-ivp/build/MOOS/MOOSCore/lib/libMOOS.a
/home/moos-ivp-douglas/bin/pSimpass: /usr/lib/x86_64-linux-gnu/libQt5Network.so.5.12.8
/home/moos-ivp-douglas/bin/pSimpass: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.12.8
/home/moos-ivp-douglas/bin/pSimpass: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.12.8
/home/moos-ivp-douglas/bin/pSimpass: src/pSimpass/CMakeFiles/pSimpass.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/moos-ivp-douglas/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable /home/moos-ivp-douglas/bin/pSimpass"
	cd /home/moos-ivp-douglas/build/src/pSimpass && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pSimpass.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/pSimpass/CMakeFiles/pSimpass.dir/build: /home/moos-ivp-douglas/bin/pSimpass
.PHONY : src/pSimpass/CMakeFiles/pSimpass.dir/build

src/pSimpass/CMakeFiles/pSimpass.dir/clean:
	cd /home/moos-ivp-douglas/build/src/pSimpass && $(CMAKE_COMMAND) -P CMakeFiles/pSimpass.dir/cmake_clean.cmake
.PHONY : src/pSimpass/CMakeFiles/pSimpass.dir/clean

src/pSimpass/CMakeFiles/pSimpass.dir/depend:
	cd /home/moos-ivp-douglas/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/moos-ivp-douglas /home/moos-ivp-douglas/src/pSimpass /home/moos-ivp-douglas/build /home/moos-ivp-douglas/build/src/pSimpass /home/moos-ivp-douglas/build/src/pSimpass/CMakeFiles/pSimpass.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/pSimpass/CMakeFiles/pSimpass.dir/depend
