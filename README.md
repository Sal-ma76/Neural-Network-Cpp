## Overview

The project consists of the following main components:

- **src/ANN.h**: Header file containing class and function declarations for the neural network.
- **src/ANN.cpp**: Source file with the implementation of the neural network classes and methods.
- **src/main.cpp**: Contains the `main()` function, which runs the program.
- **CMakeLists.txt**: Configuration file for CMake, specifying the project name, required C++ standard, and source files to compile.
- **.gitignore**: Specifies files and directories that should be ignored by Git, including build directories and temporary files.

## Building the Project

To build the project, follow these steps:

1. Ensure you have CMake installed on your system.
2. Open a terminal and navigate to the project directory.
3. Create a build directory:
   ```
   mkdir build
   cd build
   ```
4. Run CMake to configure the project:
   ```
   cmake ..
   ```
5. Build the project:
   ```
   make
   ```

## Running the Project

After building, run the executable as before. The program will prompt you for network structure, input values, and weights.
