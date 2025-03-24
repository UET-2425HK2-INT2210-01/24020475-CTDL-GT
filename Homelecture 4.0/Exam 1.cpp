#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int d){
        data = d;
        next = nullptr;
    }
};

class linklist{
private:
    Node* head = nullptr;
public:

    void append(int x){
        Node* newnode = new Node(x);
        if (head == nullptr){
            head = newnode;
            return;
        }
        else{
            Node* current = head;
            while(current->next!=nullptr){
                current = current->next;
            }
            current->next = newnode;
        }
    }

    int searched(int x){
        int position=-1;
        if(head == nullptr) return position;
        else{
            int count=0;
            Node* current = head;
            while(current != nullptr){
                if(current->data == x){
                    position = count;
                    break;
                }
                count++;
                current = current->next;
            }
        }
        return position;
    }

    void reverse(){
    if(head == nullptr) return;
    Node* prev = nullptr;
    Node* current = head;
    while(current != nullptr){
        Node* nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    head = prev;
}


    void printlist(){
        Node* current = head;
        while(current!=nullptr){
            cout << current->data << " ";
            current = current->next;
        }
    }
};

int main() {
    linklist listed;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        string t;
        cin >> t;
        if(t=="append"){
            int x;
            cin >> x;
            listed.append(x);
        }
        else if(t=="search"){
            int x;
            cin >> x;
            if(listed.searched(x) == -1){
                cout << "NO"<<endl;}
            else{
                cout << listed.searched(x)<<endl;
            }

        }
        else if(t=="reverse"){
            listed.reverse();
        }
    }
    listed.printlist();
    return 0;
}
