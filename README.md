# Nitro C++ Proficiency Test

This project is a C++ program that reads a JSON file containing rectangle definitions, computes their intersections, and outputs the results. The program is designed to be easy to build and run, with support for unit testing using Google Test.

## Table of Contents
- [Requirements](#requirements)
- [Building the Program](#building-the-program)
- [Running the Program](#running-the-program)
- [Running Unit Tests](#running-unit-tests)
- [Project Structure](#project-structure)

## Requirements

To build and run this project, you need the following:

- **C++ Compiler:** GCC (G++) or Clang with C++17 support.
- **Build System:** `make` (for Unix-like systems) or `mingw32-make` (for Windows).
- **Google Test:** Required for running unit tests. You can download it from the [Google Test GitHub repository](https://github.com/google/googletest).
- **JSON Library:** The program uses the `nlohmann/json` library, which is included as a single header file in the `include/` directory.

## Building the Program

### Step 1: Clone the Repository

Clone the repository to your local machine:

```bash 
git clone https://github.com/ahmedelmenshawy1/NitroCppTest-ahmed.git
cd NitroCppTest-ahmed
```

### Step 2: Build the Program

This project uses a Makefile for building. To compile and run the program, execute the following command:

```bash

make build_run
```

This command will:

    1-Compile the source files.
    2-Link the object files into an executable (nitroTask.exe).
    3-Run the program with a sample JSON input file.

## Running the Program

After building the program, you can run it with a JSON file as input:
```bash

nitroTask.exe input.json
```

## Running Unit Tests

The project includes unit tests for the Rectangle and RectangleIntersection classes. To run the tests, follow these steps:

### Build and Run Tests

Run the following command to build and execute the unit tests:
```bash

make test

```
This will:

    1-Compile the unit test files.
    2-Link them with Google Test.
    3-Run the tests and display the results.

### Project Structure

The project is organized as follows:
```graphql

NitroCppTest-ahmed
├── include/                  # Header files
│   ├── Rectangle.h
│   ├── RectangleIntersection.h
│   └── json.hpp              # nlohmann/json library
├── src/                      # Source files
│   ├── main.cpp
│   ├── Rectangle.cpp
│   └── RectangleIntersection.cpp
├── unit_test/                # Unit test files
│   └── test_rectangle_intersection.cpp
│   └── test_rectangle.cpp
├── Makefile                  # Build script
└── test.json                # Sample input file
└── README.md this file
└── C___Proficiency_test_-_Updated.pdf pdf task
```


## How Easy Is It to Build?

The program is designed to be easy to build and run:

- **Single Command Build:** The Makefile allows you to build and run the program with a single command:  
  ```bash
  make build_run
  ```
- **Unit Testing:** Unit tests can be run with a single command:
  
  ```bash
  make test
  ```