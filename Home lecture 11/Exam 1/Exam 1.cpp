#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
const int INF = 10000000; // Giá trị vô cực giả định cho khoảng cách chưa được cập nhật

// Thuật toán Floyd-Warshall để tìm đường đi ngắn nhất giữa mọi cặp đỉnh
void floydWarshall(int n, vector<vector<int>> &dist, vector<vector<int>> &next) {
    for (int k = 1; k <= n; k++) {  // Duyệt qua từng đỉnh trung gian
        for (int i = 1; i <= n; i++) {  // Duyệt qua từng đỉnh nguồn
            for (int j = 1; j <= n; j++) {  // Duyệt qua từng đỉnh đích
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];  // Cập nhật khoảng cách ngắn nhất
                    next[i][j] = next[i][k];  // Lưu truy vết để dựng đường đi
                }
            }
        }
    }
}

// Truy vết đường đi từ đỉnh u đến đỉnh v
vector<int> getPath(int u, int v, vector<vector<int>> &next) {
    vector<int> path;
    if (next[u][v] == -1) return path;  // Trả về danh sách rỗng nếu không có đường đi

    while (u != v) {  // Truy vết từ u đến v bằng cách lần theo bảng `next`
        path.push_back(u);
        u = next[u][v];
    }
    path.push_back(v); // Thêm điểm đích vào danh sách đường đi
    return path;
}

int main() {
    ifstream fin("dirty.txt");
    ofstream fout("dirty-out.txt");

    int n, m, s, e;
    fin >> n >> m >> s >> e;

    // Khởi tạo ma trận khoảng cách với giá trị INF và bảng truy vết với -1
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));
    vector<vector<int>> next(n + 1, vector<int>(n + 1, -1));

    // Khoảng cách từ một đỉnh đến chính nó là 0
    for (int i = 1; i <= n; i++) dist[i][i] = 0;

    // Đọc danh sách cạnh và cập nhật ma trận khoảng cách
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        fin >> u >> v >> w;
        dist[u][v] = w;
        next[u][v] = v;
    }

    floydWarshall(n, dist, next);  // Thực hiện thuật toán Floyd-Warshall
    vector<int> pathResult = getPath(s, e, next);  // Truy vết đường đi từ s đến e

    fout << dist[s][e] << '\n';  // Xuất khoảng cách ngắn nhất
    for (int node : pathResult) {
        fout << node << " ";  // Xuất đường đi
    }
    fout << endl;

    // Xuất ma trận khoảng cách giữa mọi cặp đỉnh
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            fout << (dist[i][j] == INF ? -1 : dist[i][j]) << " ";
        }
        fout << endl;
    }

    return 0;
}
