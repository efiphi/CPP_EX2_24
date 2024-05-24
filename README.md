# Graph and Algorithms Project
## Prerequisites

    C++ Compiler (GCC or Clang recommended)
    CMake
    Doctest for unit testing

## Overview

This project implements a graph representation using an adjacency matrix and supports various arithmetic and comparison operations on graphs. The graph class is designed to handle operations such as addition, subtraction, scalar multiplication, and comparisons.
Documentation
Files and Classes

    Graph.hpp / Graph.cpp: Manage the representation of graphs via an adjacency matrix. Includes methods for loading graphs, performing arithmetic operations, and comparing graphs.

    Makefile: Provides rules for compiling the project and associated utilities. It includes targets for building the project, cleaning up binaries, running tests, and more.

    Test.cpp: Includes unit tests for verifying the functionality of the graph operations. It uses the Doctest framework for test cases.

## Methods in Graph
### Construction and Initialization

    Graph(int n = 0): Constructs a graph with n vertices.
    void loadGraph(const std::vector<std::vector<int>>& matrix): Initializes the graph with a given adjacency matrix.
    std::string printGraph() const: Returns a string representation of the graph.

### Arithmetic Operators

    Graph operator+(const Graph& other) const: Adds two graphs.
    Graph& operator+=(const Graph& other): Adds another graph to the current graph.
    Graph operator-() const: Negates the graph.
    Graph operator-(const Graph& other) const: Subtracts one graph from another.
    Graph& operator-=(const Graph& other): Subtracts another graph from the current graph.
    Graph operator*(int scalar) const: Multiplies the graph by a scalar.
    Graph& operator*=(int scalar): Multiplies the current graph by a scalar.
    Graph operator*(const Graph& other) const: Multiplies two graphs (matrix multiplication).

### Comparison Operators

    bool operator==(const Graph& other) const: Checks if two graphs are equal.
    bool operator!=(const Graph& other) const: Checks if two graphs are not equal.
    bool operator<(const Graph& other) const: Checks if the current graph is less than another graph.
    bool operator>(const Graph& other) const: Checks if the current graph is greater than another graph.
    bool operator<=(const Graph& other) const: Checks if the current graph is less than or equal to another graph.
    bool operator>=(const Graph& other) const: Checks if the current graph is greater than or equal to another graph.

### Increment/Decrement Operators

    Graph& operator++(): Prefix increment.
    Graph operator++(int): Postfix increment.
    Graph& operator--(): Prefix decrement.
    Graph operator--(int): Postfix decrement.

## Usage

The provided Makefile includes several targets to facilitate building, testing, and running the project. Here's how you can use these commands:
Commands

### Makefile Commands:

    make: Compiles all the necessary .cpp files and links them to create the main executable(s) for the project. It ensures that all dependencies are up-to-date and builds any files that have changed since the last compilation.

    make run: After building the project using make, you can use this command to execute the main program. This is useful for demonstrating the functionalities implemented in the project, such as graph operations and algorithm demonstrations.

    make test: Compiles and runs the tests defined in Test.cpp. This command is essential for verifying the correctness of the graph operations. It uses the Doctest framework to execute and report on unit tests.

    make clean: Cleans up the project by removing all the compiled object files and executables. This is useful for ensuring that subsequent builds start from a clean state, which is crucial for avoiding issues caused by stale files.

### Specific Class Operations

Each class in the project serves a specific purpose:

    Graph class: Compiled and linked through the main executable when running simulations or demonstrations involving graph operations. It handles the creation, manipulation, and representation of graphs.

    Test classes (Test.cpp): Specifically used in the make test target to run unit tests on the functionalities provided by the Graph class.

## Example Usage

cpp

    #include "Graph.hpp"
    #include <iostream>

        int main() {
            ariel::Graph g1(3);
            std::vector<std::vector<int>> matrix = {
                {0, 1, 0},
                {1, 0, 1},
                {0, 1, 0}
            };
            g1.loadGraph(matrix);
            std::cout << "Graph g1:" << std::endl;
            std::cout << g1.printGraph() << std::endl;

            ariel::Graph g2 = g1 * 2;
            std::cout << "Graph g2 (g1 * 2):" << std::endl;
            std::cout << g2.printGraph() << std::endl;

            return 0;
        }



כמו כן, עליכם לכלול גם את הקובץ `Algorithms.cpp` מהמטלה הקודמת ולראות כיצד הפונקציות שהגדרתם בפעם הקודמת משתנות עכשיו. בנוסף לקבצים של המטלה אתם נדרשים להגיש גם קובץ README המתאר את אופן המימוש ואת החלוקה שביצעתם בקוד (סוג של מדריך משתמש).
עליכם לכתוב בתחילת כל קובץ את מספר תעודת הזהות שלכם ואת המייל. אי עמידה בהנחיות תגרור הפחתה בציון.
בהצלחה!

