# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_SOURCE_DIR = /home/hollow/vscpp/Tchat/src/server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hollow/vscpp/Tchat/src/server/build

# Include any dependencies generated for this target.
include CMakeFiles/server_main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/server_main.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/server_main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/server_main.dir/flags.make

CMakeFiles/server_main.dir/codegen:
.PHONY : CMakeFiles/server_main.dir/codegen

CMakeFiles/server_main.dir/server_main.cpp.o: CMakeFiles/server_main.dir/flags.make
CMakeFiles/server_main.dir/server_main.cpp.o: /home/hollow/vscpp/Tchat/src/server/server_main.cpp
CMakeFiles/server_main.dir/server_main.cpp.o: CMakeFiles/server_main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/hollow/vscpp/Tchat/src/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/server_main.dir/server_main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/server_main.dir/server_main.cpp.o -MF CMakeFiles/server_main.dir/server_main.cpp.o.d -o CMakeFiles/server_main.dir/server_main.cpp.o -c /home/hollow/vscpp/Tchat/src/server/server_main.cpp

CMakeFiles/server_main.dir/server_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/server_main.dir/server_main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hollow/vscpp/Tchat/src/server/server_main.cpp > CMakeFiles/server_main.dir/server_main.cpp.i

CMakeFiles/server_main.dir/server_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/server_main.dir/server_main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hollow/vscpp/Tchat/src/server/server_main.cpp -o CMakeFiles/server_main.dir/server_main.cpp.s

# Object files for target server_main
server_main_OBJECTS = \
"CMakeFiles/server_main.dir/server_main.cpp.o"

# External object files for target server_main
server_main_EXTERNAL_OBJECTS =

server_main: CMakeFiles/server_main.dir/server_main.cpp.o
server_main: CMakeFiles/server_main.dir/build.make
server_main: CMakeFiles/server_main.dir/compiler_depend.ts
server_main: libTcpServer.so
server_main: /usr/lib/libmariadb.so
server_main: CMakeFiles/server_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/hollow/vscpp/Tchat/src/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable server_main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/server_main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/server_main.dir/build: server_main
.PHONY : CMakeFiles/server_main.dir/build

CMakeFiles/server_main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/server_main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/server_main.dir/clean

CMakeFiles/server_main.dir/depend:
	cd /home/hollow/vscpp/Tchat/src/server/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hollow/vscpp/Tchat/src/server /home/hollow/vscpp/Tchat/src/server /home/hollow/vscpp/Tchat/src/server/build /home/hollow/vscpp/Tchat/src/server/build /home/hollow/vscpp/Tchat/src/server/build/CMakeFiles/server_main.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/server_main.dir/depend

