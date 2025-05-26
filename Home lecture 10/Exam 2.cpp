#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Hàm BFS để tìm khoảng cách từ đỉnh x đến đỉnh y
void bfs(int x, int y, int n, vector<bool> &visited, vector<vector<int>> &adj) {
    visited[x] = true; // Đánh dấu đỉnh x đã được thăm
    vector<int> dist(n + 1, 0); // Mảng lưu khoảng cách từ x đến các đỉnh khác
    queue<int> q; // Hàng đợi dùng trong thuật toán BFS
    q.push(x); // Đưa đỉnh x vào hàng đợi

    while (!q.empty()) { // Duyệt BFS đến khi hàng đợi rỗng
        int current = q.front(); // Lấy đỉnh đầu tiên trong hàng đợi
        q.pop(); // Loại bỏ đỉnh đó khỏi hàng đợi

        // Duyệt các đỉnh kề của current
        for (int neighbor : adj[current]) {
            if (!visited[neighbor]) { // Nếu neighbor chưa được thăm
                visited[neighbor] = true; // Đánh dấu đã thăm
                dist[neighbor] = dist[current] + 1; // Cập nhật khoảng cách
                q.push(neighbor); // Đưa neighbor vào hàng đợi để tiếp tục BFS
            }
        }
    }

    cout << dist[y] << endl; // In khoảng cách từ x đến y
}

int main() {
    int n, m, X, Y;
    cin >> n >> m >> X >> Y; // Nhập số lượng đỉnh, cạnh và cặp (X, Y)

    vector<vector<int>> adj(n + 1); // Danh sách kề biểu diễn đồ thị
    vector<bool> visited(n + 1, false); // Mảng kiểm tra các đỉnh đã được duyệt

    // Đọc danh sách cạnh
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y); // Thêm đỉnh y vào danh sách kề của x
    }

    bfs(X, Y, n, visited, adj); // Thực hiện BFS từ đỉnh X để tìm khoảng cách đến Y

    return 0;
}
