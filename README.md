# Game of Life

## Overview
The Game of Life is a cellular automaton devised by the mathematician John Conway. It consists of a grid of cells that evolve over time based on specific rules. This program implements the Game of Life and provides functionality to read an initial configuration from a file, evolve the grid for a given number of generations, and write the final configuration to an output file.

## Code Structure
The code is organized into multiple files:

- gameoflife.c: This file contains the main function and the program's entry point. It includes the necessary headers and defines the main function, which is responsible for reading command-line arguments, initializing the universe, evolving the grid, and writing the final configuration to an output file.

- gol.c and gol.h: These files contain the implementation and declaration of various functions related to the Game of Life. Functions in these files handle reading the input file, evolving the grid, determining if a cell is alive, and writing the output file. The struct universe is also defined here, which represents the game grid and holds necessary information about the grid's dimensions, cell states, and pointers to related objects.

## Usage
To compile and run the program, follow these steps:

1. Ensure that you have the necessary dependencies, including a C compiler and the required libraries.
2. Compile the program by executing the following command in the terminal:

```c 
gcc -o gameoflife gameoflife.c gol.c
```
3. Run the program by executing the following command:

```c
./gameoflife [options]
```
Replace [options] with the desired command-line arguments. The program accepts various options to specify the input file, output file, number of generations, and other settings.

4. The program will read the input file, evolve the grid for the specified number of generations, and write the final configuration to the output file.

## Command-line Arguments
The program accepts several command-line arguments to customize its behavior. Here are the available options:

- ```i <input_file>```: Specifies the input file containing the initial configuration of the grid.
- ```o <output_file>```: Specifies the output file to which the final configuration will be written.
- ```g <num_generations>```: Specifies the number of generations to evolve the grid (default is 5).
- ```s```: Enables printing statistics about the grid after evolution.
- ```t```: Enables using toroidal (wrap-around) boundary conditions during evolution.

## Makefile
The provided Makefile simplifies the compilation and cleaning process. The following commands are available:

- ```make```: Compiles the program and generates the executable file gameoflife.
- ```make clean```: Removes all object files and the executable.

## Additional Notes
- Some parts of the code are currently commented out. These sections are related to command-line argument parsing and the evolution loop. You may need to uncomment and modify them according to your requirements.
- This README assumes that you have the required dependencies and a basic understanding of how to compile and run C programs. If you encounter any issues, please consult the documentation or resources related to your specific development environment.

That's it! You should now have a general understanding of the code and how to use it to simulate the Game of Life. Feel free to explore the code further and make modifications as needed.
