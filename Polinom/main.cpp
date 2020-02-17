#include "Polinom.h"

int main () {
    int n;
    cout << "Derajat: ";
    cin >> n;
    cout << "Input polinom A:" << endl;
    Polinom A(n);
    A.InputPolinom();
    cout << "Input polinom B:" << endl;
    Polinom B(n);
    B.InputPolinom();

    cout << "Hasil Bruteforce:" << endl;
    Polinom C = bruteMultiply(A, B);
    C.PrintPolinom();
    cout << endl;

    cout << "Hasil Divide and Conquer:" << endl;
    Polinom D = dncMultiply(A, B);
    D.PrintPolinom();
    cout << endl;
    return 0;
}