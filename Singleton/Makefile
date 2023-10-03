#Works for Powershell

.PHONY: all clean fresh

CXXFLAGS = -g -O3 -Wpedantic -Wall -Wextra -Wmisleading-indentation -Wunused -Wuninitialized -Wshadow -Wconversion -Werror -std=c++17

EXECUTABLE = main

all: ${EXECUTABLE}

# Cleans project by deleting executable and all files generated on compilation
clean:
	powershell rm * -Include ${EXECUTABLE}.exe, *.o, *.gcov, *.gcno, *.gcda -Recurse -ErrorAction Ignore; $$null

# Cleans project and recompiles from the ground up
fresh:
	make clean
	powershell clear
	powershell clear
	make ${EXECUTABLE}

# Builds executable and associated object files
${EXECUTABLE}: Singleton.o
Singleton.o: Singleton.h