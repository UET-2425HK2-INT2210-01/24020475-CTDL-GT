#include <iostream>
using namespace std;

// Hàm hoán đổi giá trị của hai biến
void swap(int& a, int& b){
    int tmp = b;
    b = a;
    a = tmp;
}

// Hàm phân đoạn theo Lomuto Partition
int lomutopartition(int arr[], int left, int right){
    int mid = left + (right - left) / 2; // Chọn phần tử giữa làm pivot
    swap(arr[mid], arr[right]); // Đưa pivot từ giữa ra cuối mảng

    int current = left - 1; // Biến theo dõi vị trí của phần tử nhỏ hơn pivot
    int pivot = arr[right]; // Pivot là phần tử cuối cùng (đã hoán đổi)

    // Duyệt mảng để sắp xếp các phần tử nhỏ hơn pivot sang bên trái
    for(int i = left; i < right; i++){
        if(arr[i] <= pivot){ // Nếu phần tử nhỏ hơn hoặc bằng pivot
            current++; // Tăng vị trí của nhóm phần tử nhỏ hơn pivot
            swap(arr[current], arr[i]); // Hoán đổi phần tử nhỏ hơn với vị trí mới
        }
    }

    swap(arr[current + 1], arr[right]); // Đưa pivot vào vị trí đúng
    return current + 1; // Trả về vị trí của pivot để tiếp tục phân đoạn
}

// Hàm QuickSort sử dụng Lomuto Partition
void quicksortlomuto(int arr[], int left, int right){
    if(left < right){ // Điều kiện để tiếp tục chia nhỏ mảng
        int pivotnumber = lomutopartition(arr, left, right); // Xác định vị trí pivot

        quicksortlomuto(arr, left, pivotnumber - 1); // Sắp xếp phần bên trái của pivot
        quicksortlomuto(arr, pivotnumber + 1, right); // Sắp xếp phần bên phải của pivot
    }
}

// Hàm phân đoạn theo Hoare Partitioning
int hoarepartition(int arr[], int left, int right) {
    int mid = left + (right - left) / 2; // Chọn phần tử giữa làm pivot
    int pivot = arr[mid]; // Lưu giá trị pivot

    int i = left - 1; // Điểm bắt đầu từ bên trái
    int j = right + 1; // Điểm bắt đầu từ bên phải

    while (true) {
        // Tìm phần tử lớn hơn hoặc bằng pivot từ bên trái
        do {
            left++;
        } while (arr[left] < pivot);

        // Tìm phần tử nhỏ hơn hoặc bằng pivot từ bên phải
        do {
            right--;
        } while (arr[right] > pivot);

        // Khi hai con trỏ đã vượt qua nhau, trả về vị trí cuối cùng của pivot
        if (left >= right) {
            return right;
        }

        // Hoán đổi phần tử để đảm bảo phần tử nhỏ hơn pivot ở bên trái
        // và phần tử lớn hơn pivot ở bên phải
        swap(arr[left], arr[right]);
    }
}

// Hàm QuickSort sử dụng Hoare Partitioning
void quicksorthoare(int arr[], int left, int right) {
    if (left < right) { // Kiểm tra xem mảng có thể tiếp tục chia nhỏ hay không
        int current = hoarepartition(arr, left, right); // Tìm vị trí phân đoạn

        // Sắp xếp đệ quy phần bên trái của pivot
        quicksorthoare(arr, left, current);

        // Sắp xếp đệ quy phần bên phải của pivot
        quicksorthoare(arr, current + 1, right);
    }
}

// Hàm in mảng ra màn hình
void printarr(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int n;
    cout << "Nhap kich thuoc mang:" << endl;
    cin >> n;

    cout << "Nhap cac phan tu cua mang:" << endl;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << "Ket qua sau khi quicksort bang lomuto partition:" << endl;
    quicksortlomuto(arr, 0, n - 1);
    printarr(arr, n);

    cout << "Ket qua sau khi quicksort bang hoare partition:" << endl;
    quicksorthoare(arr, 0, n-1);
    printarr(arr, n);
    return 0;
}
