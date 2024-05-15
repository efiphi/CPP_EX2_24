#include "Graph.hpp"
#include <iostream>
#include <vector>

int main() {
    std::vector<std::vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };

    std::vector<std::vector<int>> weightedGraph = {
        {0, 2, 0},
        {2, 0, 3},
        {0, 3, 0}
    };

    // Initialize graph with a specific size
    ariel::Graph g1(3);
    g1.loadGraph(graph); // Load the graph to the object.

    ariel::Graph g2(3);
    g2.loadGraph(weightedGraph); // Load the graph to the object.

    std::cout << "Graph g1:\n" << g1 << std::endl;
    std::cout << "Graph g2:\n" << g2 << std::endl;

    ariel::Graph g3 = g1 + g2;
    std::cout << "Graph g3 (g1 + g2):\n" << g3 << std::endl;

    ariel::Graph g4 = g1 * g2;
    std::cout << "Graph g4 (g1 * g2):\n" << g4 << std::endl;

    ++g1;
    std::cout << "Graph g1 after increment:\n" << g1 << std::endl;

    return 0;
}
