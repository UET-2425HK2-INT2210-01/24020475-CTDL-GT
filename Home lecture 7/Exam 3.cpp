#include <iostream>

using namespace std;

// Hàm tìm ước số chung lớn nhất (gcd) giữa hai số nguyên a và b
int findgcd(int a, int b){
    if(b == 0) return a; // Điều kiện dừng: nếu b bằng 0, trả về a
    return findgcd(b, a % b); // Đệ quy: gọi hàm với b và phần dư của a chia b
}

int main()
{
    int x, y; // Khai báo hai số nguyên x và y
    cin >> x >> y; // Nhập hai số nguyên từ người dùng
    cout << findgcd(x, y); // In ra ước số chung lớn nhất của x và y
    return 0;
}
