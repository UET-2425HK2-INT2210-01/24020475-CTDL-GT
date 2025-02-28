#include <iostream>
using namespace std;

int equality(int a[], int n){
    int count=0;
    for(int i=0; i<n; i++){
        for(int j = i+1; j<n; j++){
            if(a[i] == a[j])
                count++;
        }
    }
    return count;
}

int main(){
    int n;
    cin >> n;
    int *a;
    a = new int[n];
    for(int i=0; i<n; i++)
        cin >> a[i];
    cout << equality(a,n);
    delete a;
    return 0;
}
