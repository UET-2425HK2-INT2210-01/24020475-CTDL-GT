#include <iostream>
using namespace std;

bool found = false; // Biến toàn cục để đánh dấu nếu tìm thấy tổng X

void trySubset(int A[], int n, int index, int currentSum, int target) {
    if (currentSum == target) {
        found = true;
        return;
    }
    if (index == n || found) return; // Nếu đã xét hết hoặc đã tìm thấy thì dừng

    // Chọn phần tử hiện tại
    trySubset(A, n, index + 1, currentSum + A[index], target);

    // Không chọn phần tử hiện tại
    trySubset(A, n, index + 1, currentSum, target);
}

int main() {
    int n, X;
    cin >> n >> X;

    int A[n];
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    trySubset(A, n, 0, 0, X);

    if (found) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
