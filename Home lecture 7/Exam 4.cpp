#include <iostream>
using namespace std;

// Hàm sinh tất cả các xâu nhị phân độ dài n
void generateBinary(int n, string Binary = "") {
    if (Binary.length() == n) {
        cout << Binary << endl;
        return;
    }

    // Thêm '0' và gọi đệ quy
    generateBinary(n, Binary + "0");

    // Thêm '1' và gọi đệ quy
    generateBinary(n, Binary + "1");
}

int main() {
    int n;
    cout << "Nhap do dai n: ";
    cin >> n; // Nhập độ dài xâu nhị phân
    generateBinary(n); // In các xâu nhị phân có độ dài n

    return 0;
}

