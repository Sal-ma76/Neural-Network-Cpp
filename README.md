# C++ Neural Network

This project implements a simple artificial neural network (ANN) in C++. It includes classes for neurons and the network itself, allowing for the creation, training, and evaluation of a neural network.

## Overview

The project consists of the following main components:

- **src/ANN.cpp**: Contains the implementation of the neural network. It defines the `Neuron` class, which includes methods for setting output values, computing outputs based on inputs from the previous layer, and managing weights. The `Net` class manages layers of neurons, initializes the network, feeds forward inputs, and prints results.

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

After building the project, you can run the neural network executable. The program will prompt you to enter the number of layers, the number of neurons in each layer, input values for the first layer, and weights for the connections between neurons.

## Contributing

Contributions are welcome! Please feel free to submit a pull request or open an issue for any suggestions or improvements.

## License

This project is licensed under the MIT License. See the LICENSE file for more details.