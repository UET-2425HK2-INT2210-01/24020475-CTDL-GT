#include <iostream>
using namespace std;

double power(int n){
    if(n==0)return 1;
    if(n%2==0 && n>=0) return 2*power(n/2);
    if(n%2==1 && n>=0) return 2*power(2*(n-1)/2);
    if(n%2==0 && n<0) return 1/(2*power(2*(-n/2)));
    if(n%2==1 && n<0) return 1/(2*power(2*(-n-1)/2));
}

int main(){
    int n;
    cin >> n;
    cout << power(n);
    return 0;
}
