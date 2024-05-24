/*
efiphi10@gmail.com
318591823 
*/

#include "Graph.hpp"
#include <sstream>
using namespace std;

namespace ariel {

// Constructor
Graph::Graph(int n) : size(n) {
    adjMatrix.resize(static_cast<size_t>(n), std::vector<int>(static_cast<size_t>(n), 0));
}

// Methods to manipulate the graph
void Graph::addEdge(int u, int v, int weight) {
    if (u >= size || v >= size || u < 0 || v < 0) {
        throw std::out_of_range("Invalid vertex index");
    }
    adjMatrix[static_cast<size_t>(u)][static_cast<size_t>(v)] = weight;
}

void Graph::removeEdge(int u, int v) {
    if (u >= size || v >= size || u < 0 || v < 0) {
        throw std::out_of_range("Invalid vertex index");
    }
    adjMatrix[static_cast<size_t>(u)][static_cast<size_t>(v)] = 0;
}

void Graph::display() const {
    for (const auto& row : adjMatrix) {
        for (const auto& val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

// Getter for adjacency matrix
const std::vector<std::vector<int>>& Graph::getAdjacencyMatrix() const {
    return adjMatrix;
}

// Method to load the graph
void Graph::loadGraph(const std::vector<std::vector<int>>& matrix) {
    size = static_cast<int>(matrix.size());
    adjMatrix = matrix;
}

// Print graph as a formatted string
std::string Graph::printGraph() const {
    std::ostringstream oss;
    for (const auto& row : adjMatrix) {
        for (const auto& val : row) {
            oss << val << " ";
        }
        oss << "\n";
    }
    return oss.str();
}

// Arithmetic Operators
Graph Graph::operator+(const Graph& other) const {
    if (size == 0 || other.size == 0) {
        throw std::invalid_argument("Cannot operate on empty graphs");
    }
    if (size != other.size) {
        throw std::invalid_argument("Graphs must be of the same size for addition");
    }
    Graph result(size);
    for (size_t i = 0; i < static_cast<size_t>(size); ++i) {
        for (size_t j = 0; j < static_cast<size_t>(size); ++j) {
            result.adjMatrix[i][j] = adjMatrix[i][j] + other.adjMatrix[i][j];
        }
    }
    return result;
}

Graph& Graph::operator+=(const Graph& other) {
    if (size == 0 || other.size == 0) {
        throw std::invalid_argument("Cannot operate on empty graphs");
    }
    if (size != other.size) {
        throw std::invalid_argument("Graphs must be of the same size for addition");
    }
    for (size_t i = 0; i < static_cast<size_t>(size); ++i) {
        for (size_t j = 0; j < static_cast<size_t>(size); ++j) {
            adjMatrix[i][j] += other.adjMatrix[i][j];
        }
    }
    return *this;
}


Graph Graph::operator-(const Graph& other) const {
    if (size == 0 || other.size == 0) {
        throw std::invalid_argument("Cannot operate on empty graphs");
    }
    if (size != other.size) {
        throw std::invalid_argument("Graphs must be of the same size for subtraction");
    }
    Graph result(size);
    for (size_t i = 0; i < static_cast<size_t>(size); ++i) {
        for (size_t j = 0; j < static_cast<size_t>(size); ++j) {
            result.adjMatrix[i][j] = adjMatrix[i][j] - other.adjMatrix[i][j];
        }
    }
    return result;
}

Graph& Graph::operator-=(const Graph& other) {
    if (size == 0 || other.size == 0) {
        throw std::invalid_argument("Cannot operate on empty graphs");
    }
    if (size != other.size) {
        throw std::invalid_argument("Graphs must be of the same size for subtraction");
    }
    for (size_t i = 0; i < static_cast<size_t>(size); ++i) {
        for (size_t j = 0; j < static_cast<size_t>(size); ++j) {
            adjMatrix[i][j] -= other.adjMatrix[i][j];
        }
    }
    return *this;
}


Graph Graph::operator+() const {
    return *this;
}

Graph Graph::operator-() const {
    Graph result(size);
    for (size_t i = 0; i < static_cast<size_t>(size); ++i) {
        for (size_t j = 0; j < static_cast<size_t>(size); ++j) {
            result.adjMatrix[i][j] = -adjMatrix[i][j];
        }
    }
    return result;
}

// Comparison Operators
bool Graph::operator==(const Graph& other) const {
    if (size != other.size) {
        return false;
    }
    for (size_t i = 0; i < static_cast<size_t>(size); ++i) {
        for (size_t j = 0; j < static_cast<size_t>(size); ++j) {
            if (adjMatrix[i][j] != other.adjMatrix[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool Graph::operator!=(const Graph& other) const {
    return !(*this == other);
}

bool Graph::operator<(const Graph& other) const {
    // Define comparison based on edge counts
    int thisEdgeCount = 0, otherEdgeCount = 0;
    for (const auto& row : adjMatrix) {
        for (const auto& val : row) {
            if (val != 0) ++thisEdgeCount;
        }
    }
    for (const auto& row : other.adjMatrix) {
        for (const auto& val : row) {
            if (val != 0) ++otherEdgeCount;
        }
    }
    return thisEdgeCount < otherEdgeCount;
}

bool Graph::operator>(const Graph& other) const {
    return other < *this;
}

bool Graph::operator<=(const Graph& other) const {
    return !(other < *this);
}

bool Graph::operator>=(const Graph& other) const {
    return !(*this < other);
}

// Increment/Decrement Operators
Graph& Graph::operator++() {
    for (auto& row : adjMatrix) {
        for (auto& val : row) {
            ++val;
        }
    }
    return *this;
}

Graph Graph::operator++(int) {
    Graph temp = *this;
    ++(*this);
    return temp;
}

Graph& Graph::operator--() {
    for (auto& row : adjMatrix) {
        for (auto& val : row) {
            --val;
        }
    }
    return *this;
}

Graph Graph::operator--(int) {
    Graph temp = *this;
    --(*this);
    return temp;
}

// Scalar Multiplication
Graph Graph::operator*(int scalar) const {
    Graph result(size);
    for (size_t i = 0; i < static_cast<size_t>(size); ++i) {
        for (size_t j = 0; j < static_cast<size_t>(size); ++j) {
            result.adjMatrix[i][j] = adjMatrix[i][j] * scalar;
        }
    }
    return result;
}

Graph& Graph::operator*=(int scalar) {
    for (size_t i = 0; i < static_cast<size_t>(size); ++i) {
        for (size_t j = 0; j < static_cast<size_t>(size); ++j) {
            adjMatrix[i][j] *= scalar;
        }
    }
    return *this;
}

// Graph Multiplication
Graph Graph::operator*(const Graph& other) const {
    if (size == 0 || other.size == 0) {
        throw std::invalid_argument("Cannot operate on empty graphs");
    }
    if (size != other.size) {
        throw std::invalid_argument("Graphs must be of the same size for multiplication");
    }
    Graph result(size);
    for (size_t i = 0; i < static_cast<size_t>(size); ++i) {
        for (size_t j = 0; j < static_cast<size_t>(size); ++j) {
            for (size_t k = 0; k < static_cast<size_t>(size); ++k) {
                result.adjMatrix[i][j] += adjMatrix[i][k] * other.adjMatrix[k][j];
            }
        }
    }
    return result;
}

// Output Operator
std::ostream& operator<<(std::ostream& os, const Graph& graph) {
    for (const auto& row : graph.adjMatrix) {
        for (const auto& val : row) {
            os << val << " ";
        }
        os << std::endl;
    }
    return os;
}

} // namespace ariel
