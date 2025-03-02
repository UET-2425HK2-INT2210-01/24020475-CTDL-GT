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

class Queue{
private:
    Node* head;
    Node* tail;
public:
    Queue(){
        head = nullptr;
        tail = nullptr;
    }

    void enqueue(int x){
        Node* newnode = new Node(x);
        if(head==nullptr){
            head = newnode;
            tail = newnode;
            return;
        }
        else{
            tail->next = newnode;
            tail = newnode;
        }
    }

    void dequeue(){
        if(head==nullptr){
            tail == nullptr;
            return;
        }
        else{
            Node* temp = head;
            temp->next = head->next;
            head = head->next;
            delete temp;
        }
    }

    void printqueue(){
        while(head!=nullptr){
            cout << head->data << " ";
            head = head->next;
        }
    }
};

int main(){
    int n;
    cin >> n;
    Queue listed;
    for(int i=0; i<n; i++){
        string t;
        cin >> t;
        if(t=="enqueue"){
            int x;
            cin >> x;
            listed.enqueue(x);
        }
        else if(t=="dequeue"){
            listed.dequeue();
        }
    }
    listed.printqueue();
    return 0;
}
