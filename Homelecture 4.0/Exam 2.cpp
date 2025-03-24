#include <iostream>
using namespace std;

struct Node{
    int data;
    int piority;
    Node* next;
    Node* prev;
    Node(int d, int p){
        data = d;
        piority = p;
        next = nullptr;
        prev = nullptr;
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

    void enqueue(int x, int p){
        Node* newnode = new Node(x, p);
        if(head==nullptr){
            head = newnode;
            tail = newnode;
            return;
        }
        else{
            Node* current = head;
            if(current->piority < newnode->piority){
                newnode->next = current;
                current->prev = newnode;
                head = newnode;
                return;
            }
            else{
                while(current->next!=nullptr && current->next->piority >= newnode->piority){
                    current = current->next;
                }
                newnode->next = current->next;
                if(current->next != nullptr){
                    current->next->prev = newnode;
                }
                 else{
                    tail = newnode;
                }
                current->next = newnode;
                newnode->prev = current;
            }
        }
    }

    void dequeue(){
        Node* current = head;
        head = head->next;
        delete current;
    }

    void printlist(){
        Node* current = head;
        while(current != nullptr){
            cout << " (" << current->data << "," << " " << current->piority << ")" << ";";
            current = current->next;
        }
    }
};

int main(){
    Queue listed;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        string t;
        cin >> t;
        if(t=="enqueue"){
            int x, p;
            cin >> x >> p;
            listed.enqueue(x, p);
        }
        else if(t=="dequeue"){
            listed.dequeue();
        }
    }
    listed.printlist();
    return 0;
}
