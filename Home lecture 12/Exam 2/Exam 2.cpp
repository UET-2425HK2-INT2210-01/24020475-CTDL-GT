#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

// Cấu trúc dữ liệu biểu diễn một cạnh trong đồ thị
struct Edge {
    int start, end, weight;

    // Toán tử so sánh để sắp xếp cạnh theo trọng số tăng dần (áp dụng cho Kruskal)
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

// Cấu trúc dữ liệu dùng trong Disjoint Set Union (DSU)
vector<int> parent; // Lưu cha đại diện của mỗi tập hợp
vector<int> rank_set; // Lưu cấp bậc của từng tập hợp (để tối ưu hóa việc hợp nhất)

// Hàm tìm tập hợp đại diện của một đỉnh (có áp dụng path compression)
int findSet(int node) {
    if (parent[node] != node)
        parent[node] = findSet(parent[node]); // Tối ưu hóa bằng nén đường đi
    return parent[node];
}

// Hàm hợp nhất hai tập hợp nếu chúng thuộc các cây khác nhau
bool unionSets(int nodeA, int nodeB) {
    int rootA = findSet(nodeA);
    int rootB = findSet(nodeB);

    if (rootA == rootB) return false; // Nếu cùng một tập hợp thì không hợp nhất

    // Hợp nhất theo cấp bậc của cây (giúp giữ cây phẳng)
    if (rank_set[rootA] < rank_set[rootB]) {
        parent[rootA] = rootB;
    } else if (rank_set[rootA] > rank_set[rootB]) {
        parent[rootB] = rootA;
    } else {
        parent[rootB] = rootA;
        rank_set[rootA]++;
    }
    return true;
}

int main() {
    ifstream inputFile("connection.txt"); // Mở file chứa dữ liệu đồ thị
    ofstream outputFile("connection-out.txt"); // Mở file để ghi kết quả

    // Kiểm tra xem file có mở thành công không
    if (!inputFile) {
        cerr << "Không thể mở file đầu vào!\n";
        return 1;
    }
    if (!outputFile) {
        cerr << "Không thể mở file đầu ra!\n";
        return 1;
    }

    int numNodes, numEdges;
    inputFile >> numNodes >> numEdges;

    // Đọc danh sách cạnh từ file
    vector<Edge> edges(numEdges);
    for (int i = 0; i < numEdges; ++i) {
        inputFile >> edges[i].start >> edges[i].end >> edges[i].weight;
    }

    sort(edges.begin(), edges.end()); // Sắp xếp các cạnh theo trọng số tăng dần

    // Khởi tạo DSU (mỗi nút là cha của chính nó)
    parent.resize(numNodes + 1);
    rank_set.resize(numNodes + 1, 0);
    for (int i = 1; i <= numNodes; ++i) {
        parent[i] = i;
    }

    int totalCost = 0; // Tổng trọng số của cây khung nhỏ nhất (MST)
    vector<Edge> mst; // Danh sách các cạnh thuộc MST

    // Duyệt qua từng cạnh đã sắp xếp để tạo MST theo thuật toán Kruskal
    for (Edge& edge : edges) {
        if (unionSets(edge.start, edge.end)) { // Nếu hợp nhất được hai tập hợp
            totalCost += edge.weight; // Cộng trọng số vào tổng chi phí
            mst.push_back(edge); // Thêm cạnh vào danh sách MST
        }
    }

    // Ghi kết quả ra file
    outputFile << totalCost << '\n'; // Ghi tổng trọng số của cây khung nhỏ nhất
    for (Edge& edge : mst) {
        outputFile << edge.start << ' ' << edge.end << ' ' << edge.weight << '\n';
    }

    return 0;
}
