# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_SOURCE_DIR = /mnt/o/Desktop/Space_Invaders

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/o/Desktop/Space_Invaders/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/new_target.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/new_target.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/new_target.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/new_target.dir/flags.make

CMakeFiles/new_target.dir/main.c.o: CMakeFiles/new_target.dir/flags.make
CMakeFiles/new_target.dir/main.c.o: /mnt/o/Desktop/Space_Invaders/main.c
CMakeFiles/new_target.dir/main.c.o: CMakeFiles/new_target.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/o/Desktop/Space_Invaders/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/new_target.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/new_target.dir/main.c.o -MF CMakeFiles/new_target.dir/main.c.o.d -o CMakeFiles/new_target.dir/main.c.o -c /mnt/o/Desktop/Space_Invaders/main.c

CMakeFiles/new_target.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/new_target.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/o/Desktop/Space_Invaders/main.c > CMakeFiles/new_target.dir/main.c.i

CMakeFiles/new_target.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/new_target.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/o/Desktop/Space_Invaders/main.c -o CMakeFiles/new_target.dir/main.c.s

# Object files for target new_target
new_target_OBJECTS = \
"CMakeFiles/new_target.dir/main.c.o"

# External object files for target new_target
new_target_EXTERNAL_OBJECTS =

new_target: CMakeFiles/new_target.dir/main.c.o
new_target: CMakeFiles/new_target.dir/build.make
new_target: CMakeFiles/new_target.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/mnt/o/Desktop/Space_Invaders/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable new_target"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/new_target.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/new_target.dir/build: new_target
.PHONY : CMakeFiles/new_target.dir/build

CMakeFiles/new_target.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/new_target.dir/cmake_clean.cmake
.PHONY : CMakeFiles/new_target.dir/clean

CMakeFiles/new_target.dir/depend:
	cd /mnt/o/Desktop/Space_Invaders/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/o/Desktop/Space_Invaders /mnt/o/Desktop/Space_Invaders /mnt/o/Desktop/Space_Invaders/cmake-build-debug /mnt/o/Desktop/Space_Invaders/cmake-build-debug /mnt/o/Desktop/Space_Invaders/cmake-build-debug/CMakeFiles/new_target.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/new_target.dir/depend

