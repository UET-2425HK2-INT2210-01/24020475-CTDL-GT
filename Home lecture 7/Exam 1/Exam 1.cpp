#include <iostream>
#include <fstream>
using namespace std;

// Hàm đổi chỗ giá trị của hai biến
void swap(int& a, int& b){
    int temp = a; // Lưu giá trị của a vào biến tạm
    a = b;        // Gán giá trị của b cho a
    b = temp;     // Gán giá trị của biến tạm cho b
}

int main(){
    // Mở file đầu vào để đọc dữ liệu
    ifstream Input("numbers.txt");
    // Mở file đầu ra để ghi dữ liệu đã sắp xếp
    ofstream Output("numbers.sorted.txt");
    int arr[1000]; // Mảng lưu trữ các số từ file
    int count = 0; // Biến đếm số phần tử trong mảng

    // Kiểm tra xem file đầu vào có mở được không
    if(!Input)
        cout << "Khong mo duoc file ?" << endl; // Thông báo lỗi nếu không mở được file
    else{
        // Đọc dữ liệu từ file đầu vào và lưu vào mảng
        while (Input >> arr[count]){
            count++; // Tăng biến đếm sau mỗi lần đọc
        }

        // Sắp xếp mảng theo thứ tự tăng dần bằng thuật toán sắp xếp nổi bọt
        for(int i=0; i<count; i++){
            for(int j=i+1; j<count; j++){
                if(arr[j] <= arr[i]){ // Nếu phần tử sau nhỏ hơn hoặc bằng phần tử trước
                    swap(arr[i], arr[j]); // Đổi chỗ hai phần tử
                }
            }
        }

        // Ghi mảng đã sắp xếp vào file đầu ra
        for(int i=0; i<count; i++){
            Output << arr[i] << " "; // Ghi từng phần tử vào file
        }
    }

    // Kiểm tra xem file đầu ra có ghi được không
    if(Output)
        cout << "Ket qua da duoc in ra file" << endl; // Thông báo thành công
    else
        cout << "File khong mo duoc ?" << endl; // Thông báo lỗi nếu không ghi được file

    // Đóng file đầu vào và file đầu ra
    Input.close();
    Output.close();

    return 0; // Kết thúc chương trình
}
