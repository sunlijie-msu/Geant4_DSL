# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/hgfs/Geant4_DSL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/hgfs/Geant4_DSL/Build_Geant4_DSL

# Include any dependencies generated for this target.
include CMakeFiles/tele.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tele.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tele.dir/flags.make

CMakeFiles/tele.dir/tele.cc.o: CMakeFiles/tele.dir/flags.make
CMakeFiles/tele.dir/tele.cc.o: ../tele.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/hgfs/Geant4_DSL/Build_Geant4_DSL/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tele.dir/tele.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tele.dir/tele.cc.o -c /mnt/hgfs/Geant4_DSL/tele.cc

CMakeFiles/tele.dir/tele.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tele.dir/tele.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/Geant4_DSL/tele.cc > CMakeFiles/tele.dir/tele.cc.i

CMakeFiles/tele.dir/tele.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tele.dir/tele.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/Geant4_DSL/tele.cc -o CMakeFiles/tele.dir/tele.cc.s

CMakeFiles/tele.dir/src/ExG4ActionInitialization.cc.o: CMakeFiles/tele.dir/flags.make
CMakeFiles/tele.dir/src/ExG4ActionInitialization.cc.o: ../src/ExG4ActionInitialization.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/hgfs/Geant4_DSL/Build_Geant4_DSL/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/tele.dir/src/ExG4ActionInitialization.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tele.dir/src/ExG4ActionInitialization.cc.o -c /mnt/hgfs/Geant4_DSL/src/ExG4ActionInitialization.cc

CMakeFiles/tele.dir/src/ExG4ActionInitialization.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tele.dir/src/ExG4ActionInitialization.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/Geant4_DSL/src/ExG4ActionInitialization.cc > CMakeFiles/tele.dir/src/ExG4ActionInitialization.cc.i

CMakeFiles/tele.dir/src/ExG4ActionInitialization.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tele.dir/src/ExG4ActionInitialization.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/Geant4_DSL/src/ExG4ActionInitialization.cc -o CMakeFiles/tele.dir/src/ExG4ActionInitialization.cc.s

CMakeFiles/tele.dir/src/ExG4DetectorConstruction.cc.o: CMakeFiles/tele.dir/flags.make
CMakeFiles/tele.dir/src/ExG4DetectorConstruction.cc.o: ../src/ExG4DetectorConstruction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/hgfs/Geant4_DSL/Build_Geant4_DSL/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/tele.dir/src/ExG4DetectorConstruction.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tele.dir/src/ExG4DetectorConstruction.cc.o -c /mnt/hgfs/Geant4_DSL/src/ExG4DetectorConstruction.cc

CMakeFiles/tele.dir/src/ExG4DetectorConstruction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tele.dir/src/ExG4DetectorConstruction.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/Geant4_DSL/src/ExG4DetectorConstruction.cc > CMakeFiles/tele.dir/src/ExG4DetectorConstruction.cc.i

CMakeFiles/tele.dir/src/ExG4DetectorConstruction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tele.dir/src/ExG4DetectorConstruction.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/Geant4_DSL/src/ExG4DetectorConstruction.cc -o CMakeFiles/tele.dir/src/ExG4DetectorConstruction.cc.s

CMakeFiles/tele.dir/src/ExG4EventAction.cc.o: CMakeFiles/tele.dir/flags.make
CMakeFiles/tele.dir/src/ExG4EventAction.cc.o: ../src/ExG4EventAction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/hgfs/Geant4_DSL/Build_Geant4_DSL/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/tele.dir/src/ExG4EventAction.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tele.dir/src/ExG4EventAction.cc.o -c /mnt/hgfs/Geant4_DSL/src/ExG4EventAction.cc

CMakeFiles/tele.dir/src/ExG4EventAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tele.dir/src/ExG4EventAction.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/Geant4_DSL/src/ExG4EventAction.cc > CMakeFiles/tele.dir/src/ExG4EventAction.cc.i

CMakeFiles/tele.dir/src/ExG4EventAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tele.dir/src/ExG4EventAction.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/Geant4_DSL/src/ExG4EventAction.cc -o CMakeFiles/tele.dir/src/ExG4EventAction.cc.s

CMakeFiles/tele.dir/src/ExG4Hit.cc.o: CMakeFiles/tele.dir/flags.make
CMakeFiles/tele.dir/src/ExG4Hit.cc.o: ../src/ExG4Hit.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/hgfs/Geant4_DSL/Build_Geant4_DSL/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/tele.dir/src/ExG4Hit.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tele.dir/src/ExG4Hit.cc.o -c /mnt/hgfs/Geant4_DSL/src/ExG4Hit.cc

CMakeFiles/tele.dir/src/ExG4Hit.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tele.dir/src/ExG4Hit.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/Geant4_DSL/src/ExG4Hit.cc > CMakeFiles/tele.dir/src/ExG4Hit.cc.i

CMakeFiles/tele.dir/src/ExG4Hit.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tele.dir/src/ExG4Hit.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/Geant4_DSL/src/ExG4Hit.cc -o CMakeFiles/tele.dir/src/ExG4Hit.cc.s

CMakeFiles/tele.dir/src/ExG4PhysicsList.cc.o: CMakeFiles/tele.dir/flags.make
CMakeFiles/tele.dir/src/ExG4PhysicsList.cc.o: ../src/ExG4PhysicsList.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/hgfs/Geant4_DSL/Build_Geant4_DSL/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/tele.dir/src/ExG4PhysicsList.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tele.dir/src/ExG4PhysicsList.cc.o -c /mnt/hgfs/Geant4_DSL/src/ExG4PhysicsList.cc

CMakeFiles/tele.dir/src/ExG4PhysicsList.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tele.dir/src/ExG4PhysicsList.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/Geant4_DSL/src/ExG4PhysicsList.cc > CMakeFiles/tele.dir/src/ExG4PhysicsList.cc.i

CMakeFiles/tele.dir/src/ExG4PhysicsList.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tele.dir/src/ExG4PhysicsList.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/Geant4_DSL/src/ExG4PhysicsList.cc -o CMakeFiles/tele.dir/src/ExG4PhysicsList.cc.s

CMakeFiles/tele.dir/src/ExG4PrimaryGeneratorAction.cc.o: CMakeFiles/tele.dir/flags.make
CMakeFiles/tele.dir/src/ExG4PrimaryGeneratorAction.cc.o: ../src/ExG4PrimaryGeneratorAction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/hgfs/Geant4_DSL/Build_Geant4_DSL/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/tele.dir/src/ExG4PrimaryGeneratorAction.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tele.dir/src/ExG4PrimaryGeneratorAction.cc.o -c /mnt/hgfs/Geant4_DSL/src/ExG4PrimaryGeneratorAction.cc

CMakeFiles/tele.dir/src/ExG4PrimaryGeneratorAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tele.dir/src/ExG4PrimaryGeneratorAction.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/Geant4_DSL/src/ExG4PrimaryGeneratorAction.cc > CMakeFiles/tele.dir/src/ExG4PrimaryGeneratorAction.cc.i

CMakeFiles/tele.dir/src/ExG4PrimaryGeneratorAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tele.dir/src/ExG4PrimaryGeneratorAction.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/Geant4_DSL/src/ExG4PrimaryGeneratorAction.cc -o CMakeFiles/tele.dir/src/ExG4PrimaryGeneratorAction.cc.s

CMakeFiles/tele.dir/src/ExG4RunAction.cc.o: CMakeFiles/tele.dir/flags.make
CMakeFiles/tele.dir/src/ExG4RunAction.cc.o: ../src/ExG4RunAction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/hgfs/Geant4_DSL/Build_Geant4_DSL/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/tele.dir/src/ExG4RunAction.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tele.dir/src/ExG4RunAction.cc.o -c /mnt/hgfs/Geant4_DSL/src/ExG4RunAction.cc

CMakeFiles/tele.dir/src/ExG4RunAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tele.dir/src/ExG4RunAction.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/Geant4_DSL/src/ExG4RunAction.cc > CMakeFiles/tele.dir/src/ExG4RunAction.cc.i

CMakeFiles/tele.dir/src/ExG4RunAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tele.dir/src/ExG4RunAction.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/Geant4_DSL/src/ExG4RunAction.cc -o CMakeFiles/tele.dir/src/ExG4RunAction.cc.s

CMakeFiles/tele.dir/src/ExG4SD.cc.o: CMakeFiles/tele.dir/flags.make
CMakeFiles/tele.dir/src/ExG4SD.cc.o: ../src/ExG4SD.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/hgfs/Geant4_DSL/Build_Geant4_DSL/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/tele.dir/src/ExG4SD.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tele.dir/src/ExG4SD.cc.o -c /mnt/hgfs/Geant4_DSL/src/ExG4SD.cc

CMakeFiles/tele.dir/src/ExG4SD.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tele.dir/src/ExG4SD.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/Geant4_DSL/src/ExG4SD.cc > CMakeFiles/tele.dir/src/ExG4SD.cc.i

CMakeFiles/tele.dir/src/ExG4SD.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tele.dir/src/ExG4SD.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/Geant4_DSL/src/ExG4SD.cc -o CMakeFiles/tele.dir/src/ExG4SD.cc.s

CMakeFiles/tele.dir/src/PhysListEmStandard.cc.o: CMakeFiles/tele.dir/flags.make
CMakeFiles/tele.dir/src/PhysListEmStandard.cc.o: ../src/PhysListEmStandard.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/hgfs/Geant4_DSL/Build_Geant4_DSL/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/tele.dir/src/PhysListEmStandard.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tele.dir/src/PhysListEmStandard.cc.o -c /mnt/hgfs/Geant4_DSL/src/PhysListEmStandard.cc

CMakeFiles/tele.dir/src/PhysListEmStandard.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tele.dir/src/PhysListEmStandard.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/Geant4_DSL/src/PhysListEmStandard.cc > CMakeFiles/tele.dir/src/PhysListEmStandard.cc.i

CMakeFiles/tele.dir/src/PhysListEmStandard.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tele.dir/src/PhysListEmStandard.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/Geant4_DSL/src/PhysListEmStandard.cc -o CMakeFiles/tele.dir/src/PhysListEmStandard.cc.s

# Object files for target tele
tele_OBJECTS = \
"CMakeFiles/tele.dir/tele.cc.o" \
"CMakeFiles/tele.dir/src/ExG4ActionInitialization.cc.o" \
"CMakeFiles/tele.dir/src/ExG4DetectorConstruction.cc.o" \
"CMakeFiles/tele.dir/src/ExG4EventAction.cc.o" \
"CMakeFiles/tele.dir/src/ExG4Hit.cc.o" \
"CMakeFiles/tele.dir/src/ExG4PhysicsList.cc.o" \
"CMakeFiles/tele.dir/src/ExG4PrimaryGeneratorAction.cc.o" \
"CMakeFiles/tele.dir/src/ExG4RunAction.cc.o" \
"CMakeFiles/tele.dir/src/ExG4SD.cc.o" \
"CMakeFiles/tele.dir/src/PhysListEmStandard.cc.o"

# External object files for target tele
tele_EXTERNAL_OBJECTS =

tele: CMakeFiles/tele.dir/tele.cc.o
tele: CMakeFiles/tele.dir/src/ExG4ActionInitialization.cc.o
tele: CMakeFiles/tele.dir/src/ExG4DetectorConstruction.cc.o
tele: CMakeFiles/tele.dir/src/ExG4EventAction.cc.o
tele: CMakeFiles/tele.dir/src/ExG4Hit.cc.o
tele: CMakeFiles/tele.dir/src/ExG4PhysicsList.cc.o
tele: CMakeFiles/tele.dir/src/ExG4PrimaryGeneratorAction.cc.o
tele: CMakeFiles/tele.dir/src/ExG4RunAction.cc.o
tele: CMakeFiles/tele.dir/src/ExG4SD.cc.o
tele: CMakeFiles/tele.dir/src/PhysListEmStandard.cc.o
tele: CMakeFiles/tele.dir/build.make
tele: /home/sun/app/geant4.10.02-install/lib/libG4Tree.so
tele: /home/sun/app/geant4.10.02-install/lib/libG4GMocren.so
tele: /home/sun/app/geant4.10.02-install/lib/libG4visHepRep.so
tele: /home/sun/app/geant4.10.02-install/lib/libG4RayTracer.so
tele: /home/sun/app/geant4.10.02-install/lib/libG4VRML.so
tele: /home/sun/app/geant4.10.02-install/lib/libG4OpenGL.so
tele: /home/sun/app/geant4.10.02-install/lib/libG4gl2ps.so
tele: /home/sun/app/geant4.10.02-install/lib/libG4interfaces.so
tele: /home/sun/app/geant4.10.02-install/lib/libG4persistency.so
tele: /home/sun/app/geant4.10.02-install/lib/libG4analysis.so
tele: /home/sun/app/geant4.10.02-install/lib/libG4error_propagation.so
tele: /home/sun/app/geant4.10.02-install/lib/libG4readout.so
tele: /home/sun/app/geant4.10.02-install/lib/libG4physicslists.so
tele: /home/sun/app/geant4.10.02-install/lib/libG4parmodels.so
tele: /home/sun/app/geant4.10.02-install/lib/libG4FR.so
tele: /home/sun/app/geant4.10.02-install/lib/libG4vis_management.so
tele: /home/sun/app/geant4.10.02-install/lib/libG4modeling.so
tele: /usr/lib/x86_64-linux-gnu/libXm.so
tele: /usr/lib/x86_64-linux-gnu/libSM.so
tele: /usr/lib/x86_64-linux-gnu/libICE.so
tele: /usr/lib/x86_64-linux-gnu/libX11.so
tele: /usr/lib/x86_64-linux-gnu/libXext.so
tele: /usr/lib/x86_64-linux-gnu/libXt.so
tele: /usr/lib/x86_64-linux-gnu/libXmu.so
tele: /usr/lib/x86_64-linux-gnu/libGL.so
tele: /usr/lib/x86_64-linux-gnu/libGLU.so
tele: /usr/lib/x86_64-linux-gnu/libQt5OpenGL.so.5.12.8
tele: /usr/lib/x86_64-linux-gnu/libQt5PrintSupport.so.5.12.8
tele: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.12.8
tele: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.12.8
tele: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.12.8
tele: /usr/lib/x86_64-linux-gnu/libxerces-c.so
tele: /usr/lib/x86_64-linux-gnu/libfreetype.so
tele: /home/sun/app/geant4.10.02-install/lib/libG4run.so
tele: /home/sun/app/geant4.10.02-install/lib/libG4event.so
tele: /home/sun/app/geant4.10.02-install/lib/libG4tracking.so
tele: /home/sun/app/geant4.10.02-install/lib/libG4processes.so
tele: /home/sun/app/geant4.10.02-install/lib/libG4zlib.so
tele: /usr/lib/x86_64-linux-gnu/libexpat.so
tele: /home/sun/app/geant4.10.02-install/lib/libG4digits_hits.so
tele: /home/sun/app/geant4.10.02-install/lib/libG4track.so
tele: /home/sun/app/geant4.10.02-install/lib/libG4particles.so
tele: /home/sun/app/geant4.10.02-install/lib/libG4geometry.so
tele: /home/sun/app/geant4.10.02-install/lib/libG4materials.so
tele: /home/sun/app/geant4.10.02-install/lib/libG4graphics_reps.so
tele: /home/sun/app/geant4.10.02-install/lib/libG4intercoms.so
tele: /home/sun/app/geant4.10.02-install/lib/libG4global.so
tele: /home/sun/app/geant4.10.02-install/lib/libG4clhep.so
tele: CMakeFiles/tele.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/hgfs/Geant4_DSL/Build_Geant4_DSL/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable tele"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tele.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tele.dir/build: tele

.PHONY : CMakeFiles/tele.dir/build

CMakeFiles/tele.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tele.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tele.dir/clean

CMakeFiles/tele.dir/depend:
	cd /mnt/hgfs/Geant4_DSL/Build_Geant4_DSL && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/hgfs/Geant4_DSL /mnt/hgfs/Geant4_DSL /mnt/hgfs/Geant4_DSL/Build_Geant4_DSL /mnt/hgfs/Geant4_DSL/Build_Geant4_DSL /mnt/hgfs/Geant4_DSL/Build_Geant4_DSL/CMakeFiles/tele.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tele.dir/depend

