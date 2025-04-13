#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("Matrix.txt");
    ofstream fout("Matrix.out.txt");

    int m, n;
    fin >> m >> n;

    int matrix[100][100]; // Giới hạn ma trận 100x100 để đơn giản, bạn có thể tăng giới hạn nếu cần

    // Đọc dữ liệu từ file
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            fin >> matrix[i][j];

    int maxSum = 0;
    int r1, c1, r2, c2;

    // Brute-force: Duyệt tất cả các hình chữ nhật có thể
    for (int top = 0; top < m; ++top) {
        for (int left = 0; left < n; ++left) {
            for (int bottom = top; bottom < m; ++bottom) {
                for (int right = left; right < n; ++right) {
                    int sum = 0;

                    // Tính tổng hình chữ nhật từ (top, left) đến (bottom, right)
                    for (int i = top; i <= bottom; ++i)
                        for (int j = left; j <= right; ++j)
                            sum += matrix[i][j];

                    // Cập nhật nếu tổng lớn hơn
                    if (sum > maxSum) {
                        maxSum = sum;
                        r1 = top;
                        c1 = left;
                        r2 = bottom;
                        c2 = right;
                    }
                }
            }
        }
    }

    // In ra kết quả với chỉ số bắt đầu từ 1
    fout << r1 + 1 << " " << c1 + 1 << " "
         << r2 + 1 << " " << c2 + 1 << " "
         << maxSum << endl;

    return 0;
}
