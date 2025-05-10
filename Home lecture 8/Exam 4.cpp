#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Cấu trúc dữ liệu để lưu trữ thông tin về từng vật
struct numbersvalue {
    int value;  // Giá trị của vật
    int weight; // Trọng lượng của vật
};

// Hàm tìm tổng giá trị lớn nhất có thể đạt được với tổng trọng lượng không vượt quá x
int largestsum(numbersvalue arr[], int n, int x) {
    vector<int> max_value(x + 1, 0); // Mảng động để lưu tổng giá trị lớn nhất

    if (n == 0) return 0; // Nếu không có vật nào, tổng giá trị là 0

    // Duyệt qua từng vật
    for (int i = 0; i < n; i++) {
        // Duyệt ngược để đảm bảo mỗi vật chỉ được xét một lần
        for (int j = x; j >= arr[i].weight; j--) {
            // Cập nhật giá trị tối đa cho trọng lượng j khi thêm arr[i]
            max_value[j] = max(max_value[j], max_value[j - arr[i].weight] + arr[i].value);
        }
    }

    return max_value[x]; // Trả về tổng giá trị lớn nhất có thể đạt được với trọng lượng x
}

int main() {
    int n, x;
    cin >> n >> x; // Nhập số lượng vật và giới hạn trọng lượng
    numbersvalue array[n]; // Mảng lưu thông tin vật

    // Nhập trọng lượng và giá trị của từng vật
    for (int i = 0; i < n; i++) {
        cin >> array[i].weight >> array[i].value;
    }

    // Xuất tổng giá trị lớn nhất có thể đạt được
    cout << largestsum(array, n, x);

    return 0;
}
