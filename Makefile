# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.26.3/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.26.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ohdonggeun/workspace/test/snakeGame

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ohdonggeun/workspace/test/snakeGame

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/opt/homebrew/Cellar/cmake/3.26.3/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/opt/homebrew/Cellar/cmake/3.26.3/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/ohdonggeun/workspace/test/snakeGame/CMakeFiles /Users/ohdonggeun/workspace/test/snakeGame//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/ohdonggeun/workspace/test/snakeGame/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named snakeGame

# Build rule for target.
snakeGame: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 snakeGame
.PHONY : snakeGame

# fast build rule for target.
snakeGame/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/snakeGame.dir/build.make CMakeFiles/snakeGame.dir/build
.PHONY : snakeGame/fast

game/Object.o: game/Object.cpp.o
.PHONY : game/Object.o

# target to build an object file
game/Object.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/snakeGame.dir/build.make CMakeFiles/snakeGame.dir/game/Object.cpp.o
.PHONY : game/Object.cpp.o

game/Object.i: game/Object.cpp.i
.PHONY : game/Object.i

# target to preprocess a source file
game/Object.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/snakeGame.dir/build.make CMakeFiles/snakeGame.dir/game/Object.cpp.i
.PHONY : game/Object.cpp.i

game/Object.s: game/Object.cpp.s
.PHONY : game/Object.s

# target to generate assembly for a file
game/Object.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/snakeGame.dir/build.make CMakeFiles/snakeGame.dir/game/Object.cpp.s
.PHONY : game/Object.cpp.s

game/eatable/Eatable.o: game/eatable/Eatable.cpp.o
.PHONY : game/eatable/Eatable.o

# target to build an object file
game/eatable/Eatable.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/snakeGame.dir/build.make CMakeFiles/snakeGame.dir/game/eatable/Eatable.cpp.o
.PHONY : game/eatable/Eatable.cpp.o

game/eatable/Eatable.i: game/eatable/Eatable.cpp.i
.PHONY : game/eatable/Eatable.i

# target to preprocess a source file
game/eatable/Eatable.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/snakeGame.dir/build.make CMakeFiles/snakeGame.dir/game/eatable/Eatable.cpp.i
.PHONY : game/eatable/Eatable.cpp.i

game/eatable/Eatable.s: game/eatable/Eatable.cpp.s
.PHONY : game/eatable/Eatable.s

# target to generate assembly for a file
game/eatable/Eatable.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/snakeGame.dir/build.make CMakeFiles/snakeGame.dir/game/eatable/Eatable.cpp.s
.PHONY : game/eatable/Eatable.cpp.s

game/eatable/Fruit.o: game/eatable/Fruit.cpp.o
.PHONY : game/eatable/Fruit.o

# target to build an object file
game/eatable/Fruit.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/snakeGame.dir/build.make CMakeFiles/snakeGame.dir/game/eatable/Fruit.cpp.o
.PHONY : game/eatable/Fruit.cpp.o

game/eatable/Fruit.i: game/eatable/Fruit.cpp.i
.PHONY : game/eatable/Fruit.i

# target to preprocess a source file
game/eatable/Fruit.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/snakeGame.dir/build.make CMakeFiles/snakeGame.dir/game/eatable/Fruit.cpp.i
.PHONY : game/eatable/Fruit.cpp.i

game/eatable/Fruit.s: game/eatable/Fruit.cpp.s
.PHONY : game/eatable/Fruit.s

# target to generate assembly for a file
game/eatable/Fruit.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/snakeGame.dir/build.make CMakeFiles/snakeGame.dir/game/eatable/Fruit.cpp.s
.PHONY : game/eatable/Fruit.cpp.s

game/eatable/Poison.o: game/eatable/Poison.cpp.o
.PHONY : game/eatable/Poison.o

# target to build an object file
game/eatable/Poison.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/snakeGame.dir/build.make CMakeFiles/snakeGame.dir/game/eatable/Poison.cpp.o
.PHONY : game/eatable/Poison.cpp.o

game/eatable/Poison.i: game/eatable/Poison.cpp.i
.PHONY : game/eatable/Poison.i

# target to preprocess a source file
game/eatable/Poison.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/snakeGame.dir/build.make CMakeFiles/snakeGame.dir/game/eatable/Poison.cpp.i
.PHONY : game/eatable/Poison.cpp.i

game/eatable/Poison.s: game/eatable/Poison.cpp.s
.PHONY : game/eatable/Poison.s

# target to generate assembly for a file
game/eatable/Poison.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/snakeGame.dir/build.make CMakeFiles/snakeGame.dir/game/eatable/Poison.cpp.s
.PHONY : game/eatable/Poison.cpp.s

game/map/Gate.o: game/map/Gate.cpp.o
.PHONY : game/map/Gate.o

# target to build an object file
game/map/Gate.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/snakeGame.dir/build.make CMakeFiles/snakeGame.dir/game/map/Gate.cpp.o
.PHONY : game/map/Gate.cpp.o

game/map/Gate.i: game/map/Gate.cpp.i
.PHONY : game/map/Gate.i

# target to preprocess a source file
game/map/Gate.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/snakeGame.dir/build.make CMakeFiles/snakeGame.dir/game/map/Gate.cpp.i
.PHONY : game/map/Gate.cpp.i

game/map/Gate.s: game/map/Gate.cpp.s
.PHONY : game/map/Gate.s

# target to generate assembly for a file
game/map/Gate.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/snakeGame.dir/build.make CMakeFiles/snakeGame.dir/game/map/Gate.cpp.s
.PHONY : game/map/Gate.cpp.s

game/map/ImmuneWall.o: game/map/ImmuneWall.cpp.o
.PHONY : game/map/ImmuneWall.o

# target to build an object file
game/map/ImmuneWall.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/snakeGame.dir/build.make CMakeFiles/snakeGame.dir/game/map/ImmuneWall.cpp.o
.PHONY : game/map/ImmuneWall.cpp.o

game/map/ImmuneWall.i: game/map/ImmuneWall.cpp.i
.PHONY : game/map/ImmuneWall.i

# target to preprocess a source file
game/map/ImmuneWall.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/snakeGame.dir/build.make CMakeFiles/snakeGame.dir/game/map/ImmuneWall.cpp.i
.PHONY : game/map/ImmuneWall.cpp.i

game/map/ImmuneWall.s: game/map/ImmuneWall.cpp.s
.PHONY : game/map/ImmuneWall.s

# target to generate assembly for a file
game/map/ImmuneWall.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/snakeGame.dir/build.make CMakeFiles/snakeGame.dir/game/map/ImmuneWall.cpp.s
.PHONY : game/map/ImmuneWall.cpp.s

game/map/Wall.o: game/map/Wall.cpp.o
.PHONY : game/map/Wall.o

# target to build an object file
game/map/Wall.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/snakeGame.dir/build.make CMakeFiles/snakeGame.dir/game/map/Wall.cpp.o
.PHONY : game/map/Wall.cpp.o

game/map/Wall.i: game/map/Wall.cpp.i
.PHONY : game/map/Wall.i

# target to preprocess a source file
game/map/Wall.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/snakeGame.dir/build.make CMakeFiles/snakeGame.dir/game/map/Wall.cpp.i
.PHONY : game/map/Wall.cpp.i

game/map/Wall.s: game/map/Wall.cpp.s
.PHONY : game/map/Wall.s

# target to generate assembly for a file
game/map/Wall.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/snakeGame.dir/build.make CMakeFiles/snakeGame.dir/game/map/Wall.cpp.s
.PHONY : game/map/Wall.cpp.s

game/snake/SnakeHead.o: game/snake/SnakeHead.cpp.o
.PHONY : game/snake/SnakeHead.o

# target to build an object file
game/snake/SnakeHead.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/snakeGame.dir/build.make CMakeFiles/snakeGame.dir/game/snake/SnakeHead.cpp.o
.PHONY : game/snake/SnakeHead.cpp.o

game/snake/SnakeHead.i: game/snake/SnakeHead.cpp.i
.PHONY : game/snake/SnakeHead.i

# target to preprocess a source file
game/snake/SnakeHead.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/snakeGame.dir/build.make CMakeFiles/snakeGame.dir/game/snake/SnakeHead.cpp.i
.PHONY : game/snake/SnakeHead.cpp.i

game/snake/SnakeHead.s: game/snake/SnakeHead.cpp.s
.PHONY : game/snake/SnakeHead.s

# target to generate assembly for a file
game/snake/SnakeHead.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/snakeGame.dir/build.make CMakeFiles/snakeGame.dir/game/snake/SnakeHead.cpp.s
.PHONY : game/snake/SnakeHead.cpp.s

game/snake/SnakeTail.o: game/snake/SnakeTail.cpp.o
.PHONY : game/snake/SnakeTail.o

# target to build an object file
game/snake/SnakeTail.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/snakeGame.dir/build.make CMakeFiles/snakeGame.dir/game/snake/SnakeTail.cpp.o
.PHONY : game/snake/SnakeTail.cpp.o

game/snake/SnakeTail.i: game/snake/SnakeTail.cpp.i
.PHONY : game/snake/SnakeTail.i

# target to preprocess a source file
game/snake/SnakeTail.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/snakeGame.dir/build.make CMakeFiles/snakeGame.dir/game/snake/SnakeTail.cpp.i
.PHONY : game/snake/SnakeTail.cpp.i

game/snake/SnakeTail.s: game/snake/SnakeTail.cpp.s
.PHONY : game/snake/SnakeTail.s

# target to generate assembly for a file
game/snake/SnakeTail.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/snakeGame.dir/build.make CMakeFiles/snakeGame.dir/game/snake/SnakeTail.cpp.s
.PHONY : game/snake/SnakeTail.cpp.s

main.o: main.cpp.o
.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/snakeGame.dir/build.make CMakeFiles/snakeGame.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i
.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/snakeGame.dir/build.make CMakeFiles/snakeGame.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s
.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/snakeGame.dir/build.make CMakeFiles/snakeGame.dir/main.cpp.s
.PHONY : main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... snakeGame"
	@echo "... game/Object.o"
	@echo "... game/Object.i"
	@echo "... game/Object.s"
	@echo "... game/eatable/Eatable.o"
	@echo "... game/eatable/Eatable.i"
	@echo "... game/eatable/Eatable.s"
	@echo "... game/eatable/Fruit.o"
	@echo "... game/eatable/Fruit.i"
	@echo "... game/eatable/Fruit.s"
	@echo "... game/eatable/Poison.o"
	@echo "... game/eatable/Poison.i"
	@echo "... game/eatable/Poison.s"
	@echo "... game/map/Gate.o"
	@echo "... game/map/Gate.i"
	@echo "... game/map/Gate.s"
	@echo "... game/map/ImmuneWall.o"
	@echo "... game/map/ImmuneWall.i"
	@echo "... game/map/ImmuneWall.s"
	@echo "... game/map/Wall.o"
	@echo "... game/map/Wall.i"
	@echo "... game/map/Wall.s"
	@echo "... game/snake/SnakeHead.o"
	@echo "... game/snake/SnakeHead.i"
	@echo "... game/snake/SnakeHead.s"
	@echo "... game/snake/SnakeTail.o"
	@echo "... game/snake/SnakeTail.i"
	@echo "... game/snake/SnakeTail.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

