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
include CMakeFiles/mi_proyecto.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/mi_proyecto.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/mi_proyecto.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mi_proyecto.dir/flags.make

CMakeFiles/mi_proyecto.dir/main.c.o: CMakeFiles/mi_proyecto.dir/flags.make
CMakeFiles/mi_proyecto.dir/main.c.o: /mnt/o/Desktop/Space_Invaders/main.c
CMakeFiles/mi_proyecto.dir/main.c.o: CMakeFiles/mi_proyecto.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/o/Desktop/Space_Invaders/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/mi_proyecto.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/mi_proyecto.dir/main.c.o -MF CMakeFiles/mi_proyecto.dir/main.c.o.d -o CMakeFiles/mi_proyecto.dir/main.c.o -c /mnt/o/Desktop/Space_Invaders/main.c

CMakeFiles/mi_proyecto.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/mi_proyecto.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/o/Desktop/Space_Invaders/main.c > CMakeFiles/mi_proyecto.dir/main.c.i

CMakeFiles/mi_proyecto.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/mi_proyecto.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/o/Desktop/Space_Invaders/main.c -o CMakeFiles/mi_proyecto.dir/main.c.s

CMakeFiles/mi_proyecto.dir/print_frame.c.o: CMakeFiles/mi_proyecto.dir/flags.make
CMakeFiles/mi_proyecto.dir/print_frame.c.o: /mnt/o/Desktop/Space_Invaders/print_frame.c
CMakeFiles/mi_proyecto.dir/print_frame.c.o: CMakeFiles/mi_proyecto.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/o/Desktop/Space_Invaders/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/mi_proyecto.dir/print_frame.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/mi_proyecto.dir/print_frame.c.o -MF CMakeFiles/mi_proyecto.dir/print_frame.c.o.d -o CMakeFiles/mi_proyecto.dir/print_frame.c.o -c /mnt/o/Desktop/Space_Invaders/print_frame.c

CMakeFiles/mi_proyecto.dir/print_frame.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/mi_proyecto.dir/print_frame.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/o/Desktop/Space_Invaders/print_frame.c > CMakeFiles/mi_proyecto.dir/print_frame.c.i

CMakeFiles/mi_proyecto.dir/print_frame.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/mi_proyecto.dir/print_frame.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/o/Desktop/Space_Invaders/print_frame.c -o CMakeFiles/mi_proyecto.dir/print_frame.c.s

CMakeFiles/mi_proyecto.dir/objects.c.o: CMakeFiles/mi_proyecto.dir/flags.make
CMakeFiles/mi_proyecto.dir/objects.c.o: /mnt/o/Desktop/Space_Invaders/objects.c
CMakeFiles/mi_proyecto.dir/objects.c.o: CMakeFiles/mi_proyecto.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/o/Desktop/Space_Invaders/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/mi_proyecto.dir/objects.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/mi_proyecto.dir/objects.c.o -MF CMakeFiles/mi_proyecto.dir/objects.c.o.d -o CMakeFiles/mi_proyecto.dir/objects.c.o -c /mnt/o/Desktop/Space_Invaders/objects.c

CMakeFiles/mi_proyecto.dir/objects.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/mi_proyecto.dir/objects.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/o/Desktop/Space_Invaders/objects.c > CMakeFiles/mi_proyecto.dir/objects.c.i

CMakeFiles/mi_proyecto.dir/objects.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/mi_proyecto.dir/objects.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/o/Desktop/Space_Invaders/objects.c -o CMakeFiles/mi_proyecto.dir/objects.c.s

CMakeFiles/mi_proyecto.dir/ship.c.o: CMakeFiles/mi_proyecto.dir/flags.make
CMakeFiles/mi_proyecto.dir/ship.c.o: /mnt/o/Desktop/Space_Invaders/ship.c
CMakeFiles/mi_proyecto.dir/ship.c.o: CMakeFiles/mi_proyecto.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/o/Desktop/Space_Invaders/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/mi_proyecto.dir/ship.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/mi_proyecto.dir/ship.c.o -MF CMakeFiles/mi_proyecto.dir/ship.c.o.d -o CMakeFiles/mi_proyecto.dir/ship.c.o -c /mnt/o/Desktop/Space_Invaders/ship.c

CMakeFiles/mi_proyecto.dir/ship.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/mi_proyecto.dir/ship.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/o/Desktop/Space_Invaders/ship.c > CMakeFiles/mi_proyecto.dir/ship.c.i

CMakeFiles/mi_proyecto.dir/ship.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/mi_proyecto.dir/ship.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/o/Desktop/Space_Invaders/ship.c -o CMakeFiles/mi_proyecto.dir/ship.c.s

# Object files for target mi_proyecto
mi_proyecto_OBJECTS = \
"CMakeFiles/mi_proyecto.dir/main.c.o" \
"CMakeFiles/mi_proyecto.dir/print_frame.c.o" \
"CMakeFiles/mi_proyecto.dir/objects.c.o" \
"CMakeFiles/mi_proyecto.dir/ship.c.o"

# External object files for target mi_proyecto
mi_proyecto_EXTERNAL_OBJECTS =

mi_proyecto: CMakeFiles/mi_proyecto.dir/main.c.o
mi_proyecto: CMakeFiles/mi_proyecto.dir/print_frame.c.o
mi_proyecto: CMakeFiles/mi_proyecto.dir/objects.c.o
mi_proyecto: CMakeFiles/mi_proyecto.dir/ship.c.o
mi_proyecto: CMakeFiles/mi_proyecto.dir/build.make
mi_proyecto: /usr/lib/x86_64-linux-gnu/libcurses.so
mi_proyecto: /usr/lib/x86_64-linux-gnu/libform.so
mi_proyecto: CMakeFiles/mi_proyecto.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/mnt/o/Desktop/Space_Invaders/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable mi_proyecto"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mi_proyecto.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mi_proyecto.dir/build: mi_proyecto
.PHONY : CMakeFiles/mi_proyecto.dir/build

CMakeFiles/mi_proyecto.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mi_proyecto.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mi_proyecto.dir/clean

CMakeFiles/mi_proyecto.dir/depend:
	cd /mnt/o/Desktop/Space_Invaders/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/o/Desktop/Space_Invaders /mnt/o/Desktop/Space_Invaders /mnt/o/Desktop/Space_Invaders/cmake-build-debug /mnt/o/Desktop/Space_Invaders/cmake-build-debug /mnt/o/Desktop/Space_Invaders/cmake-build-debug/CMakeFiles/mi_proyecto.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/mi_proyecto.dir/depend

