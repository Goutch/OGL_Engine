# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\User\Documents\GitHub\OGL_Engine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\User\Documents\GitHub\OGL_Engine\cmake-build-release

# Include any dependencies generated for this target.
include Dependencies/GLM/test/perf/CMakeFiles/test-perf_matrix_inverse.dir/depend.make

# Include the progress variables for this target.
include Dependencies/GLM/test/perf/CMakeFiles/test-perf_matrix_inverse.dir/progress.make

# Include the compile flags for this target's objects.
include Dependencies/GLM/test/perf/CMakeFiles/test-perf_matrix_inverse.dir/flags.make

Dependencies/GLM/test/perf/CMakeFiles/test-perf_matrix_inverse.dir/perf_matrix_inverse.cpp.obj: Dependencies/GLM/test/perf/CMakeFiles/test-perf_matrix_inverse.dir/flags.make
Dependencies/GLM/test/perf/CMakeFiles/test-perf_matrix_inverse.dir/perf_matrix_inverse.cpp.obj: Dependencies/GLM/test/perf/CMakeFiles/test-perf_matrix_inverse.dir/includes_CXX.rsp
Dependencies/GLM/test/perf/CMakeFiles/test-perf_matrix_inverse.dir/perf_matrix_inverse.cpp.obj: ../Dependencies/GLM/test/perf/perf_matrix_inverse.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\User\Documents\GitHub\OGL_Engine\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Dependencies/GLM/test/perf/CMakeFiles/test-perf_matrix_inverse.dir/perf_matrix_inverse.cpp.obj"
	cd /d C:\Users\User\Documents\GitHub\OGL_Engine\cmake-build-release\Dependencies\GLM\test\perf && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\test-perf_matrix_inverse.dir\perf_matrix_inverse.cpp.obj -c C:\Users\User\Documents\GitHub\OGL_Engine\Dependencies\GLM\test\perf\perf_matrix_inverse.cpp

Dependencies/GLM/test/perf/CMakeFiles/test-perf_matrix_inverse.dir/perf_matrix_inverse.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test-perf_matrix_inverse.dir/perf_matrix_inverse.cpp.i"
	cd /d C:\Users\User\Documents\GitHub\OGL_Engine\cmake-build-release\Dependencies\GLM\test\perf && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\User\Documents\GitHub\OGL_Engine\Dependencies\GLM\test\perf\perf_matrix_inverse.cpp > CMakeFiles\test-perf_matrix_inverse.dir\perf_matrix_inverse.cpp.i

Dependencies/GLM/test/perf/CMakeFiles/test-perf_matrix_inverse.dir/perf_matrix_inverse.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test-perf_matrix_inverse.dir/perf_matrix_inverse.cpp.s"
	cd /d C:\Users\User\Documents\GitHub\OGL_Engine\cmake-build-release\Dependencies\GLM\test\perf && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\User\Documents\GitHub\OGL_Engine\Dependencies\GLM\test\perf\perf_matrix_inverse.cpp -o CMakeFiles\test-perf_matrix_inverse.dir\perf_matrix_inverse.cpp.s

# Object files for target test-perf_matrix_inverse
test__perf_matrix_inverse_OBJECTS = \
"CMakeFiles/test-perf_matrix_inverse.dir/perf_matrix_inverse.cpp.obj"

# External object files for target test-perf_matrix_inverse
test__perf_matrix_inverse_EXTERNAL_OBJECTS =

Dependencies/GLM/test/perf/test-perf_matrix_inverse.exe: Dependencies/GLM/test/perf/CMakeFiles/test-perf_matrix_inverse.dir/perf_matrix_inverse.cpp.obj
Dependencies/GLM/test/perf/test-perf_matrix_inverse.exe: Dependencies/GLM/test/perf/CMakeFiles/test-perf_matrix_inverse.dir/build.make
Dependencies/GLM/test/perf/test-perf_matrix_inverse.exe: Dependencies/GLM/test/perf/CMakeFiles/test-perf_matrix_inverse.dir/linklibs.rsp
Dependencies/GLM/test/perf/test-perf_matrix_inverse.exe: Dependencies/GLM/test/perf/CMakeFiles/test-perf_matrix_inverse.dir/objects1.rsp
Dependencies/GLM/test/perf/test-perf_matrix_inverse.exe: Dependencies/GLM/test/perf/CMakeFiles/test-perf_matrix_inverse.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\User\Documents\GitHub\OGL_Engine\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test-perf_matrix_inverse.exe"
	cd /d C:\Users\User\Documents\GitHub\OGL_Engine\cmake-build-release\Dependencies\GLM\test\perf && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\test-perf_matrix_inverse.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Dependencies/GLM/test/perf/CMakeFiles/test-perf_matrix_inverse.dir/build: Dependencies/GLM/test/perf/test-perf_matrix_inverse.exe

.PHONY : Dependencies/GLM/test/perf/CMakeFiles/test-perf_matrix_inverse.dir/build

Dependencies/GLM/test/perf/CMakeFiles/test-perf_matrix_inverse.dir/clean:
	cd /d C:\Users\User\Documents\GitHub\OGL_Engine\cmake-build-release\Dependencies\GLM\test\perf && $(CMAKE_COMMAND) -P CMakeFiles\test-perf_matrix_inverse.dir\cmake_clean.cmake
.PHONY : Dependencies/GLM/test/perf/CMakeFiles/test-perf_matrix_inverse.dir/clean

Dependencies/GLM/test/perf/CMakeFiles/test-perf_matrix_inverse.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\User\Documents\GitHub\OGL_Engine C:\Users\User\Documents\GitHub\OGL_Engine\Dependencies\GLM\test\perf C:\Users\User\Documents\GitHub\OGL_Engine\cmake-build-release C:\Users\User\Documents\GitHub\OGL_Engine\cmake-build-release\Dependencies\GLM\test\perf C:\Users\User\Documents\GitHub\OGL_Engine\cmake-build-release\Dependencies\GLM\test\perf\CMakeFiles\test-perf_matrix_inverse.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : Dependencies/GLM/test/perf/CMakeFiles/test-perf_matrix_inverse.dir/depend

