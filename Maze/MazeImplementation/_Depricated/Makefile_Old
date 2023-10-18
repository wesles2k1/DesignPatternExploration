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
${EXECUTABLE}: MazeGame/MazeGame.o MazeGame/MapType.o Player/Player.o Map/Map.o MapFactory/MapFactory.o MapFactory/BombMapFactory/BombMapFactory.o MapFactory/BombMapFactory/AtomicBombMapFactory/AtomicBombMapFactory.o MapFactory/EnchantedMapFactory/EnchantedMapFactory.o MapFactory/LockMapFactory/LockMapFactory.o MapSite/Room/Room.o MapSite/Room/BombRoom/BombRoom.o MapSite/Room/BombRoom/AtomicBombRoom/AtomicBombRoom.o MapSite/Room/EnchantedRoom/EnchantedRoom.o MapSite/Door/Door.o MapSite/Door/EnchantedDoor/EnchantedDoor.o MapSite/Door/LockDoor/LockDoor.o MapSite/Wall/Wall.o MapSite/Wall/BombWall/BombWall.o MapSite/Wall/LockWall/LockWall.o
# Other
MazeGame.o: MazeGame/MazeGame.h
MapType.o: MazeGame/MapType.h
Player.o: Player/Player.h
Map.o: Map/Map.h
# Factories
MapFactory.o: MapFactory/MapFactory.h
BombMapFactory.o: MapFactory/BombMapFactory/BombMapFactory.h
AtomicBombMapFactory.o: MapFactory/BombMapFactory/AtomicBombMapFactory/AtomicBombMapFactory.h
EnchantedMapFactory.o: MapFactory/EnchantedMapFactory/EnchantedMapFactory.h
LockMapFactory.o: MapFactory/LockMapFactory/LockMapFactory.h
# Map Elements
#	Room
Room.o: MapSite/Room/Room.h
BombRoom.o: MapSite/Room/BombRoom/BombRoom.h
AtomicBombRoom.o: MapSite/Room/BombRoom/AtomicBombRoom/AtomicBombRoom.h
EnchantedRoom.o: MapSite/Room/EnchantedRoom/EnchantedRoom.h
#	Door
Door.o: MapSite/Door/Door.h
EnchantedDoor.o: MapSite/Door/EnchantedDoor/EnchantedDoor.h
LockDoor.o: MapSite/Door/LockDoor/LockDoor.h
#	Wall
Wall.o: MapSite/Wall/Wall.h
BombWall.o: MapSite/Wall/BombWall/BombWall.h
LockWall.o: MapSite/Wall/LockWall/LockWall.h