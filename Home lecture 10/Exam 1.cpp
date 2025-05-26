#include <iostream>
#include <vector>
using namespace std;

// duyệt cây dfs
void dfs(vector<vector<int>> &adj, vector<bool> &isVisited, int node) {
    // đánh dấu node đã được visit
    isVisited[node] = true;
    // duyệt tất cả node hàng xóm
    for (int neighbor : adj[node]) {
        if (!isVisited[neighbor])
            // dfs tất cả node hàng xóm để đánh dấu 1 đồ thị liên thông tất cả các node là visited
            dfs(adj, isVisited, neighbor);
    }
}
// đếm số lượng đồ thị liên thông

int main() //Xử lý đầu vào
{
	int n, m, count = 0;
	cin >> n >> m;
	vector<bool> visited(n + 1, false); //tạo vector visited kiểm tra xem đã thăm node chưa
	vector<vector<int>> adj(n + 1); //tạo vector adj để lưu trữ các đỉnh kề
	while (m--) { //xử lý đầu vào
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y); //thêm đỉnh y vào danh sách kề của x
		adj[y].push_back(x); //thêm đỉnh x vào danh sách kề của y
	}
	for (int i = 1; i <= n; ++i) { //duyệt qua tất cả các đỉnh
		if (!visited[i]) { //nếu đỉnh chưa được thăm
			dfs(adj, visited, i); //gọi hàm dfs để duyệt đồ thị
			++count; //tăng biến đếm số thành phần liên thông
		}
	}
	cout << count << endl; //in ra số thành phần liên thông
}
