#ifndef __POLINOM_H__
#define __POLINOM_H__

#include "global.h"
#include <bits/stdc++.h>

using namespace std;

struct Polinom {
    int derajat;
    vector<int> v;
    Polinom(int n);
    Polinom& operator=(const Polinom& P);
    void GeneratePolinom(int seed);
    void InputPolinom();
    void PrintPolinom();
};

Polinom bruteMultiply(Polinom A, Polinom B);
Polinom add(Polinom A, Polinom B);
Polinom sub(Polinom A, Polinom B);
Polinom dncMultiply(Polinom A, Polinom B);

#endif