# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /home/denyhs/JetBrains/clion-2017.3.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/denyhs/JetBrains/clion-2017.3.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/denyhs/Documentos/Faculdade/SecondYear/PP/Exerc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/denyhs/Documentos/Faculdade/SecondYear/PP/Exerc/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Exerc.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Exerc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Exerc.dir/flags.make

CMakeFiles/Exerc.dir/main.c.o: CMakeFiles/Exerc.dir/flags.make
CMakeFiles/Exerc.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/denyhs/Documentos/Faculdade/SecondYear/PP/Exerc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Exerc.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Exerc.dir/main.c.o   -c /home/denyhs/Documentos/Faculdade/SecondYear/PP/Exerc/main.c

CMakeFiles/Exerc.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Exerc.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/denyhs/Documentos/Faculdade/SecondYear/PP/Exerc/main.c > CMakeFiles/Exerc.dir/main.c.i

CMakeFiles/Exerc.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Exerc.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/denyhs/Documentos/Faculdade/SecondYear/PP/Exerc/main.c -o CMakeFiles/Exerc.dir/main.c.s

CMakeFiles/Exerc.dir/main.c.o.requires:

.PHONY : CMakeFiles/Exerc.dir/main.c.o.requires

CMakeFiles/Exerc.dir/main.c.o.provides: CMakeFiles/Exerc.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/Exerc.dir/build.make CMakeFiles/Exerc.dir/main.c.o.provides.build
.PHONY : CMakeFiles/Exerc.dir/main.c.o.provides

CMakeFiles/Exerc.dir/main.c.o.provides.build: CMakeFiles/Exerc.dir/main.c.o


# Object files for target Exerc
Exerc_OBJECTS = \
"CMakeFiles/Exerc.dir/main.c.o"

# External object files for target Exerc
Exerc_EXTERNAL_OBJECTS =

Exerc: CMakeFiles/Exerc.dir/main.c.o
Exerc: CMakeFiles/Exerc.dir/build.make
Exerc: CMakeFiles/Exerc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/denyhs/Documentos/Faculdade/SecondYear/PP/Exerc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Exerc"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Exerc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Exerc.dir/build: Exerc

.PHONY : CMakeFiles/Exerc.dir/build

CMakeFiles/Exerc.dir/requires: CMakeFiles/Exerc.dir/main.c.o.requires

.PHONY : CMakeFiles/Exerc.dir/requires

CMakeFiles/Exerc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Exerc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Exerc.dir/clean

CMakeFiles/Exerc.dir/depend:
	cd /home/denyhs/Documentos/Faculdade/SecondYear/PP/Exerc/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/denyhs/Documentos/Faculdade/SecondYear/PP/Exerc /home/denyhs/Documentos/Faculdade/SecondYear/PP/Exerc /home/denyhs/Documentos/Faculdade/SecondYear/PP/Exerc/cmake-build-debug /home/denyhs/Documentos/Faculdade/SecondYear/PP/Exerc/cmake-build-debug /home/denyhs/Documentos/Faculdade/SecondYear/PP/Exerc/cmake-build-debug/CMakeFiles/Exerc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Exerc.dir/depend

