#include "global.h"
#include "PolinomBF.h"
#include "PolinomDNC.h"

int main () {
    int n;
    cout << "Input Derajat: ";
    cin >> n;
    cout << endl;

    PolinomBF A(n);
    PolinomBF B(n);

    A.GeneratePolinom(16518380);
    B.GeneratePolinom(13518093);

    addOp = 0;
    mulOp = 0;
    cout << "Hasil Bruteforce:" << endl;
    clock_t start = clock();    // start timer
    PolinomBF C = bruteMultiply(A, B);
    // C.PrintPolinom();
    // cout << endl;
    cout << "Operasi tambah: " << addOp << endl;
    cout << "Operasi kali: " << mulOp << endl;
    cout << "Time needed: " << fixed << setprecision(5) << (clock()-start)*1./CLOCKS_PER_SEC*1000 << endl;

    cout << endl;
    cout << "Hasil Divide and Conquer:" << endl;
    PolinomDNC A2(n);
    PolinomDNC B2(n);
    addOp = 0;
    mulOp = 0;
    A2.GeneratePolinom(16518380);
    B2.GeneratePolinom(13518093);

    start = clock();    // start timer
    PolinomDNC C2 = dncMultiply(A2, B2);
    // C2.PrintPolinom();
    // cout << endl;
    cout << "Operasi tambah: " << addOp << endl;
    cout << "Operasi kali: " << mulOp << endl;
    cout << "Time needed: " << fixed << setprecision(5) << 1000*(clock()-start)*1./CLOCKS_PER_SEC*1000 << endl;
    return 0;
}