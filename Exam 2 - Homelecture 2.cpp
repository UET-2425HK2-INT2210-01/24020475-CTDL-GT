#include <iostream>
#include <string>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int d_){
        data = d_;
        next = nullptr;
    }
};

class linkedlist{
public:
    Node* head = nullptr;
    void insert(int p, int x){
        Node* newnode = new Node(x);
        if(p==0){
            newnode->next=head;
            head = newnode;
            return;
        }
        else{
        Node* current = head;
        for(int i=0; i<p-1; i++){
            if(current == nullptr)
                return;
            current = current->next;
        }
        newnode->next = current->next;
        current->next=newnode;
        current = newnode;
        }
    }

    void deletenode(int p){
        if(head == nullptr) return;
        if(p==0){
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        else{
            Node* current = head;
            for(int i=0; i<p-1; i++){
                if(current == nullptr || current->next == nullptr)
                    return;
                current = current->next;
            }
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

    void printlist(){
        Node* current = head;
        while(current!=nullptr){
            cout<<current->data<<" ";
            current = current->next;
        }
        cout << endl;
    }
};

int main(){
    int n;
    cin >> n;
    linkedlist linklist;
    for(int i=0; i<n; i++){
        string inserted;
        cin >> inserted;

        if(inserted == "insert"){
            int p, x;
            cin >> p >> x;
            linklist.insert(p, x);
        }
        else if(inserted == "delete"){
            int p;
            cin >> p;
            linklist.deletenode(p);
        }
    }
    linklist.printlist();
    return 0;
}
