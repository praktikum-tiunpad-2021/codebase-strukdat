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
  matrix<int> adjList;
} g;

void createNode(const int value) {
  pointer newNode = new Node;
  newNode->value = value;
  newNode->next = nullptr;
}

void createGraph(const int nodes, matrix<int>& edges) {
  g.adjList = matrix<int>(nodes+1);

  for(auto it = edges.begin(); it != edges.end(); ++it) {
    g.adjList[(*it)[0]].push_back((*it)[1]);
  }
}

void printAdjList() {
  for(int i = 1; i < g.adjList.size(); ++i) {
    std::cout << i << " | ";
    for(auto iter = g.adjList[i].begin(); iter < g.adjList[i].end(); ++iter)
      std::cout << *iter << ' ';
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
  printAdjList();
  return 0;
}
