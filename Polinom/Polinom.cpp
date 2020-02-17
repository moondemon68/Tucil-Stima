#include "Polinom.h"

Polinom::Polinom(int n) {
    derajat = n;
    v.resize(n+1);
    for (int i=0;i<=derajat;i++) v[i] = 0;
}

Polinom& Polinom::operator=(const Polinom& P) {
    derajat = P.derajat;
    for (int i=0;i<=derajat;i++) {
        v[i] = P.v[i];
    }
    return *this;
}

void Polinom::InputPolinom() {
    for (int i=0;i<=derajat;i++) cin >> v[i];
}

void Polinom::PrintPolinom() {
    for (int i=0;i<=derajat;i++) cout << v[i] << " ";
}

Polinom bruteMultiply(Polinom A, Polinom B) {
    Polinom C(A.derajat + B.derajat);
    for (int i=0;i<=A.derajat;i++) {
        for (int j=0;j<=B.derajat;j++) {
            C.v[i+j] += A.v[i]*B.v[j];
        }
    }
    return C;
}

Polinom add(Polinom A, Polinom B) {
    Polinom C(max(A.derajat, B.derajat));
    for (int i=0;i<=max(A.derajat, B.derajat);i++) {
        C.v[i] = A.v[i] + B.v[i];
    }
    return C;
}

Polinom sub(Polinom A, Polinom B) {
    Polinom C(max(A.derajat, B.derajat));
    for (int i=0;i<=A.derajat;i++) {
        C.v[i] = A.v[i];
    }
    for (int i=0;i<=B.derajat;i++) {
        C.v[i] -= B.v[i];
    }
    return C;
}

Polinom dncMultiply(Polinom A, Polinom B) {
    // Kenapa 2? Karena 1/2-1 = -1 (Out of bounds)
    if (A.derajat <= 2) {
        Polinom C = bruteMultiply(A, B);
        return C;
    }
    Polinom A0(A.derajat/2-1);
    Polinom A1(A.derajat - A.derajat/2);
    Polinom B0(B.derajat/2-1);
    Polinom B1(B.derajat - B.derajat/2);
    for (int i=0;i<=A0.derajat;i++) {
        A0.v[i] = A.v[i];
    }
    for (int i=A.derajat/2;i<=A.derajat;i++) {
        A1.v[i-A.derajat/2] = A.v[i];
    }
    for (int i=0;i<=B0.derajat;i++) {
        B0.v[i] = B.v[i];
    }
    for (int i=B.derajat/2;i<=B.derajat;i++) {
        B1.v[i-B.derajat/2] = B.v[i];
    }
    Polinom X = dncMultiply(add(A0, A1), add(B0, B1));
    Polinom Y = dncMultiply(A0, B0);
    Polinom Z = dncMultiply(A1, B1);

    Polinom V = sub(sub(X, Y), Z);
    
    // X.PrintPolinom();
    // cout << endl;
    // Y.PrintPolinom();
    // cout << endl;
    // Z.PrintPolinom();
    // cout << endl;

    // Y.PrintPolinom();
    // cout << endl;
    // V.PrintPolinom();
    // cout << endl;
    // Z.PrintPolinom();
    // cout << endl;

    Polinom Ret(A.derajat + B.derajat);
    for (int i=0;i<=Y.derajat;i++) {
        Ret.v[i] += Y.v[i];
    }
    for (int i=0;i<=V.derajat;i++) {
        Ret.v[i+A.derajat/2] += V.v[i];
    }
    for (int i=0;i<=Z.derajat;i++) {
        Ret.v[i+(A.derajat/2)*2] += Z.v[i];
    }
    return Ret;
}