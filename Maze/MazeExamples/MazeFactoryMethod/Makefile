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
${EXECUTABLE}: MazeGame/MazeGame.o Player/Player.o Map/Map.o MazeGame/BombMazeGame/BombMazeGame.o MazeGame/EnchantedMazeGame/EnchantedMazeGame.o MapSite/Room/Room.o MapSite/Room/BombRoom/BombRoom.o MapSite/Room/EnchantedRoom/EnchantedRoom.o MapSite/Door/Door.o MapSite/Door/EnchantedDoor/EnchantedDoor.o MapSite/Wall/Wall.o MapSite/Wall/BombWall/BombWall.o
MazeGame.o: MazeGame/MazeGame.h
BombMazeGame.o: MazeGame/BombMazeGame/BombMazeGame.h
EnchantedMazeGame.o: MazeGame/EnchantedMazeGame/EnchantedMazeGame.h
Player.o: Player/Player.h
Map.o: Map/Map.h
Room.o: MapSite/Room/Room.h
BombRoom.o: MapSite/Room/BombRoom/BombRoom.h
EnchantedRoom.o: MapSite/Room/EnchantedRoom/EnchantedRoom.h
Door.o: MapSite/Door/Door.h
EnchantedDoor.o: MapSite/Door/EnchantedDoor/EnchantedDoor.h
Wall.o: MapSite/Wall/Wall.h
BombWall.o: MapSite/Wall/BombWall/BombWall.h