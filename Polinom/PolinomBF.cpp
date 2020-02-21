#include "global.h"
#include "PolinomBF.h"

PolinomBF::PolinomBF(int n) {
    derajat = n;
    v.resize(n+1);
    for (int i=0;i<=derajat;i++) v[i] = 0;
}

PolinomBF& PolinomBF::operator=(const PolinomBF& P) {
    derajat = P.derajat;
    for (int i=0;i<=derajat;i++) {
        v[i] = P.v[i];
    }
    return *this;
}

void PolinomBF::GeneratePolinom(int seed) {
    mt19937 mt_rand(seed);
    uniform_int_distribution<int> distribution(-1000,1000);
    for (int i=0;i<=derajat;i++) {
        v[i] = distribution(mt_rand);
    }
}

void PolinomBF::InputPolinom() {
    for (int i=0;i<=derajat;i++) cin >> v[i];
}

void PolinomBF::PrintPolinom() {
    for (int i=0;i<=derajat;i++) {
        if (i > 0 && v[i] >= 0) cout << " + ";
        if (v[i] < 0) cout << " - ";
        cout << abs(v[i]);
        if (i > 0) cout << "x";
        if (i > 1) cout << "^" << i;
    }
}

PolinomBF bruteMultiply(PolinomBF A, PolinomBF B) {
    PolinomBF C(A.derajat + B.derajat);
    for (int i=0;i<=A.derajat;i++) {
        for (int j=0;j<=B.derajat;j++) {
            C.v[i+j] += A.v[i]*B.v[j];
            mulOp++;
            addOp++;
        }
    }
    return C;
}