# Wesley Partch's Makefile
# Written: 10/17/2023
# Last Edited: 10/17/2023
#
# This Makefile is made for Powershell and is generalized for use across different projects.
# This Makefile will create and link object files all throughout a root directory unless explicitely exluded.
# Ideally, the only lines you may want to alter in this make file are:
#	`Executable = ...` if you wish to rename the produced executable file
#	`ROOT_PATH = ...` if you wish to specify the root directory of your project (use `.` if this Makefile is already in your root)
#		!IMPORTANT! This functionality is still under development. While it works desirable with `make clean`, `make` still does not work.
#			Until this functions, please do not change this value from `.` and keep this Makefile in your root directory.
#	`EXE_PATH = ...` if you wish to specify the executable's destination
#	(something about specifying what SOURCE files to use. I should make one line to include every .cpp, one to specify what to include, and one to specify what to exclude, and comment the latter two out so it is all by default)

# Improvements to be made:
#	Fix `ROOT_PATH`'s interaction with `make` so this Makefile is not required to be in the root directory
#	Add optional lines to offer the option of excluding or including specified files
#	Can this be generalized to work for both Powershell and Bash?

# --------- #
# Variables #
# --------- #

# Compiler
CXX = g++
# Compiler Flags
CXXFLAGS = -g -O3 -Wpedantic -Wall -Wextra -Wmisleading-indentation -Wunused -Wuninitialized -Wshadow -Wconversion -Werror -std=c++17

# Executable File Name
EXECUTABLE = main
# Object Files
OBJECTS = $(SOURCES:.cpp=.o)
# Source Files
EXCLUDED = $(ROOT_PATH)/_Depricated
SOURCES = $(shell powershell Get-ChildItem $(ROOT_PATH)/ -Recurse -Filter *.cpp -Name)

# Path to the root directory (from which to use implementation files)
ROOT_PATH = .
# Path to the desired directory of the produced executable (from this Makefile)
EXE_PATH = $(ROOT_PATH)

# ----- #
# Rules #
# ----- #

# Rule to build object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# -------------------- #
# Compilation Commands #
# -------------------- #

.PHONY: all clean rebuild

# Default `make` command; Builds object files and executable
all: $(EXECUTABLE)

# Builds object files and executable by linking object files together
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(EXE_PATH)/$(EXECUTABLE) $(OBJECTS)

# Cleans project by deleting executable and all files generated on compilation
clean:
	powershell rm $(ROOT_PATH)/* -Include *.exe, *.o, *.gcov, *.gcno, *.gcda -Recurse -ErrorAction Ignore; $$null

# Cleans project and recompiles from the ground up
rebuild:
	make clean
	powershell clear
	powershell clear
	make $(EXECUTABLE)

# ----- #
# Other #
# ----- #

.PHONY: check

# Use to check what are being read as Source files to ensure the program is being compiled correctly
check:
	$(info Sources used: $(SOURCES))