---------------- G A M E   O F   L I F E ----------------


This is a readme file for programming languages project.

Repository contains source code (written in C) for Conway's Game of Life (Projekt.c), README.txt, and config.txt (file with values of parametres used in program).

1. What is "Game of Life"?
"The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970.
The game is a zero-player game, meaning that its evolution is determined by its initial state, requiring no further input.
One interacts with the Game of Life by creating an initial configuration and observing how it evolves, or, for advanced players, by creating patterns with particular properties (via Wikipedia).

	Rules:
1. Any living cell with 2 or 3 living neighbours stays alive (ah, ah, ah, ah...) in next step.
2. Living cells with less than 2 or more than 3 living neighbours dies in next step.
3. Any dead cell with exactly 3 living neighbours becomes a living cell.

Game takes place on two-dimensional array, consisting of dead or alive cells.

2. Program.
The game's place consist of two-dimensional array, which size is determined by user, via config.txt.
Initial number of living cells is also determined by user via config.txt.
Positions of that cells on game's array is determined by pseudo-random numbers generated within program.
After every second, the program puts actual state of array to standard output, number of current step, number of dead and living cells.
The last 3 values are written to the "data.dat" file in every step.
The game ends when state within becomes balanced (there are no changes in placement of cells), after previously determined number of steps (via config.txt) or on user's demand.

3. config.txt file.
The config.txt file contains values of simulation parametres. The following parametres are:
height - height of array
width - width of array (what a suprise...)
cells - initial number of living cells, deployed on array
iterations - number of steps made by the game before it stops
question - number of steps after which game will be asking about continuing or aborting simulation.

4. How to run?
"Projekt.c" is the file containing source code of this cellular automaton. It was written in C programming language.
To use this program you have to compile it first. The author used TGM-GCC 4.9.2 64-bit release (which he also reccomends for this code) implemented in Bloodshed Dev-C++ enviroment for Windows.

5. Errors.
Properly working program should return 0 value if the game finishes.
Returned value 1 means error connected with file managament, probably there's no config file in catalogue, which must be in catalogue with program.
Other predicted errors might be caused by setting invalid parametres (e.g. negative size of array or more living cells, than array can contain).

6. Author.
Bartłomiej Sokołowski
bartlomiej_sokolowski@poczta.pl
https://github.com/Falco-Subbuteo
+48 693 380 593



