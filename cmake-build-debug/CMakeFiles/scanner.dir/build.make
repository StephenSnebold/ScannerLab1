# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\deoge\scanner-StephenSnebold-master\Project_1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\deoge\scanner-StephenSnebold-master\Project_1\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\scanner.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\scanner.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\scanner.dir\flags.make

CMakeFiles\scanner.dir\src\main.c.obj: CMakeFiles\scanner.dir\flags.make
CMakeFiles\scanner.dir\src\main.c.obj: ..\src\main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\deoge\scanner-StephenSnebold-master\Project_1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/scanner.dir/src/main.c.obj"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\scanner.dir\src\main.c.obj /FdCMakeFiles\scanner.dir\ /FS -c C:\Users\deoge\scanner-StephenSnebold-master\Project_1\src\main.c
<<

CMakeFiles\scanner.dir\src\main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/scanner.dir/src/main.c.i"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe > CMakeFiles\scanner.dir\src\main.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\deoge\scanner-StephenSnebold-master\Project_1\src\main.c
<<

CMakeFiles\scanner.dir\src\main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/scanner.dir/src/main.c.s"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\scanner.dir\src\main.c.s /c C:\Users\deoge\scanner-StephenSnebold-master\Project_1\src\main.c
<<

CMakeFiles\scanner.dir\src\scanner.c.obj: CMakeFiles\scanner.dir\flags.make
CMakeFiles\scanner.dir\src\scanner.c.obj: ..\src\scanner.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\deoge\scanner-StephenSnebold-master\Project_1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/scanner.dir/src/scanner.c.obj"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\scanner.dir\src\scanner.c.obj /FdCMakeFiles\scanner.dir\ /FS -c C:\Users\deoge\scanner-StephenSnebold-master\Project_1\src\scanner.c
<<

CMakeFiles\scanner.dir\src\scanner.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/scanner.dir/src/scanner.c.i"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe > CMakeFiles\scanner.dir\src\scanner.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\deoge\scanner-StephenSnebold-master\Project_1\src\scanner.c
<<

CMakeFiles\scanner.dir\src\scanner.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/scanner.dir/src/scanner.c.s"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\scanner.dir\src\scanner.c.s /c C:\Users\deoge\scanner-StephenSnebold-master\Project_1\src\scanner.c
<<

# Object files for target scanner
scanner_OBJECTS = \
"CMakeFiles\scanner.dir\src\main.c.obj" \
"CMakeFiles\scanner.dir\src\scanner.c.obj"

# External object files for target scanner
scanner_EXTERNAL_OBJECTS =

scanner.exe: CMakeFiles\scanner.dir\src\main.c.obj
scanner.exe: CMakeFiles\scanner.dir\src\scanner.c.obj
scanner.exe: CMakeFiles\scanner.dir\build.make
scanner.exe: CMakeFiles\scanner.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\deoge\scanner-StephenSnebold-master\Project_1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable scanner.exe"
	"C:\Program Files\JetBrains\CLion 2020.3.1\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\scanner.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~1.0\VC\bin\link.exe /nologo @CMakeFiles\scanner.dir\objects1.rsp @<<
 /out:scanner.exe /implib:scanner.lib /pdb:C:\Users\deoge\scanner-StephenSnebold-master\Project_1\cmake-build-debug\scanner.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\scanner.dir\build: scanner.exe

.PHONY : CMakeFiles\scanner.dir\build

CMakeFiles\scanner.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\scanner.dir\cmake_clean.cmake
.PHONY : CMakeFiles\scanner.dir\clean

CMakeFiles\scanner.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\deoge\scanner-StephenSnebold-master\Project_1 C:\Users\deoge\scanner-StephenSnebold-master\Project_1 C:\Users\deoge\scanner-StephenSnebold-master\Project_1\cmake-build-debug C:\Users\deoge\scanner-StephenSnebold-master\Project_1\cmake-build-debug C:\Users\deoge\scanner-StephenSnebold-master\Project_1\cmake-build-debug\CMakeFiles\scanner.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\scanner.dir\depend

