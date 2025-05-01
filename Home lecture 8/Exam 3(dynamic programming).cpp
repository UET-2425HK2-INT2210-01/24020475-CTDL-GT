#include <iostream>
using namespace std;

// Định nghĩa kích thước tối đa cho mảng kiểm tra tổng
const int max_size = 1000;

bool findagesum(int arr[], int n, int x) {
    bool current[max_size]; // Mảng đánh dấu các tổng có thể tạo được

    // Khởi tạo mảng `current` với giá trị `false`
    for (int i = 0; i < max_size; i++) {
        current[i] = false;
    }

    // Nếu không có phần tử nào, không thể tạo tổng X → trả về false
    if (n == 0) return false;

    // Luôn có thể tạo tổng 0 bằng cách không chọn phần tử nào
    current[0] = true;

    // Kiểm tra nhanh nếu có phần tử nào đúng bằng x → trả về true ngay
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) return true;
    }

    // Duyệt từng phần tử trong mảng arr[]
    for (int i = 0; i < n; i++) {
        // Duyệt ngược từ X về arr[i] để tránh ghi đè giá trị chưa cập nhật
        for (int j = x; j >= arr[i]; j--) {
            // Nếu có thể tạo tổng `j - arr[i]`, thì có thể tạo tổng `j`
            if (current[j - arr[i]]) {
                current[j] = true;
            }
        }
    }

    // Kiểm tra nếu có thể tạo tổng đúng bằng X
    return current[x];
}

int main() {
    int n, x;
    cin >> n >> x;

    int array[n];

    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    if (findagesum(array, n, x)) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
