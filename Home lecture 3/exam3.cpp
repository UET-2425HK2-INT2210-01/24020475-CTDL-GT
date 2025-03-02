#include <iostream>
using namespace std;

const int size = 1000;
class Queue{
private:
    int front, rear;
    int queued[size];
public:
    Queue(){
        front = rear = 0;
    }

    void enqueue(int x){
        if(rear == size){
            cout << "Full";
            return;
        }
        else{
            queued[rear]=x;
            rear++;
        }
    }

    void dequeue(){
        if(front == rear){
            cout << "None to delete";
            return;
        }
        else{
            for(int i=0; i< rear-1; i++){
                queued[i]=queued[i+1];
            }
            rear--;
        }
    }

    void printqueue(){
        for(int i=0;i<rear;i++)
            cout << queued[i] << " ";
    }
};

int main(){
    Queue list;
    int n; // the quantity of numbers you want to put in queue
    cin >> n;
    if(n>size){
        cout << "Can't enter that number";
        return 0;
    }
    for(int i=0; i<n; i++){
        string t;
        cin >> t;
        if(t=="enqueue"){
            int x;
            cin >> x;
            list.enqueue(x);
        }
        else if(t=="dequeue"){
            list.dequeue();
        }
    }
    list.printqueue();
    return 0;
}
