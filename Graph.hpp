/*
efiphi10@gmail.com
318591823
*/

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
#include <stdexcept>
#include <sstream>

namespace ariel {

class Graph {
private:
    std::vector<std::vector<int>> adjMatrix;
    int size;

public:
    // Constructor
    Graph(int n = 0);

    // Methods to manipulate the graph
    void addEdge(int u, int v, int weight);
    void removeEdge(int u, int v);
    void display() const;
    const std::vector<std::vector<int>>& getAdjacencyMatrix() const;
    std::string printGraph() const;

    // Method to load the graph
    void loadGraph(const std::vector<std::vector<int>>& matrix);

    // Arithmetic Operators
    Graph operator+(const Graph& other) const;
    Graph& operator+=(const Graph& other);
    Graph operator-(const Graph& other) const;
    Graph& operator-=(const Graph& other);
    Graph operator+() const;
    Graph operator-() const;

    //multiplication operators
    Graph operator*(int scalar) const;
    Graph& operator*=(int scalar);
    Graph operator*(const Graph& other) const;


    // Comparison Operators
    bool operator==(const Graph& other) const;
    bool operator!=(const Graph& other) const;
    bool operator<(const Graph& other) const;
    bool operator>(const Graph& other) const;
    bool operator<=(const Graph& other) const;
    bool operator>=(const Graph& other) const;

    // Increment/Decrement Operators
    Graph& operator++();    // Prefix increment
    Graph operator++(int);  // Postfix increment
    Graph& operator--();    // Prefix decrement
    Graph operator--(int);  // Postfix decrement

    // Output Operator
    friend std::ostream& operator<<(std::ostream& os, const Graph& graph);
};

} // namespace ariel

#endif // GRAPH_HPP
