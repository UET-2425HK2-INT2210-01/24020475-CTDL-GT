#include <iostream>
using namespace std;

// Định nghĩa cấu trúc Node cho cây nhị phân
struct Node{
	int data;       // Dữ liệu của node
	Node* left;     // Con trái
	Node* right;    // Con phải

	// Hàm khởi tạo node với giá trị data
	Node(int d){
		data = d;
		left = nullptr;
		right = nullptr;
	}
};

// Cấu trúc cây nhị phân
class tree{
public:
	Node* root;  // Gốc của cây

	// Hàm khởi tạo cây rỗng
	tree(){
		root = nullptr;
	}

	// Hàm chèn một giá trị vào cây nhị phân
	void insertbinary(int x){
		if(root==nullptr){
			// Nếu cây rỗng thì tạo node gốc
			root = new Node(x);
		}
		else{
			// Duyệt từ node gốc để tìm vị trí chèn thích hợp
			Node* newnode = new Node(x);
			Node* traversal = root;
			while(traversal!=nullptr){ // Điều kiện dừng vòng lặp
				if(x < traversal->data){
					if(traversal->left==nullptr){ // Nếu không có node con trái
                        traversal->left = newnode; // Chèn vào bên trái
                        break;
					}
					else traversal = traversal->left; // duyệt tiếp đến phần tử tiếp theo
				}
				else{
					if(traversal->right==nullptr){ // Nếu không có node con phải
                        traversal->right = newnode; // Chèn vào bên phải
                        break;
					}
					else traversal = traversal->right; // Duyệt đến phần tử tiếp theo
				}
			}
		}
	}

	// Hàm tìm node kế tiếp nhỏ nhất (successor) trong cây con bên phải
	// Còn 1 cách khác là hàm tìm node kế tiếp lớn nhất (predecessor) trong cây con bên trái
	Node* minright(Node* node){
		if(node == nullptr || node->right==nullptr){
			return nullptr;
		}
		else{
			node = node->right; // di chuyển sang nhánh cây bên phải
			while(node->left!=nullptr){
				node = node->left; // Tìm node nhỏ nhất bên phải
			}
		}
		return node; // trả về node nhỏ nhất
	}

	// Hàm xóa một node với giá trị y khỏi cây
	void deletebinary(int y) {
		if (root == nullptr) return;

		Node* parent = nullptr;      // Lưu node cha
		Node* traversal = root;      // Duyệt cây từ gốc

		// Vòng lặp tìm node cần xóa
        while (traversal != nullptr && traversal->data != y) {
            parent = traversal;
            if (y < traversal->data) {
                raversal = traversal->left;
            }
            else {
                traversal = traversal->right;
            }
        }

		if (traversal == nullptr) return; // Không tìm thấy node cần xóa

		// Trường hợp 1: Node không có con
		if (traversal->left == nullptr && traversal->right == nullptr) {
			if (parent == nullptr) root = nullptr; // Node là root
			else if (parent->left == traversal) parent->left = nullptr;
			else parent->right = nullptr;
			delete traversal;
		}
		// Trường hợp 2: Node có một con
		else if (traversal->left == nullptr || traversal->right == nullptr) {
			Node* child = (traversal->left != nullptr) ? traversal->left : traversal->right;
			if (parent == nullptr) root = child; // Node là root
			else if (parent->left == traversal) parent->left = child;
			else parent->right = child;
			delete traversal;
		}
		// Trường hợp 3: Node có hai con
		else {
			Node* successor = minright(traversal);              // Tìm successor
			int successorData = successor->data;                // Lưu giá trị successor
			deletebinary(successor->data);                      // Xóa successor
			traversal->data = successorData;                    // Gán giá trị mới
		}
	}

	// Hàm duyệt giữa cây (in-order traversal)
	void inoder(Node* node){
		if(node==nullptr){
			return;
		}
		else{
			inoder(node->left);              // Duyệt trái
			cout << node->data << " ";       // In node
			inoder(node->right);             // Duyệt phải
		}
	}

	// Hàm in toàn bộ cây theo thứ tự giữa
	void printinoder(){
		inoder(root);
		cout << endl;
	}
};


int main(){
	tree binarytree; // khai báo cây
	string t;

	cout << "Nhap cac lenh:" << endl
             << "insert x: nhap gia tri" << endl
             << "delete x: xoa gia tri" << endl
             << "print: in cay" << endl
             << "exit: thoat khoi chuong trinh" << endl;

	do{
		cin >> t;
		if(t=="insert"){
			int d;
			cin >> d;
			binarytree.insertbinary(d); // Thêm giá trị vào cây
		}
		else if(t=="delete"){
			int d;
			cin >> d;
			binarytree.deletebinary(d); // Xóa giá trị khỏi cây
		}
		else if(t=="print"){
			binarytree.printinoder();   // In cây theo in-order
		}
		else if(t=="exit"){
            break;                      // Thoát vòng lặp
		}
	}while(!t.empty());

	return 0;
}
