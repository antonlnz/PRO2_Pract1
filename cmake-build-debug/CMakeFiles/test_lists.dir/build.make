# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.21

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

# Produce verbose output by default.
VERBOSE = 1

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.3.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Particular\Downloads\Anton\PRO2\PRO2_Pract1-main

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Particular\Downloads\Anton\PRO2\PRO2_Pract1-main\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/test_lists.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/test_lists.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/test_lists.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_lists.dir/flags.make

CMakeFiles/test_lists.dir/test.c.obj: CMakeFiles/test_lists.dir/flags.make
CMakeFiles/test_lists.dir/test.c.obj: ../test.c
CMakeFiles/test_lists.dir/test.c.obj: CMakeFiles/test_lists.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Particular\Downloads\Anton\PRO2\PRO2_Pract1-main\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/test_lists.dir/test.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/test_lists.dir/test.c.obj -MF CMakeFiles\test_lists.dir\test.c.obj.d -o CMakeFiles\test_lists.dir\test.c.obj -c C:\Users\Particular\Downloads\Anton\PRO2\PRO2_Pract1-main\test.c

CMakeFiles/test_lists.dir/test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_lists.dir/test.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Particular\Downloads\Anton\PRO2\PRO2_Pract1-main\test.c > CMakeFiles\test_lists.dir\test.c.i

CMakeFiles/test_lists.dir/test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_lists.dir/test.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Particular\Downloads\Anton\PRO2\PRO2_Pract1-main\test.c -o CMakeFiles\test_lists.dir\test.c.s

CMakeFiles/test_lists.dir/static_list.c.obj: CMakeFiles/test_lists.dir/flags.make
CMakeFiles/test_lists.dir/static_list.c.obj: ../static_list.c
CMakeFiles/test_lists.dir/static_list.c.obj: CMakeFiles/test_lists.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Particular\Downloads\Anton\PRO2\PRO2_Pract1-main\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/test_lists.dir/static_list.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/test_lists.dir/static_list.c.obj -MF CMakeFiles\test_lists.dir\static_list.c.obj.d -o CMakeFiles\test_lists.dir\static_list.c.obj -c C:\Users\Particular\Downloads\Anton\PRO2\PRO2_Pract1-main\static_list.c

CMakeFiles/test_lists.dir/static_list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_lists.dir/static_list.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Particular\Downloads\Anton\PRO2\PRO2_Pract1-main\static_list.c > CMakeFiles\test_lists.dir\static_list.c.i

CMakeFiles/test_lists.dir/static_list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_lists.dir/static_list.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Particular\Downloads\Anton\PRO2\PRO2_Pract1-main\static_list.c -o CMakeFiles\test_lists.dir\static_list.c.s

# Object files for target test_lists
test_lists_OBJECTS = \
"CMakeFiles/test_lists.dir/test.c.obj" \
"CMakeFiles/test_lists.dir/static_list.c.obj"

# External object files for target test_lists
test_lists_EXTERNAL_OBJECTS =

../bin/test_lists.exe: CMakeFiles/test_lists.dir/test.c.obj
../bin/test_lists.exe: CMakeFiles/test_lists.dir/static_list.c.obj
../bin/test_lists.exe: CMakeFiles/test_lists.dir/build.make
../bin/test_lists.exe: CMakeFiles/test_lists.dir/linklibs.rsp
../bin/test_lists.exe: CMakeFiles/test_lists.dir/objects1.rsp
../bin/test_lists.exe: CMakeFiles/test_lists.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Particular\Downloads\Anton\PRO2\PRO2_Pract1-main\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable ..\bin\test_lists.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\test_lists.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_lists.dir/build: ../bin/test_lists.exe
.PHONY : CMakeFiles/test_lists.dir/build

CMakeFiles/test_lists.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\test_lists.dir\cmake_clean.cmake
.PHONY : CMakeFiles/test_lists.dir/clean

CMakeFiles/test_lists.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Particular\Downloads\Anton\PRO2\PRO2_Pract1-main C:\Users\Particular\Downloads\Anton\PRO2\PRO2_Pract1-main C:\Users\Particular\Downloads\Anton\PRO2\PRO2_Pract1-main\cmake-build-debug C:\Users\Particular\Downloads\Anton\PRO2\PRO2_Pract1-main\cmake-build-debug C:\Users\Particular\Downloads\Anton\PRO2\PRO2_Pract1-main\cmake-build-debug\CMakeFiles\test_lists.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_lists.dir/depend

