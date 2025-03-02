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

class stack{
private:
    Node* top;
public:
    stack(){
        top = nullptr;
    }

    void push(int x){
        Node* newnode = new Node(x);
        if(top==nullptr){
            top = newnode;
            return;
        }
        else{
            newnode->next = top;
            top = newnode;
        }
    }

    void pop(){
        if(top==nullptr)
            return;
        else{
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void printstack(){
        while(top!=nullptr){
            cout << top->data << " ";
            top = top->next;
        }
    }
};

int main(){
    int n;
    cin >> n;
    stack list;
    for(int i=0; i<n; i++){
        string t;
        cin >> t;
        if(t=="push"){
            int x;
            cin >> x;
            list.push(x);
        }
        else if(t=="pop"){
            list.pop();
        }
    }
    list.printstack();
    return 0;
}
