#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node(char d) {
        data = d;
        next = nullptr;
    }
};

class Stack {
private:
    Node* top;
public:
    Stack() {
        top = nullptr;
    }

    void push(char x) {
        Node* newnode = new Node(x);
        newnode->next = top;
        top = newnode;
    }

    char pop() {
        if (top == nullptr) return '\0';
        Node* temp = top;
        char popped = top->data;
        top = top->next;
        delete temp;
        return popped;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    bool isValid(string s) {
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                push(c);
            } else {
                if (isEmpty()) return false;

                char topChar = pop();
                if ((c == ')' && topChar != '(') ||
                    (c == '}' && topChar != '{') ||
                    (c == ']' && topChar != '[')) {
                    return false;
                }
            }
        }
        return isEmpty();
    }
};

int main() {
    string t;
    cin >> t;

    Stack list;
    if (list.isValid(t))
        cout << "Valid";
    else
        cout << "Invalid";

    return 0;
}
