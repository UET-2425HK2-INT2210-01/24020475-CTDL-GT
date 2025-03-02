#include <iostream>
using namespace std;

double power(int n){
    double result = 1;
    if(n>=0){
    for(int i=0; i<n; i++)
        result *= 2;
    }
    else{
    for(int i=0; i<-n; i++)
        result *= 2;
    result = 1/result;
    }
    return result;
}

int main(){
    int n;
    cin >> n;
    cout << power(n);
    return 0;
}
