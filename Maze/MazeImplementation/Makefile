# Wesley Partch's Makefile
# Written: 10/17/2023
# Last Edited: 10/19/2023
#
# This Makefile is made for PowerShell on a Windows machine and is generalized for use across different projects.
# This Makefile will create and link object files all throughout the directory it is in.
# Likely, the only lines you may want to alter in this make file are:
#	`EXECUTABLE = ...` if you wish to rename the produced executable file
#	`ROOT_PATH = ...` if you wish to specify the project's root directory
#	`EXE_PATH = ...` if you wish to specify the executable's destination
#	`EXCLUDE = ...` if you wish to specify files and/or directories to exclude from compilation
#	`INCLUDE = ...` if you wish to specify files and/or directories to include from compilation (priority over EXCLUDE)
# Please note that the `clean` command will not adhere to EXCLUDE or INCLUDE specifiers, and will clean only and entirely the root directory
# Theoretically, this Makefile may be improved to be generalized across different shells and operating systems.

# ----------------------- #
# Configuration Variables #
# ----------------------- #

# Compiler
CXX = g++
# Compiler Flags
CXXFLAGS = -g -O3 -Wpedantic -Wall -Wextra -Wmisleading-indentation -Wunused -Wuninitialized -Wshadow -Wconversion -Werror -std=c++23

# Executable Name
EXECUTABLE = main
# Path to the root file from this Makefile (`.` for this Makefile's directory; Use `\` for navigation)
ROOT_PATH = .
# Path to the executable destination from this Makefile (Use `\` for navigation)
EXE_PATH = .
# Excludes directories/files relative to this Makefile from compilation if they exist (Use `\` for navigation and `%` as a wildcard)
EXCLUDE = _Deprecated%
# Includes directories/files relative to this Makefile from compilation if they exist (Use `\` for navigation and `%` as a wildcard) (priority over EXCLUDE)
INCLUDE = 

# ------------------- #
# Variable Processing #
# ------------------- #

# Object Files
OBJECTS = $(SOURCES:.cpp=.o)

# Source Files
SOURCES = $(addprefix $(ROOT_PATH)\, $(shell powershell -Command "Get-ChildItem $(ROOT_PATH) -Recurse -Filter *.cpp -Name"))

EXCLUDE := $(addprefix $(ROOT_PATH)\, $(EXCLUDE))
SOURCES := $(filter-out $(EXCLUDE), $(SOURCES))

SOURCES += $(addprefix $(ROOT_PATH)\, $(filter-out \
	$(SOURCES), $(filter $(INCLUDE), \
		$(shell powershell -Command "Get-ChildItem $(ROOT_PATH) -Recurse -Filter *.cpp -Name") \
	) \
))

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
	powershell -Command "rm $(ROOT_PATH)\* -Include *.exe, *.o, *.gcov, *.gcno, *.gcda -Recurse -ErrorAction Ignore; $$null"

# Cleans project and recompiles from the ground up
rebuild:
	make clean
	powershell -Command "clear"
	powershell -Command "clear"
	make $(EXECUTABLE)

# ----- #
# Other #
# ----- #

.PHONY: check

# Use to check what are being read as Source files to ensure the program is being compiled correctly
check:
	@echo "SOURCES:"
	@echo $(SOURCES)