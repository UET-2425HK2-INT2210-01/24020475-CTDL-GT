#include <iostream>
using namespace std;

// Hàm in các hoán vị hiện tại của mảng
void printPermutations(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i]; // Hiển thị từng phần tử trong mảng
    }
    cout << endl; // Kết thúc dòng sau khi in xong
}

// Hàm đệ quy để tạo các hoán vị của mảng
void generatePermutations(int arr[], int l, int r) {
    if (l == r) {
        printPermutations(arr, r + 1); // Khi đạt đến điểm dừng, in ra hoán vị
    } else {
        for (int i = l; i <= r; i++) {
            // Thực hiện hoán đổi phần tử tại vị trí 'l' và 'i'
            int temp = arr[l];
            arr[l] = arr[i];
            arr[i] = temp;

            // Gọi đệ quy để tiếp tục tạo các hoán vị từ chỉ số tiếp theo
            generatePermutations(arr, l + 1, r);

            // Hoàn tác hoán đổi để quay về trạng thái ban đầu trước khi duyệt hoán vị kế tiếp
            temp = arr[l];
            arr[l] = arr[i];
            arr[i] = temp;
        }
    }
}

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n; // Nhập kích thước của mảng

    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1; // Gán giá trị cho mảng theo thứ tự từ 1 đến n
    }

    generatePermutations(arr, 0, n - 1); // Bắt đầu tạo hoán vị từ mảng ban đầu

    return 0;
}
