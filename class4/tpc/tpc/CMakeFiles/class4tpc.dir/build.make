# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_COMMAND = /home/jncfa/.local/lib/python3.8/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /home/jncfa/.local/lib/python3.8/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jncfa/idp_exercices/class4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jncfa/idp_exercices/class4/tpc

# Include any dependencies generated for this target.
include tpc/CMakeFiles/class4tpc.dir/depend.make

# Include the progress variables for this target.
include tpc/CMakeFiles/class4tpc.dir/progress.make

# Include the compile flags for this target's objects.
include tpc/CMakeFiles/class4tpc.dir/flags.make

tpc/CMakeFiles/class4tpc.dir/class4tpc.cc.o: tpc/CMakeFiles/class4tpc.dir/flags.make
tpc/CMakeFiles/class4tpc.dir/class4tpc.cc.o: class4tpc.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jncfa/idp_exercices/class4/tpc/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tpc/CMakeFiles/class4tpc.dir/class4tpc.cc.o"
	cd /home/jncfa/idp_exercices/class4/tpc/tpc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/class4tpc.dir/class4tpc.cc.o -c /home/jncfa/idp_exercices/class4/tpc/class4tpc.cc

tpc/CMakeFiles/class4tpc.dir/class4tpc.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/class4tpc.dir/class4tpc.cc.i"
	cd /home/jncfa/idp_exercices/class4/tpc/tpc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jncfa/idp_exercices/class4/tpc/class4tpc.cc > CMakeFiles/class4tpc.dir/class4tpc.cc.i

tpc/CMakeFiles/class4tpc.dir/class4tpc.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/class4tpc.dir/class4tpc.cc.s"
	cd /home/jncfa/idp_exercices/class4/tpc/tpc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jncfa/idp_exercices/class4/tpc/class4tpc.cc -o CMakeFiles/class4tpc.dir/class4tpc.cc.s

tpc/CMakeFiles/class4tpc.dir/src/DetectorConstruction.cc.o: tpc/CMakeFiles/class4tpc.dir/flags.make
tpc/CMakeFiles/class4tpc.dir/src/DetectorConstruction.cc.o: src/DetectorConstruction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jncfa/idp_exercices/class4/tpc/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tpc/CMakeFiles/class4tpc.dir/src/DetectorConstruction.cc.o"
	cd /home/jncfa/idp_exercices/class4/tpc/tpc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/class4tpc.dir/src/DetectorConstruction.cc.o -c /home/jncfa/idp_exercices/class4/tpc/src/DetectorConstruction.cc

tpc/CMakeFiles/class4tpc.dir/src/DetectorConstruction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/class4tpc.dir/src/DetectorConstruction.cc.i"
	cd /home/jncfa/idp_exercices/class4/tpc/tpc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jncfa/idp_exercices/class4/tpc/src/DetectorConstruction.cc > CMakeFiles/class4tpc.dir/src/DetectorConstruction.cc.i

tpc/CMakeFiles/class4tpc.dir/src/DetectorConstruction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/class4tpc.dir/src/DetectorConstruction.cc.s"
	cd /home/jncfa/idp_exercices/class4/tpc/tpc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jncfa/idp_exercices/class4/tpc/src/DetectorConstruction.cc -o CMakeFiles/class4tpc.dir/src/DetectorConstruction.cc.s

tpc/CMakeFiles/class4tpc.dir/src/PrimaryGeneratorAction.cc.o: tpc/CMakeFiles/class4tpc.dir/flags.make
tpc/CMakeFiles/class4tpc.dir/src/PrimaryGeneratorAction.cc.o: src/PrimaryGeneratorAction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jncfa/idp_exercices/class4/tpc/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object tpc/CMakeFiles/class4tpc.dir/src/PrimaryGeneratorAction.cc.o"
	cd /home/jncfa/idp_exercices/class4/tpc/tpc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/class4tpc.dir/src/PrimaryGeneratorAction.cc.o -c /home/jncfa/idp_exercices/class4/tpc/src/PrimaryGeneratorAction.cc

tpc/CMakeFiles/class4tpc.dir/src/PrimaryGeneratorAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/class4tpc.dir/src/PrimaryGeneratorAction.cc.i"
	cd /home/jncfa/idp_exercices/class4/tpc/tpc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jncfa/idp_exercices/class4/tpc/src/PrimaryGeneratorAction.cc > CMakeFiles/class4tpc.dir/src/PrimaryGeneratorAction.cc.i

tpc/CMakeFiles/class4tpc.dir/src/PrimaryGeneratorAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/class4tpc.dir/src/PrimaryGeneratorAction.cc.s"
	cd /home/jncfa/idp_exercices/class4/tpc/tpc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jncfa/idp_exercices/class4/tpc/src/PrimaryGeneratorAction.cc -o CMakeFiles/class4tpc.dir/src/PrimaryGeneratorAction.cc.s

tpc/CMakeFiles/class4tpc.dir/src/SteppingAction.cc.o: tpc/CMakeFiles/class4tpc.dir/flags.make
tpc/CMakeFiles/class4tpc.dir/src/SteppingAction.cc.o: src/SteppingAction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jncfa/idp_exercices/class4/tpc/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object tpc/CMakeFiles/class4tpc.dir/src/SteppingAction.cc.o"
	cd /home/jncfa/idp_exercices/class4/tpc/tpc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/class4tpc.dir/src/SteppingAction.cc.o -c /home/jncfa/idp_exercices/class4/tpc/src/SteppingAction.cc

tpc/CMakeFiles/class4tpc.dir/src/SteppingAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/class4tpc.dir/src/SteppingAction.cc.i"
	cd /home/jncfa/idp_exercices/class4/tpc/tpc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jncfa/idp_exercices/class4/tpc/src/SteppingAction.cc > CMakeFiles/class4tpc.dir/src/SteppingAction.cc.i

tpc/CMakeFiles/class4tpc.dir/src/SteppingAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/class4tpc.dir/src/SteppingAction.cc.s"
	cd /home/jncfa/idp_exercices/class4/tpc/tpc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jncfa/idp_exercices/class4/tpc/src/SteppingAction.cc -o CMakeFiles/class4tpc.dir/src/SteppingAction.cc.s

# Object files for target class4tpc
class4tpc_OBJECTS = \
"CMakeFiles/class4tpc.dir/class4tpc.cc.o" \
"CMakeFiles/class4tpc.dir/src/DetectorConstruction.cc.o" \
"CMakeFiles/class4tpc.dir/src/PrimaryGeneratorAction.cc.o" \
"CMakeFiles/class4tpc.dir/src/SteppingAction.cc.o"

# External object files for target class4tpc
class4tpc_EXTERNAL_OBJECTS =

tpc/class4tpc: tpc/CMakeFiles/class4tpc.dir/class4tpc.cc.o
tpc/class4tpc: tpc/CMakeFiles/class4tpc.dir/src/DetectorConstruction.cc.o
tpc/class4tpc: tpc/CMakeFiles/class4tpc.dir/src/PrimaryGeneratorAction.cc.o
tpc/class4tpc: tpc/CMakeFiles/class4tpc.dir/src/SteppingAction.cc.o
tpc/class4tpc: tpc/CMakeFiles/class4tpc.dir/build.make
tpc/class4tpc: /usr/local/lib/libG4Tree.so
tpc/class4tpc: /usr/local/lib/libG4FR.so
tpc/class4tpc: /usr/local/lib/libG4GMocren.so
tpc/class4tpc: /usr/local/lib/libG4visHepRep.so
tpc/class4tpc: /usr/local/lib/libG4RayTracer.so
tpc/class4tpc: /usr/local/lib/libG4VRML.so
tpc/class4tpc: /usr/local/lib/libG4OpenGL.so
tpc/class4tpc: /usr/local/lib/libG4gl2ps.so
tpc/class4tpc: /usr/local/lib/libG4vis_management.so
tpc/class4tpc: /usr/local/lib/libG4modeling.so
tpc/class4tpc: /usr/local/lib/libG4interfaces.so
tpc/class4tpc: /usr/local/lib/libG4persistency.so
tpc/class4tpc: /usr/local/lib/libG4error_propagation.so
tpc/class4tpc: /usr/local/lib/libG4readout.so
tpc/class4tpc: /usr/local/lib/libG4physicslists.so
tpc/class4tpc: /usr/local/lib/libG4tasking.so
tpc/class4tpc: /usr/local/lib/libG4parmodels.so
tpc/class4tpc: /usr/lib/x86_64-linux-gnu/libGL.so
tpc/class4tpc: /usr/lib/x86_64-linux-gnu/libQt5OpenGL.so.5.12.8
tpc/class4tpc: /usr/lib/x86_64-linux-gnu/libQt5PrintSupport.so.5.12.8
tpc/class4tpc: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.12.8
tpc/class4tpc: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.12.8
tpc/class4tpc: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.12.8
tpc/class4tpc: /usr/local/lib/libG4run.so
tpc/class4tpc: /usr/local/lib/libG4event.so
tpc/class4tpc: /usr/local/lib/libG4tracking.so
tpc/class4tpc: /usr/local/lib/libG4processes.so
tpc/class4tpc: /usr/local/lib/libG4analysis.so
tpc/class4tpc: /usr/lib/x86_64-linux-gnu/libexpat.so
tpc/class4tpc: /usr/local/lib/libG4digits_hits.so
tpc/class4tpc: /usr/local/lib/libG4track.so
tpc/class4tpc: /usr/local/lib/libG4particles.so
tpc/class4tpc: /usr/local/lib/libG4geometry.so
tpc/class4tpc: /usr/local/lib/libG4materials.so
tpc/class4tpc: /usr/local/lib/libG4zlib.so
tpc/class4tpc: /usr/local/lib/libG4graphics_reps.so
tpc/class4tpc: /usr/local/lib/libG4intercoms.so
tpc/class4tpc: /usr/local/lib/libG4global.so
tpc/class4tpc: /usr/local/lib/libG4clhep.so
tpc/class4tpc: /usr/local/lib/libG4ptl.so.0.0.2
tpc/class4tpc: tpc/CMakeFiles/class4tpc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jncfa/idp_exercices/class4/tpc/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable class4tpc"
	cd /home/jncfa/idp_exercices/class4/tpc/tpc && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/class4tpc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tpc/CMakeFiles/class4tpc.dir/build: tpc/class4tpc

.PHONY : tpc/CMakeFiles/class4tpc.dir/build

tpc/CMakeFiles/class4tpc.dir/clean:
	cd /home/jncfa/idp_exercices/class4/tpc/tpc && $(CMAKE_COMMAND) -P CMakeFiles/class4tpc.dir/cmake_clean.cmake
.PHONY : tpc/CMakeFiles/class4tpc.dir/clean

tpc/CMakeFiles/class4tpc.dir/depend:
	cd /home/jncfa/idp_exercices/class4/tpc && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jncfa/idp_exercices/class4 /home/jncfa/idp_exercices/class4/tpc /home/jncfa/idp_exercices/class4/tpc /home/jncfa/idp_exercices/class4/tpc/tpc /home/jncfa/idp_exercices/class4/tpc/tpc/CMakeFiles/class4tpc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tpc/CMakeFiles/class4tpc.dir/depend

