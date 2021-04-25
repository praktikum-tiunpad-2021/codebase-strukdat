#include <iostream>
#include <vector>
#include <stack>

using std::vector;
using std::stack;

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

void DFSTraversal(int node) {
  vector<bool> visited(g.adjList.size(), false);

  stack<int> stack;
  stack.push(node);

  while (!stack.empty()) {
    if (!visited[node]) {
      visited[node] = true;
      std::cout << node << ' ';
    }

    vector<int>::iterator i;
    for (i = g.adjList[node].begin(); i != g.adjList[node].end(); ++i) {
      if (!visited[*i]) {
        node = *i;
        stack.push(node);
        break;
      }
    }
    
    if (i == g.adjList[node].end()) {
      node = stack.top();
      stack.pop();
    }
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
  DFSTraversal(1);
  return 0;
}
