#include <iostream>
using namespace std;

// Hàm trộn hai mảng con đã sắp xếp thành một mảng duy nhất
void merged(int arr[], int l, int m, int r){
    int lvolume = m - l + 1; // Số phần tử của mảng con bên trái
    int rvolume = r - m;     // Số phần tử của mảng con bên phải
    int L[lvolume], R[rvolume]; // Tạo hai mảng con để lưu dữ liệu

    // Sao chép dữ liệu vào mảng con bên trái
    for(int i = 0; i < lvolume; i++){
        L[i] = arr[l + i];
    }

    // Sao chép dữ liệu vào mảng con bên phải
    for(int i = 0; i < rvolume; i++){
        R[i] = arr[m + 1 + i];
    }

    // Chỉ số duyệt hai mảng con
    int i = 0, j = 0;
    int left = l; // Chỉ số để điền vào mảng gốc

    // Hợp nhất hai mảng con lại thành một mảng đã sắp xếp
    while(i < lvolume && j < rvolume){
        if(L[i] <= R[j]){ // Nếu phần tử bên trái nhỏ hơn phần tử bên phải
            arr[left] = L[i]; // Gán giá trị nhỏ hơn vào mảng chính
            i++;
        }
        else{ // Ngược lại, chọn phần tử bên phải
            arr[left] = R[j];
            j++;
        }
        left++; // Di chuyển chỉ số điền vào mảng chính
    }

    // Sao chép phần còn lại của mảng con bên trái (nếu còn)
    while(i < lvolume){
        arr[left] = L[i];
        i++;
        left++;
    }

    // Sao chép phần còn lại của mảng con bên phải (nếu còn)
    while(j < rvolume){
        arr[left] = R[j];
        j++;
        left++;
    }
}

// Hàm thực hiện thuật toán Merge Sort bằng cách chia nhỏ mảng
void mergesort(int arr[], int l, int r){
    if(l < r){  // Nếu mảng vẫn còn nhiều phần tử thì tiếp tục chia nhỏ
        int m = l + (r - l) / 2; // Tìm vị trí giữa mảng

        mergesort(arr, l, m);    // Gọi đệ quy sắp xếp nửa trái
        mergesort(arr, m + 1, r); // Gọi đệ quy sắp xếp nửa phải

        merged(arr, l, m, r);    // Hợp nhất hai nửa đã sắp xếp
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
    cout << "Nhap kich co array:" << endl;
    cin >> n;
    int arr[n];

    cout << "Nhap cac phan tu cua array:" << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << "Ket qua sau khi mergesort:" << endl;
    mergesort(arr, 0, n - 1);
    printarr(arr, n);

    return 0;
}
