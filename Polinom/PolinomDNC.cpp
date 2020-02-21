#include "global.h"
#include "PolinomDNC.h"

PolinomDNC::PolinomDNC(int n) {
    derajat = n;
    v.resize(n+1);
    for (int i=0;i<=derajat;i++) v[i] = 0;
}

PolinomDNC& PolinomDNC::operator=(const PolinomDNC& P) {
    derajat = P.derajat;
    for (int i=0;i<=derajat;i++) {
        v[i] = P.v[i];
    }
    return *this;
}

void PolinomDNC::GeneratePolinom(int seed) {
    mt19937 mt_rand(seed);
    uniform_int_distribution<int> distribution(-1000,1000);
    for (int i=0;i<=derajat;i++) {
        v[i] = distribution(mt_rand);
    }
}

void PolinomDNC::InputPolinom() {
    for (int i=0;i<=derajat;i++) cin >> v[i];
}

void PolinomDNC::PrintPolinom() {
    for (int i=0;i<=derajat;i++) {
        if (i > 0 && v[i] >= 0) cout << " + ";
        if (v[i] < 0) cout << " - ";
        cout << abs(v[i]);
        if (i > 0) cout << "x";
        if (i > 1) cout << "^" << i;
    }
}

PolinomDNC bruteMultiply(PolinomDNC A, PolinomDNC B) {
    PolinomDNC C(A.derajat + B.derajat);
    for (int i=0;i<=A.derajat;i++) {
        for (int j=0;j<=B.derajat;j++) {
            C.v[i+j] += A.v[i]*B.v[j];
            mulOp++;
            addOp++;
        }
    }
    return C;
}

PolinomDNC add(PolinomDNC A, PolinomDNC B) {
    PolinomDNC C(max(A.derajat, B.derajat));
    for (int i=0;i<=A.derajat;i++) {
        C.v[i] = A.v[i];
    }
    for (int i=0;i<=B.derajat;i++) {
        C.v[i] += B.v[i];
        addOp++;
    }
    return C;
}

PolinomDNC sub(PolinomDNC A, PolinomDNC B) {
    PolinomDNC C(max(A.derajat, B.derajat));
    for (int i=0;i<=A.derajat;i++) {
        C.v[i] = A.v[i];
    }
    for (int i=0;i<=B.derajat;i++) {
        C.v[i] -= B.v[i];
        addOp++;
    }
    return C;
}

PolinomDNC dncMultiply(PolinomDNC A, PolinomDNC B) {
    // Kenapa 2? Karena 1/2-1 = -1 (Out of bounds)
    if (A.derajat <= 2) {
        PolinomDNC C = bruteMultiply(A, B);
        return C;
    }
    PolinomDNC A0(A.derajat/2-1);
    PolinomDNC A1(A.derajat - A.derajat/2);
    PolinomDNC B0(B.derajat/2-1);
    PolinomDNC B1(B.derajat - B.derajat/2);

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

    PolinomDNC X = dncMultiply(add(A0, A1), add(B0, B1));
    PolinomDNC Y = dncMultiply(A0, B0);
    PolinomDNC Z = dncMultiply(A1, B1);

    PolinomDNC V = sub(sub(X, Y), Z);

    PolinomDNC Ret(A.derajat + B.derajat);
    for (int i=0;i<=Y.derajat;i++) {
        Ret.v[i] = Y.v[i];
    }
    for (int i=0;i<=V.derajat;i++) {
        Ret.v[i+A.derajat/2] += V.v[i];
        addOp++;
    }
    for (int i=0;i<=Z.derajat;i++) {
        Ret.v[i+(A.derajat/2)*2] += Z.v[i];
        addOp++;
    }
    return Ret;
}