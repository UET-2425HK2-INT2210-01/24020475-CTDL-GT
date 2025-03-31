#include <iostream>
using namespace std;

const int treesize = 1000; // Kích thước tối đa của cây

// Định nghĩa cấu trúc của một nút trong cây
struct Node {
    int data; // Dữ liệu của nút
    Node* firstchild; // Con đầu tiên của nút
    Node* siblings; // Anh em của nút

    // Hàm khởi tạo nút với giá trị đầu vào
    Node(int d) {
        data = d;
        firstchild = nullptr;
        siblings = nullptr;
    }
};

// Lớp quản lý cây và các chức năng của cây
class Trees {
public:
    Node* root; // Gốc của cây
    Node* treearray[treesize]; // Mảng lưu trữ các nút trong cây
    bool child[treesize]; // Mảng kiểm tra xem nút có phải là con không

    // Khởi tạo cây
    Trees() : root(nullptr) {
        for (int i = 0; i < treesize; i++) {
            treearray[i] = nullptr; // Ban đầu tất cả các phần tử là nullptr
            child[i] = false; // Tất cả đều không phải con
        }
    };

    // Hàm lấy nút gốc của cây
    Node* getRoot() {
        return root;
    }

    // Xác định nút gốc bằng cách tìm nút không phải là con của nút nào
    void addroot() {
        for (int i = 0; i < treesize; i++) {
            if (treearray[i] != nullptr && !child[i]) {
                root = treearray[i];
                return;
            }
        }
    }

    // Thêm một nút con (b) vào nút cha (a)
    void insertchild(int a, int b) {
        // Tạo nút a nếu nút này chưa tồn tại
        if (treearray[a] == nullptr) {
            treearray[a] = new Node(a);
        }
        // Tạo nút b nếu nút này chưa tồn tại
        if (treearray[b] == nullptr) {
            treearray[b] = new Node(b);
        }
        // Nếu nút a chưa có con, gán b làm con đầu tiên
        if (treearray[a]->firstchild == nullptr) {
            treearray[a]->firstchild = treearray[b];
        } else { // Nếu đã có con, thêm b vào danh sách anh em của a
            Node* current = treearray[a]->firstchild;
            while (current->siblings != nullptr) {
                current = current->siblings;
            }
            current->siblings = treearray[b];
        }
        child[b] = 1; // Đánh dấu b là con
        addroot(); // Cập nhật lại nút gốc
    }

    // Tính chiều cao của cây
    int height(Node* node) {
        if (node == nullptr)
            return 0; // Nếu nút là nullptr, chiều cao là 0
        int maxheight = 0; // Biến để lưu chiều cao lớn nhất
        Node* childnode = node->firstchild;
        // Duyệt qua tất cả các con và tính chiều cao lớn nhất
        while (childnode != nullptr) {
            int heighted = height(childnode);
            if (heighted > maxheight) maxheight = heighted;
            childnode = childnode->siblings;
        }
        return maxheight + 1; // Cộng thêm 1 để tính luôn nút hiện tại
    }

    // Duyệt cây theo thứ tự trước (preorder)
    void preoder(Node* treenode) {
        if (treenode == nullptr) return; // Dừng nếu nút là nullptr
        cout << treenode->data << " "; // In dữ liệu nút hiện tại
        Node* childnode = treenode->firstchild;
        // Đệ quy duyệt qua tất cả các con
        while (childnode != nullptr) {
            preoder(childnode);
            childnode = childnode->siblings;
        }
    }

    // Duyệt cây theo thứ tự sau (postorder)
    void postoder(Node* treenode) {
        if (treenode == nullptr) return; // Dừng nếu nút là nullptr
        Node* childnode = treenode->firstchild;
        // Đệ quy duyệt qua tất cả các con
        while (childnode != nullptr) {
            postoder(childnode);
            childnode = childnode->siblings;
        }
        cout << treenode->data << " "; // In dữ liệu nút sau khi duyệt qua các con
    }

    // Kiểm tra xem cây có phải là cây nhị phân không
    bool checkbinary(Node* node) {
        if (node == nullptr) return true; // Nếu nút là nullptr, vẫn là nhị phân

        Node* childnode = node->firstchild;
        int childnumber = 0; // Biến đếm số con
        while (childnode != nullptr) {
            childnumber++;
            if (childnumber > 2) return false; // Nếu có nhiều hơn 2 con, không phải nhị phân
            if (checkbinary(childnode) == false) return false; // Đệ quy kiểm tra từng con, nếu con có nhiều hơn 2 con khác, không phải nhị phân
            childnode = childnode->siblings;
        }
        return true; // Nếu tất cả các điều kiện đều thỏa, là cây nhị phân
    }

    // Duyệt cây theo thứ tự giữa (inorder) (chỉ cho cây nhị phân)
    void inoder(Node* node) {
        if (node == nullptr) return;
        if (node->firstchild != nullptr)
            inoder(node->firstchild); // Duyệt con trái
        cout << node->data << " "; // In dữ liệu nút hiện tại
        if ((node->firstchild != nullptr) && (node->firstchild->siblings != nullptr))
            inoder(node->firstchild->siblings); // Duyệt con phải
    }

    // In thứ tự giữa, nhưng chỉ nếu cây là nhị phân
    void printinoder() {
        if (checkbinary(root)) {
            inoder(root);
            cout << endl;
        } else
            cout << "NOT BINARY TREE" << endl; // In thông báo nếu không phải cây nhị phân
    }
};

int main() {
    int m, n; // m: số nút, n: số cạnh
    cin >> m >> n;

    Trees Tree; // Khởi tạo cây
    for (int i = 0; i < n; i++) {
        int u, v; // Đọc cặp nút(u, v)
        cin >> u >> v;
        Tree.insertchild(u, v); // Thêm cạnh vào cây
    }
    Node* root = Tree.getRoot(); // Lấy nút gốc của cây

    cout << Tree.height(root) << endl; // In chiều cao của cây

    Tree.preoder(root); // In duyệt cây theo thứ tự trước
    cout << endl;
    Tree.postoder(root); // In duyệt cây theo thứ tự sau
    cout << endl;
    Tree.printinoder(); // In duyệt cây theo thứ tự giữa (nếu là cây nhị phân)
    return 0;
}
