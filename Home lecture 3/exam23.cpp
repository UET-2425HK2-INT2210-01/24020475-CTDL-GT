#include <iostream>
using namespace std;

double power(int n){
    double result;
    if(n>0){
        return result = 1 << n;
    }
    else{
        result = 1 << -n;
        return 1/result;
    }
}

int main(){
    int n;
    cin >> n;
    cout << power(n);
    return 0;
}
