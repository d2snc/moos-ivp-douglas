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

# Utility rule file for pSimpass_autogen.

# Include any custom commands dependencies for this target.
include src/pSimpass/CMakeFiles/pSimpass_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include src/pSimpass/CMakeFiles/pSimpass_autogen.dir/progress.make

src/pSimpass/CMakeFiles/pSimpass_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/moos-ivp-douglas/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target pSimpass"
	cd /home/moos-ivp-douglas/build/src/pSimpass && /home/douglas/.local/lib/python3.10/site-packages/cmake/data/bin/cmake -E cmake_autogen /home/moos-ivp-douglas/build/src/pSimpass/CMakeFiles/pSimpass_autogen.dir/AutogenInfo.json None

pSimpass_autogen: src/pSimpass/CMakeFiles/pSimpass_autogen
pSimpass_autogen: src/pSimpass/CMakeFiles/pSimpass_autogen.dir/build.make
.PHONY : pSimpass_autogen

# Rule to build all files generated by this target.
src/pSimpass/CMakeFiles/pSimpass_autogen.dir/build: pSimpass_autogen
.PHONY : src/pSimpass/CMakeFiles/pSimpass_autogen.dir/build

src/pSimpass/CMakeFiles/pSimpass_autogen.dir/clean:
	cd /home/moos-ivp-douglas/build/src/pSimpass && $(CMAKE_COMMAND) -P CMakeFiles/pSimpass_autogen.dir/cmake_clean.cmake
.PHONY : src/pSimpass/CMakeFiles/pSimpass_autogen.dir/clean

src/pSimpass/CMakeFiles/pSimpass_autogen.dir/depend:
	cd /home/moos-ivp-douglas/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/moos-ivp-douglas /home/moos-ivp-douglas/src/pSimpass /home/moos-ivp-douglas/build /home/moos-ivp-douglas/build/src/pSimpass /home/moos-ivp-douglas/build/src/pSimpass/CMakeFiles/pSimpass_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/pSimpass/CMakeFiles/pSimpass_autogen.dir/depend
