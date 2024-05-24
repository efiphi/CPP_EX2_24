/*
efiphi10@gmail.com
318591823 
*/

#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "Graph.hpp"
#include <set>
#include <sstream>
#include <vector>

namespace ariel {
    class Algorithms {
    public:
        static bool isConnected(const Graph &g);
        static std::vector<int>* shortestPath(const ariel::Graph& g, size_t start, size_t end);
        static std::vector<int> isContainsCycle(const ariel::Graph& g);
        static std::vector<std::set<int>> isBipartite(const Graph&);
        static void negativeCycle(const ariel::Graph& g);

        static std::string shortestPathToString(const std::vector<int>* shortestPath);
        static std::string cycleToString(const std::vector<int>&);
        static std::string bipartiteGraphToString(const std::vector<std::set<int>>&);
        static bool directedCycleDFS(const std::vector<std::vector<int>>& graph, int v, std::vector<bool>& visited, std::vector<bool>& onStack, std::vector<int>& cycle);
        static bool unDirectedCycleDFS(const std::vector<std::vector<int>>& graph, int v, int parent, std::vector<bool>& visited, std::vector<int>& cycle);
        static bool isSymmetric(const std::vector<std::vector<int>>& adjacencyMatrix);
        static void printMatrix(const std::vector<std::vector<int>>& );
        static std::string trim(const std::string& str);

    };
};

#endif // ALGORITHMS_HPP