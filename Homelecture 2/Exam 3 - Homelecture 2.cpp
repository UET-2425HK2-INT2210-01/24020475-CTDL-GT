#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
    Node(int d_){
        data = d_;
        next = nullptr;
        prev = nullptr;
    }
};

void add(Node*& head, int value){
    Node* newnode = new Node(value);
    if(head == nullptr){
        head = newnode;
        return;
    }
    Node* current = head;
    while(current->next != nullptr){
        current = current->next;
    }
    current->next = newnode;
    newnode->prev = current;
}

int count_triplets(Node* head){
    if(head == nullptr) return 0;
    int counted = 0;
    Node* temp = head->next;
    while(temp != nullptr && temp->next != nullptr){
        if(temp->prev->data + temp->data + temp->next->data == 0){
            counted++;
        }
        temp = temp->next;
    }
    return counted;
}

int main(){
    int n;
    cin >> n;
    Node* head = nullptr;
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        add(head, val);
    }
    cout << count_triplets(head) << endl;
    return 0;
}
