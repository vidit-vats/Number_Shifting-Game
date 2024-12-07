# Number-Shifting-Game

## Game Description

The game involves a 4x4 matrix with random initial values that needs to be transformed into a specific ordered matrix.

### Initial Matrix Example

```
Initial Matrix with scattered numbers 1 to 15 in any random order.
```

### Target Matrix

```
1   2   3   4
5   6   7   8
9  10  11  12
13 14  15  (empty space)
```

## Game Rules

1. Players can move only 1 step at a time using arrow keys.
2. Numbers can only be moved to an empty position.
3. Each valid move decreases the total number of available moves.

## Winning Condition

The matrix must be arranged in order from 1 to 15, with the final position being an empty space.

## Gameplay
* A Welcome Screen will be prompted when the program is compiled and run.
  
* All Instructions/rules regarding the game will be displayed on the prompt itself before starting the game.

* Player is allowed to use ⬆,⬇,⬅,➡ keys to move numbers.
  
* Pressing 'g' will start the game.
* New Position of the 'Blank Space' and the No of moves left will be continuously printed onto the terminal prompt until game is not over.

## Compiling the Program
Type ```cc welcome.c main.c -lncurses``` OR ```cc -o name_of_executable welcome.c main.c -lncurses```

This will create a target executable ```a.out``` OR ```name_of_executable``` on a Unix Based Systems like Linux or Mac. To run it, simple type: ```./a.out``` OR ```./name_of_executable```
