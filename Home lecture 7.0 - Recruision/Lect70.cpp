#include <iostream>

using namespace std;

int sumrecrusion(int n){
    if (n==0) return 0;
    return n + sumrecrusion(n-1);
}

int factorialrecrusion(int n){
    if(n==0) return 1;
    return n * factorialrecrusion(n-1);
}

int Fibonacci(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    return Fibonacci(n-1) + Fibonacci(n-2);
}

double expolnentialrecrusion(int x, int n){
    if (n==0) return 1;
    else if(n>=0){
        return x * expolnentialrecrusion(x, n-1);
    }
    else{
        int k = -n;
        return 1 / (x*expolnentialrecrusion(x, k-1));
    }
}

int numberscountrecrusion(int n){
    if(n==0) return 0;
    return 1 + numberscountrecrusion(n/10);
}

int numberssumrecrusion(int n){
    if(n==0) return 0;
    return n%10 + numberssumrecrusion(n/10);
}

int numbersreverseresrusion(int n){
    if(n<10) return n;
    return (n%10)*expolnentialrecrusion(10, numberscountrecrusion(n)-1) + numbersreverseresrusion(n/10);
}

int main(){
    cout << "Bai 1: Tinh tong tu 1 den n " << endl
         << "Dau vao n = 5" << endl
         << "Ket qua: " << sumrecrusion(5) << endl
         << endl;
    cout << "Bai 3: Tinh giai thua " << endl
         << "Dau vao n = 5" << endl
         << "Ket qua: " << factorialrecrusion(5) << endl
         << endl;
    cout << "Bai 3: Tinh so Fibonacci thu n " << endl
         << "Dau vao n = 6" << endl
         << "Ket qua: " << Fibonacci(6) << endl
         << endl;
    cout << "Bai 4: Tinh luy thua " << endl
         << "Dau vao x=2, n=3" << endl
         << "Ket qua: " << expolnentialrecrusion(2, 3) << endl
         << endl;
    cout << "Bai 5: Dem so chu cua mot so nguyen " << endl
         << "Dau vao n = 12345" << endl
         << "Ket qua: " << numberscountrecrusion(12345) << endl
         << endl;
    cout << "Bai 6: Tinh tong cac chu so cua mot so nguyen " << endl
         << "Dau vao n = 1234" << endl
         << "Ket qua: " << numberssumrecrusion(1234) << endl
         << endl;
    cout << "Bai 7: Dao nguoc mot so nguyen " << endl
         << "Dau vao n = 1234" << endl
         << "Ket qua: " << numbersreverseresrusion(1234) << endl
         << endl;
    cout << "TONG HOP BAI TU 1 DEN 7 :333";
    return 0;
}
