#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int d){
        data = d;
        next = nullptr;
    }
};

class stacklist{
private:
    Node* top;
public:
    stacklist(){
        top = nullptr;
    }

    void push(int x){
        Node* newnode = new Node(x);
        if(top==nullptr){
            top = newnode;
        }
        else{
            newnode->next = top;
            top = newnode;
        }
    }

    void pop(){
        if(top == nullptr) return;
        else{
            Node* current = top;
            current = top->next;
            delete top;
            top = current;
            if(top==nullptr){
                return;
            }
        }
    }

    void printstack(){
        vector <int> print;
        while(top!=nullptr){
            print.push_back(top->data);
            top = top->next;
        }
        reverse(print.begin(), print.end());
        for(int i=0; i<print.size(); i++){
            cout << print[i] << " ";
        }
}
};


int main(){
    int n;
    cin >>n;
    stacklist stacked;
    for(int i=0; i<n; i++){
        string t;
        cin >> t;
        if(t == "push"){
            int x;
            cin >> x;
            stacked.push(x);
        }
        else if(t == "pop"){
            stacked.pop();
        }
    }
    stacked.printstack();
    return 0;
}
