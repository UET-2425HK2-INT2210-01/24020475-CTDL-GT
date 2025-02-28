#include <iostream>
#include <string>
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
        if(tail == nullptr) {
                tail = newnode;
                head = newnode;
        }
        else{
            tail->next=newnode;
            tail = newnode;
        }
    }

    void dequeue(){
        if(tail==nullptr) return;
        else{
            Node* temp = head;
            head = head->next;
            delete temp;
            if(head==nullptr){
                tail = nullptr;
            }
        }
    }

    void printqueue(){
        while(head!=nullptr){
            cout << head ->data << " ";
            head =  head->next;
        }
    }
};

int main(){
    int n;
    cin >> n;
    Queue queuelist;
    for(int i=0; i<n; i++){
        string t;
        cin >> t;
        if(t == "enqueue"){
            int x;
            cin >> x;
            queuelist.enqueue(x);
        }
        else if(t == "dequeue"){
            queuelist.dequeue();
        }
    }
    queuelist.printqueue();
    return 0;
}
