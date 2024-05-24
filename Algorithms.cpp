/*
efiphi10@gmail.com
318591823 
*/

#include "Algorithms.hpp"
#include "Graph.hpp"
#include <queue>
#include <vector>
#include <limits>
#include <algorithm>
#include <iostream>
#include <functional>
#include <set>
#include <sstream>

namespace ariel
{

bool Algorithms::isConnected(const Graph &g)
{
    const auto &matrix = g.getAdjacencyMatrix();
    std::size_t numVertices = matrix.size();
    std::vector<bool> visited(numVertices, false);
    std::queue<std::size_t> queue;

    // Start BFS from the first vertex
    visited[0] = true;
    queue.push(0);

    size_t visitedCount = 1;

    while (!queue.empty())
    {
        std::size_t current = queue.front();
        queue.pop();

        for (std::size_t j = 0; j < numVertices; ++j)
        {
            if (matrix[current][j] != 0 && !visited[j])
            {
                visited[j] = true;
                queue.push(j);
                visitedCount++;
            }
        }
    }

    return visitedCount == numVertices;
}

std::vector<int> *Algorithms::shortestPath(const Graph &g, size_t start, size_t end)
{
    const auto &matrix = g.getAdjacencyMatrix();
    std::size_t numVertices = matrix.size();
    std::vector<int> dist(numVertices, std::numeric_limits<int>::max());
    std::vector<int> previous(numVertices, -1);
    std::vector<bool> visited(numVertices, false);

    dist[start] = 0;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    pq.emplace(0, start);

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        if (visited[static_cast<size_t>(u)])
            continue;
        visited[static_cast<size_t>(u)] = true;

        for (size_t v = 0; v < numVertices; ++v)
        {
            if (matrix[static_cast<size_t>(u)][v] != 0 && !visited[v])
            {
                int alt = dist[static_cast<size_t>(u)] + matrix[static_cast<size_t>(u)][v];
                if (alt < dist[v])
                {
                    dist[v] = alt;
                    previous[v] = u;
                    pq.emplace(dist[v], static_cast<int>(v));
                }
            }
        }
    }

    if (dist[end] == std::numeric_limits<int>::max())
    {
        return nullptr; // No path found
    }

    std::vector<int> *path = new std::vector<int>();
    for (int at = static_cast<int>(end); at != -1; at = previous[static_cast<size_t>(at)])
    {
        path->push_back(at);
    }
    std::reverse(path->begin(), path->end());

    return path;
}

std::vector<int> Algorithms::isContainsCycle(const Graph &g)
{
    const auto &matrix = g.getAdjacencyMatrix();
    std::vector<bool> visited(matrix.size(), false);
    std::vector<bool> onStack(matrix.size(), false);
    std::vector<int> cycle;

    for (size_t i = 0; i < matrix.size(); ++i)
    {
        if (!visited[i])
        {
            if (isSymmetric(matrix) && unDirectedCycleDFS(matrix, static_cast<int>(i), -1, visited, cycle))
            {
                break;
            }
            else if (directedCycleDFS(matrix, static_cast<int>(i), visited, onStack, cycle))
            {
                break;
            }
        }
    }

    return cycle; // Will be empty if no cycle is found
}

std::vector<std::set<int>> Algorithms::isBipartite(const Graph &g)
{
    const auto &matrix = g.getAdjacencyMatrix();
    size_t numVertices = matrix.size();
    std::vector<int> color(numVertices, -1);
    std::vector<std::set<int>> sets(2);

    std::function<bool(int)> bfs = [&](int s)
    {
        std::queue<int> q;
        q.push(s);
        color[static_cast<size_t>(s)] = 0;
        sets[0].insert(s);

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (size_t v = 0; v < numVertices; ++v)
            {
                if (matrix[static_cast<size_t>(u)][v] != 0 && color[v] == -1)
                {
                    color[v] = 1 - color[static_cast<size_t>(u)];
                    sets[static_cast<size_t>(color[v])].insert(static_cast<int>(v));
                    q.push(static_cast<int>(v));
                }
                else if (matrix[static_cast<size_t>(u)][v] != 0 && color[v] == color[static_cast<size_t>(u)])
                {
                    return false;
                }
            }
        }
        return true;
    };

    for (size_t i = 0; i < numVertices; ++i)
    {
        if (color[i] == -1 && !bfs(static_cast<int>(i)))
            return {};
    }
    return sets;
}

void Algorithms::negativeCycle(const Graph &g)
{
    const auto &matrix = g.getAdjacencyMatrix();
    size_t numVertices = matrix.size();
    std::vector<std::vector<int>> dist = matrix;

    for (size_t i = 0; i < numVertices; ++i)
    {
        for (size_t u = 0; u < numVertices; ++u)
        {
            for (size_t v = 0; v < numVertices; ++v)
            {
                if (dist[u][i] + dist[i][v] < dist[u][v] && dist[u][i] != std::numeric_limits<int>::max() && dist[i][v] != std::numeric_limits<int>::max())
                {
                    if (!isSymmetric(matrix))
                    {
                        dist[u][v] = dist[u][i] + dist[i][v];
                    }
                    else
                    {
                        if (matrix[u][v] != 0 && dist[u][v] != std::numeric_limits<int>::max() && dist[u][v] + matrix[u][v] < dist[u][v])
                        {
                            dist[u][v] = dist[u][v] + matrix[u][v];

                            if (i == numVertices - 1 && dist[u][v] < 0)
                            {
                                std::cout << "Negative cycle detected!" << std::endl;
                                return;
                            }
                        }
                    }
                }
            }
        }
    }
    for (size_t j = 0; j < numVertices; ++j)
    {
        if (dist[j][j] < 0)
        {
            std::cout << "Negative cycle detected!" << std::endl;
            return;
        }
    }
    std::cout << "No negative cycle detected!" << std::endl;
}

std::string Algorithms::shortestPathToString(const std::vector<int> *shortestPath)
{
    if (!shortestPath)
        return "No path";
    std::ostringstream oss;
    for (size_t i = 0; i < shortestPath->size(); ++i)
    {
        if (i > 0)
            oss << "->";
        oss << (*shortestPath)[i];
    }
    return oss.str();
}

std::string Algorithms::cycleToString(const std::vector<int> &cycleNodes)
{
    std::ostringstream oss;
    if (cycleNodes.empty())
    {
        oss << "No cycle found";
        return oss.str();
    }
    else
    {
        for (size_t i = 0; i < cycleNodes.size(); ++i)
        {
            if (i > 0)
                oss << "->";
            oss << cycleNodes[i];
        }
    }
    return trim(oss.str());
}

std::string Algorithms::bipartiteGraphToString(const std::vector<std::set<int>> &sets)
{
    std::ostringstream oss;
    if (sets.empty())
    {
        oss << "Graph is not bipartite" << std::endl;
        return oss.str();
    }
    for (const auto &set : sets)
    {
        oss << "{ ";
        for (int v : set)
        {
            oss << v << " ";
        }
        oss << "} ";
    }
    return trim(oss.str());
}

bool Algorithms::directedCycleDFS(const std::vector<std::vector<int>> &graph, int v, std::vector<bool> &visited, std::vector<bool> &onStack, std::vector<int> &cycle)
{
    visited[static_cast<size_t>(v)] = true;
    onStack[static_cast<size_t>(v)] = true;

    for (size_t i = 0; i < graph[static_cast<size_t>(v)].size(); ++i)
    {
        if (graph[static_cast<size_t>(v)][i] > 0)
        { // Check for an edge
            if (!visited[i])
            {
                if (directedCycleDFS(graph, static_cast<int>(i), visited, onStack, cycle))
                {
                    if (cycle.empty() || cycle.front() != v)
                    {
                        cycle.push_back(v); // Building the cycle path
                        if (i == static_cast<size_t>(cycle.front()))
                            return true; // End cycle if back to start
                    }
                    return true;
                }
            }
            else if (onStack[i])
            {
                cycle.push_back(static_cast<int>(i)); // Start the cycle path
                cycle.push_back(v);                   // Add current node to the cycle
                return true;
            }
        }
    }

    onStack[static_cast<size_t>(v)] = false; // Backtrack: unmark the current vertex
    return false;
}

bool Algorithms::unDirectedCycleDFS(const std::vector<std::vector<int>> &graph, int v, int parent, std::vector<bool> &visited, std::vector<int> &cycle)
{
    visited[static_cast<size_t>(v)] = true;
    cycle.push_back(v); // Assume v is part of the cycle initially

    for (size_t i = 0; i < graph[static_cast<size_t>(v)].size(); ++i)
    {
        if (graph[static_cast<size_t>(v)][i] > 0 && static_cast<int>(i) != parent)
        { // Check for an edge, ensuring it's not the parent
            if (!visited[i])
            {
                if (unDirectedCycleDFS(graph, static_cast<int>(i), v, visited, cycle))
                {
                    return true;
                }
            }
            else
            {
                cycle.push_back(static_cast<int>(i)); // Close the cycle
                return true;
            }
        }
    }

    cycle.pop_back(); // Backtrack if no cycle found via v
    return false;
}

bool Algorithms::isSymmetric(const std::vector<std::vector<int>> &adjacencyMatrix)
{
    for (size_t i = 0; i < adjacencyMatrix.size(); ++i)
    {
        for (size_t j = 0; j < i; ++j)
        {
            if (adjacencyMatrix[i][j] != adjacencyMatrix[j][i])
            {
                return false;
            }
        }
    }
    return true;
}

void Algorithms::printMatrix(const std::vector<std::vector<int>> &matrix)
{
    for (const auto &row : matrix)
    {
        for (int val : row)
        {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

std::string Algorithms::trim(const std::string &str)
{
    size_t first = str.find_first_not_of(' ');
    if (std::string::npos == first)
    {
        return str;
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

} // namespace ariel
