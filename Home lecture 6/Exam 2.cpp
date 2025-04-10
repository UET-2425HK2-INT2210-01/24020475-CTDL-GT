#include <iostream>
using namespace std;

const int maxheapsize = 1000; // Kích thước tối đa của Heap

class Minheap {
private:
    int* heap; // Mảng lưu trữ các phần tử của Heap
    int heapsize; // Số lượng phần tử hiện tại trong Heap

    // Hàm tính chỉ số cha của nút tại vị trí i
    int dad(int i) {
        return (i - 1) / 2;
    }

    // Hàm tính chỉ số con trái của nút tại vị trí i
    int leftchild(int i) {
        return (2 * i + 1);
    }

    // Hàm tính chỉ số con phải của nút tại vị trí i
    int rightchild(int i) {
        return (2 * i + 2);
    }

    // Hoán đổi giá trị giữa hai phần tử
    void minswap(int& a, int& b) {
        int temp = b;
        b = a;
        a = temp;
    }

    // Duy trì tính chất Min Heap từ dưới lên
    void heapifyup(int i) {
        int parent = dad(i); // Tìm nút cha
        if (i > 0 && heap[i] < heap[parent]) { // Nếu nút con nhỏ hơn nút cha
            minswap(heap[i], heap[parent]); // Hoán đổi nút cha và nút con
            heapifyup(parent); // Tiếp tục kiểm tra nút cha
        }
    }

    // Duy trì tính chất Min Heap từ trên xuống
    void heapifydown(int i) {
        int smallest = i; // Khởi tạo nút nhỏ nhất là nút hiện tại
        int left = leftchild(i); // Chỉ số con trái
        int right = rightchild(i); // Chỉ số con phải

        // So sánh với con trái, nếu nhỏ hơn thì cập nhật
        if (left < heapsize && heap[left] < heap[smallest]) {
            smallest = left;
        }

        // So sánh với con phải, nếu nhỏ hơn thì cập nhật
        if (right < heapsize && heap[right] < heap[smallest]) {
            smallest = right;
        }

        // Nếu cần hoán đổi, thực hiện hoán đổi và tiếp tục heapify xuống dưới
        if (smallest != i) {
            minswap(heap[i], heap[smallest]);
            heapifydown(smallest);
        }
    }

public:
    // Constructor: Khởi tạo Heap rỗng
    Minheap() {
        heapsize = 0;
        heap = new int[maxheapsize]; // Khởi tạo mảng Heap với kích thước tối đa
    }

    // Thêm một phần tử mới vào Heap
    void insertion(int x) {
        if (heapsize == maxheapsize) { // Kiểm tra nếu đầy Heap
            cout << "Can't add more" << endl;
            return;
        } else {
            heap[heapsize] = x; // Thêm phần tử vào cuối mảng
            heapifyup(heapsize); // Duy trì tính chất Min Heap
            heapsize++; // Tăng kích thước Heap
        }
    }

    // Xóa một phần tử cụ thể khỏi Heap
    void deletion(int x) {
        for (int i = 0; i < heapsize; i++) {
            if (heap[i] == x) { // Tìm phần tử cần xóa
                heap[i] = heap[heapsize - 1]; // Thay bằng phần tử cuối cùng
                heapsize--; // Giảm kích thước Heap
                heapifydown(i); // Duy trì tính chất Min Heap
                break;
            }
        }
    }

    // Xây dựng Heap từ một mảng đầu vào
    void heaptree(int arr[], int n) {
        for (int i = 0; i < n; i++) {
            insertion(arr[i]); // Chèn từng phần tử vào Heap
        }
    }

    // In các phần tử trong Heap dưới dạng mảng
    void printheaparr() {
        for (int i = 0; i < heapsize; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }

    // Duyệt cây theo thứ tự trước (preorder traversal)
    void preoder(int i) {
        if (i >= heapsize) { // Nếu chỉ số vượt quá kích thước Heap, thoát
            return;
        } else {
            cout << heap[i] << " "; // In giá trị của nút hiện tại
            preoder(leftchild(i)); // Duyệt con trái
            preoder(rightchild(i)); // Duyệt con phải
        }
    }

    // In toàn bộ Heap theo thứ tự trước
    void printpreoder() {
        preoder(0); // Bắt đầu từ gốc (root)
    }
};

int main() {
    int n; // Kích thước mảng đầu vào
    cin >> n;
    int treearray[n]; // Mảng đầu vào
    Minheap tree; // Tạo một Min Heap
    for (int i = 0; i < n; i++) {
        cin >> treearray[i]; // Nhập các phần tử
    }
    tree.heaptree(treearray, n); // Xây dựng Min Heap từ mảng
    tree.printheaparr(); // In các phần tử của Heap dưới dạng mảng
    cout << endl;

    cout << "Ban co muon delete phan tu nao khong ? : 1/Yes 2/No" << endl;
    while (true) {
        int t; cin >> t;
        if (t == 1) { // Nếu người dùng muốn xóa phần tử
            int x;
            cin >> x;
            tree.deletion(x); // Xóa phần tử khỏi Heap
        } else if (t == 2) { // Thoát nếu không muốn xóa nữa
            break;
        }
    }
    cout << "Preoder: ";
    tree.printpreoder(); // In Heap dưới dạng duyệt preorder
    return 0;
}
