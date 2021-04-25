#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;

template <typename T>
using matrix = vector<vector<T>>;

struct Node {
  int value;
  Node* next;
};

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

void addNode(const int node) {
  if (g.adjList[node].empty()) {
    g.adjList.resize(node+1);
  }
}

void deleteNode(const int node) {
  if (!g.adjList[node].empty()) {
    g.adjList[node].clear();

    for(int i = 1; i < g.adjList.size(); ++i) {
      if (g.adjList[i].empty()) continue;

      auto it = std::find(g.adjList[i].begin(),
                          g.adjList[i].end(),
                          node);
      if (it != g.adjList[i].end()) {
        g.adjList[i].erase(it);
      }
    }
  }
}

void addEdge(const int node1, const int node2) {
  vector<int> &adj1 = g.adjList[node1],
              &adj2 = g.adjList[node2];

  auto it = std::find(adj1.begin(), adj1.end(), node2);
  if (it == adj1.end()) {
    adj1.push_back(node2);
    std::sort(adj1.begin(), adj1.end());
  }

  it = std::find(adj2.begin(), adj2.end(), node1);
  if (it == adj2.end()) {
    adj2.push_back(node1);
    std::sort(adj2.begin(), adj2.end());
  }
}

void deleteEdge(const int node1, const int node2) {
  vector<int> &adj1 = g.adjList[node1],
              &adj2 = g.adjList[node2];

  auto it = std::find(adj1.begin(), adj1.end(), node2);
  if (it != adj1.end()) {
    adj1.erase(it);
  }

  it = std::find(adj2.begin(), adj2.end(), node1);
  if (it != adj2.end()) {
    adj2.erase(it);
  }
}

void printAdjList() {
  for(int i = 1; i < g.adjList.size(); ++i) {
    if (g.adjList[i].empty()) continue;
    std::cout << i << " | ";
    for(auto it = g.adjList[i].begin();
        it < g.adjList[i].end();
        ++it) {
      std::cout << *it << ' ';
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
  printAdjList();
  std::cout << "------\n";
  deleteNode(4);
  printAdjList();
  std::cout << "------\n";
  addEdge(1, 5);
  printAdjList();
  std::cout << "------\n";
  addNode(8);
  addEdge(3, 8);
  printAdjList();
  return 0;
}
