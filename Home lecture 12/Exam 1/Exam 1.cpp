#include <iostream>
#include <vector>
#include <stack>
#include <fstream>

using namespace std;

// Hàm DFS để duyệt đồ thị và tạo thứ tự topo
void dfsTraversal(const vector<vector<int>> &graph, vector<bool> &visited, int node, stack<int> &sortedOrder) {
    visited[node] = true;

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfsTraversal(graph, visited, neighbor, sortedOrder);
        }
    }

    sortedOrder.push(node);
}

// Hàm thực hiện sắp xếp topo bằng DFS
void performTopoSort(const vector<vector<int>> &graph, int numNodes, stack<int> &sortedOrder) {
    vector<bool> visited(numNodes + 1, false);

    for (int vertex = 1; vertex <= numNodes; vertex++) {
        if (!visited[vertex]) {
            dfsTraversal(graph, visited, vertex, sortedOrder);
        }
    }
}

int main() {
    ifstream inputFile("jobs.txt");
    ofstream outputFile("jobs-out.txt");

    int numNodes, numEdges;
    inputFile >> numNodes >> numEdges;

    vector<vector<int>> adjacencyList(numNodes + 1);

    for (int i = 1; i <= numEdges; i++) {
        int fromNode, toNode;
        inputFile >> fromNode >> toNode;
        adjacencyList[fromNode].push_back(toNode);
    }

    stack<int> sortedOrder;
    performTopoSort(adjacencyList, numNodes, sortedOrder);

    while (!sortedOrder.empty()) {
        outputFile << sortedOrder.top() << ' ';
        sortedOrder.pop();
    }

    return 0;
}
