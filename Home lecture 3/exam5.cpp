#include <iostream>
using namespace std;

const int size = 1000;
class Stack{
private:
    int top;
    int stack[size];
public:
    Stack(){
        top=0;
    }

    void push(int x){
        if(top==size){
            cout << "Full";
            return;
        }
        else{
            stack[top] = x;
            top++;
        }
    }

    void pop(){
        if(top==NULL){
            cout << "None";
            return;
        }
        else{
            top--;
           }
        }

    void printstack(){
        for(int i=0; i<top; i++){
            cout << stack[i] << " ";
        }
    }
};

int main(){
    Stack list;
    int n; // the quantity of numbers you want to put in stack
    cin >> n;
    if(n>size){
        cout << "Can't enter that number";
        return 0;
    }
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
