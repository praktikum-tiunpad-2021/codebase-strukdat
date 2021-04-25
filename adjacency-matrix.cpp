#include <iostream>
#include <vector>

using std::vector;

struct Node {
  int value;
  Node* next;
};

template <typename T>
using matrix = vector<vector<T>>;

using pointer = Node*;

struct Graph {
  matrix<int> adjMatrix;
} g;

void createNode(const int value) {
  pointer newNode = new Node;
  newNode->value = value;
  newNode->next = nullptr;
}

void createGraph(const int nodes, matrix<int>& edges) {
  g.adjMatrix = matrix<int>(nodes+1, vector<int>(nodes+1, 0));

  for(auto it = edges.begin(); it != edges.end(); ++it) {
    g.adjMatrix[(*it)[0]][(*it)[1]] = 1;
  }
}

void printAdjMatrix() {
  for(int i = 0; i < g.adjMatrix.size(); ++i) {
    if (i == 0) std::cout << "  ";
    else std::cout << i << " ";

    for(int j = 1; j < g.adjMatrix.size(); ++j) {
      if (i == 0)  std::cout << j << ' ';
      else std::cout << g.adjMatrix[i][j] << ' ';
    }
    std::cout << '\n';
  }
}

int main() {
  int nodes = 5;
  matrix<int> edges = {
    {1, 2}, {1, 4},
    {2, 1}, {2, 3}, {2, 5},
    {3, 2}, {3, 4}, {3, 5},
    {4, 1}, {4, 3},
    {5, 2}, {5, 3}
  };
  createGraph(nodes, edges);
  printAdjMatrix();
  return 0;
}
