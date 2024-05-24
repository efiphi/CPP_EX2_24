/*
efiphi10@gmail.com
318591823 
*/

#include "doctest.h"
#include "Graph.hpp"
#include <vector>

using namespace std;

TEST_CASE("Test graph addition operator") {
    ariel::Graph g1(3);
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph1);

    ariel::Graph g2(3);
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}
    };
    g2.loadGraph(graph2);

    ariel::Graph g3 = g1 + g2;
    CHECK(g3.printGraph() == "0 2 1 \n2 0 3 \n1 3 0 \n");
}

TEST_CASE("Test graph addition assignment operator") {
    ariel::Graph g1(3);
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph1);

    ariel::Graph g2(3);
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}
    };
    g2.loadGraph(graph2);

    g1 += g2;
    CHECK(g1.printGraph() == "0 2 1 \n2 0 3 \n1 3 0 \n");
}

TEST_CASE("Test unary plus operator") {
    ariel::Graph g1(3);
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph1);

    ariel::Graph g2 = +g1;
    CHECK(g2.printGraph() == "0 1 0 \n1 0 1 \n0 1 0 \n");
}

TEST_CASE("Test graph subtraction operator") {
    ariel::Graph g1(3);
    vector<vector<int>> graph1 = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}
    };
    g1.loadGraph(graph1);

    ariel::Graph g2(3);
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}
    };
    g2.loadGraph(graph2);

    ariel::Graph g3 = g1 - g2;
    CHECK(g3.printGraph() == "0 1 0 \n1 0 1 \n0 1 0 \n");
}

TEST_CASE("Test graph subtraction assignment operator") {
    ariel::Graph g1(3);
    vector<vector<int>> graph1 = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}
    };
    g1.loadGraph(graph1);

    ariel::Graph g2(3);
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}
    };
    g2.loadGraph(graph2);

    g1 -= g2;
    CHECK(g1.printGraph() == "0 1 0 \n1 0 1 \n0 1 0 \n");
}

TEST_CASE("Test unary minus operator") {
    ariel::Graph g1(3);
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph1);

    ariel::Graph g2 = -g1;
    CHECK(g2.printGraph() == "0 -1 0 \n-1 0 -1 \n0 -1 0 \n");
}

TEST_CASE("Test equality operator") {
    ariel::Graph g1(3);
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph1);

    ariel::Graph g2(3);
    g2.loadGraph(graph1);

    CHECK(g1 == g2);
}

TEST_CASE("Test inequality operator") {
    ariel::Graph g1(3);
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph1);

    ariel::Graph g2(3);
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}
    };
    g2.loadGraph(graph2);

    CHECK(g1 != g2);
}

TEST_CASE("Test greater than operator") {
    ariel::Graph g1(3);
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph1);

    ariel::Graph g2(3);
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}
    };
    g2.loadGraph(graph2);

    CHECK(g2 > g1);
}

TEST_CASE("Test greater than or equal operator") {
    ariel::Graph g1(3);
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph1);

    ariel::Graph g2(3);
    g2.loadGraph(graph1);

    ariel::Graph g3(3);
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}
    };
    g3.loadGraph(graph2);

    CHECK(g2 >= g1);
    CHECK(g3 >= g1);
}

TEST_CASE("Test less than operator") {
    ariel::Graph g1(3);
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph1);

    ariel::Graph g2(3);
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}
    };
    g2.loadGraph(graph2);

    CHECK(g1 < g2);
}

TEST_CASE("Test less than or equal operator") {
    ariel::Graph g1(3);
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph1);

    ariel::Graph g2(3);
    g2.loadGraph(graph1);

    ariel::Graph g3(3);
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}
    };
    g3.loadGraph(graph2);

    CHECK(g1 <= g2);
    CHECK(g1 <= g3);
}

TEST_CASE("Test increment operators") {
    ariel::Graph g1(3);
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph1);

    ++g1;
    CHECK(g1.printGraph() == "1 2 1 \n2 1 2 \n1 2 1 \n");

    g1++;
    CHECK(g1.printGraph() == "2 3 2 \n3 2 3 \n2 3 2 \n");
}

TEST_CASE("Test decrement operators") {
    ariel::Graph g1(3);
    vector<vector<int>> graph1 = {
        {2, 3, 2},
        {3, 2, 3},
        {2, 3, 2}
    };
    g1.loadGraph(graph1);

    --g1;
    CHECK(g1.printGraph() == "1 2 1 \n2 1 2 \n1 2 1 \n");

    g1--;
    CHECK(g1.printGraph() == "0 1 0 \n1 0 1 \n0 1 0 \n");
}

TEST_CASE("Test scalar multiplication") {
    ariel::Graph g1(3);
    vector<vector<int>> graph1 = {
        {1, 2, 1},
        {2, 1, 2},
        {1, 2, 1}
    };
    g1.loadGraph(graph1);

    ariel::Graph g2 = g1 * 2;
    CHECK(g2.printGraph() == "2 4 2 \n4 2 4 \n2 4 2 \n");

    g1 *= 3;
    CHECK(g1.printGraph() == "3 6 3 \n6 3 6 \n3 6 3 \n");
}

TEST_CASE("Test graph multiplication operator1") {
    ariel::Graph g1(3);
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph1);

    ariel::Graph g2(3);
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}
    };
    g2.loadGraph(graph2);

    ariel::Graph g3 = g1 * g2;
    CHECK(g3.printGraph() == "1 0 2 \n1 3 1 \n1 0 2 \n");
}

TEST_CASE("Test graph multiplication operator2") {
    ariel::Graph g1(3);
    vector<vector<int>> graph1 = {
        {1, 0, 0},
        {2, 0, 1},
        {3, 5, 4}
    };
    g1.loadGraph(graph1);

    ariel::Graph g2(3);
    vector<vector<int>> graph2 = {
        {0, 0, 0},
        {2, 5, 8},
        {3, 2, 1}
    };
    g2.loadGraph(graph2);

    ariel::Graph g3 = g1 * g2;
    CHECK(g3.printGraph() == "0 0 0 \n3 2 1 \n22 33 44 \n");
}

TEST_CASE("Attempting to multiply graphs of different sizes") {
    ariel::Graph g1(2);
    vector<vector<int>> graph1 = {
        {0, 1},
        {1, 0}
    };
    g1.loadGraph(graph1);

    ariel::Graph g2(3);
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}
    };
    g2.loadGraph(graph2);

    CHECK_THROWS(g1 * g2);
}

TEST_CASE("Multiplication involving a graph with zero edges") {
    ariel::Graph g1(3);
    vector<vector<int>> graph1 = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    g1.loadGraph(graph1);

    ariel::Graph g2(3);
    vector<vector<int>> graph2 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    g2.loadGraph(graph2);

    ariel::Graph g3 = g1 * g2;
    vector<vector<int>> expectedGraph = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    CHECK(g3.printGraph() == "0 0 0 \n0 0 0 \n0 0 0 \n");
}

TEST_CASE("Edge case: Empty graph") {
    ariel::Graph g1(0);
    CHECK(g1.printGraph() == "");

    ariel::Graph g2(0);
    CHECK_THROWS(g1 + g2);
    CHECK_THROWS(g1 * g2);
}

TEST_CASE("Edge case: Single node graph") {
    ariel::Graph g1(1);
    vector<vector<int>> graph1 = {{0}};
    g1.loadGraph(graph1);
    CHECK(g1.printGraph() == "0 \n");

    ariel::Graph g2(1);
    vector<vector<int>> graph2 = {{2}};
    g2.loadGraph(graph2);
    ariel::Graph g3 = g1 + g2;
    CHECK(g3.printGraph() == "2 \n");

    ariel::Graph g4 = g1 * g2;
    CHECK(g4.printGraph() == "0 \n");
}

TEST_CASE("Edge case: Graph with self-loops") {
    ariel::Graph g1(3);
    vector<vector<int>> graph1 = {
        {1, 1, 0},
        {1, 1, 1},
        {0, 1, 1}
    };
    g1.loadGraph(graph1);
    CHECK(g1.printGraph() == "1 1 0 \n1 1 1 \n0 1 1 \n");

    ariel::Graph g2 = g1 * 2;
    CHECK(g2.printGraph() == "2 2 0 \n2 2 2 \n0 2 2 \n");
}

