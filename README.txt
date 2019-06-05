---------------- G A M E   O F   L I F E ----------------


This is a readme file for programming languages project.

Repository contains source code (written in C) for Conway's Game of Life.

1. What is "Game of Life"?

"The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970.
The game is a zero-player game, meaning that its evolution is determined by its initial state, requiring no further input.
One interacts with the Game of Life by creating an initial configuration and observing how it evolves, or, for advanced players, by creating patterns with particular properties (via Wikipedia).

	Rules:
1. Any living cell with 2 or 3 living neighbours stays alive (ah, ah, ah, ah...) in next step.
2. Living cells with less than 2 or more than 3 living neighbours dies in next step.
3. Any Dead cell with exactly 3 living neighbours becomes a living cell.

Game takes place on two-dimensional place, consisting of dead or alive cells.

2. Program.
The game's place consist of two-dimensional array, which size is determined by user, via config.dat //TODO
Initial number of living cells is also determined by user via config.dat. //TODO
Positions of that cells on game's array is determined by pseudo-random numbers generated within program.
After every second, the program puts actual state of array to standard output. Also in every state
number of current step, number of dead and living cells is written to the "output.dat" file.
The game ends when state within becomes balanced (there are no changes in placement of cells),
or by user's demand. //TODO 

3. Author.
Bartłomiej Sokołowski
bartlomiej_sokolowski@poczta.pl
https://github.com/Falco-Subbuteo
+48 693 380 593



