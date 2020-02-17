#include "global.h"
#include "Polinom.h"

int main () {
    int n;
    cout << "Input Derajat: ";
    cin >> n;
    cout << endl;

    Polinom A(n);
    Polinom B(n);

    // cout << "Input polinom A:" << endl;
    // A.InputPolinom();
    // cout << "Input polinom B:" << endl;
    // B.InputPolinom();

    A.GeneratePolinom(16518380);
    B.GeneratePolinom(13518093);

    // cout << "Polinom A:" << endl;
    // A.PrintPolinom();
    // cout << endl;
    // cout << "Polinom B:" << endl;
    // B.PrintPolinom();
    // cout << endl;
    // cout << endl;

    addOp = 0;
    mulOp = 0;
    cout << "Hasil Bruteforce:" << endl;
    clock_t start = clock();    // start timer
    Polinom C = bruteMultiply(A, B);
    // C.PrintPolinom();
    // cout << endl;
    cout << "Operasi tambah: " << addOp << endl;
    cout << "Operasi kali: " << mulOp << endl;
    cout << "Time needed: " << fixed << setprecision(5) << (clock()-start)*1./CLOCKS_PER_SEC << endl;

    cout << endl;
    addOp = 0;
    mulOp = 0;
    cout << "Hasil Divide and Conquer:" << endl;
    Polinom D = dncMultiply(A, B);
    // D.PrintPolinom();
    // cout << endl;
    start = clock();    // start timer
    cout << "Operasi tambah: " << addOp << endl;
    cout << "Operasi kali: " << mulOp << endl;
    cout << "Time needed: " << fixed << setprecision(5) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}