#ifndef __POLINOMDNC_H__
#define __POLINOMDNC_H__

#include "global.h"
#include <bits/stdc++.h>

using namespace std;

struct PolinomDNC {
    int derajat;
    vector<int> v;
    PolinomDNC(int n);
    PolinomDNC& operator=(const PolinomDNC& P);
    void GeneratePolinom(int seed);
    void InputPolinom();
    void PrintPolinom();
};

PolinomDNC bruteMultiply(PolinomDNC A, PolinomDNC B);
PolinomDNC add(PolinomDNC A, PolinomDNC B);
PolinomDNC sub(PolinomDNC A, PolinomDNC B);
PolinomDNC dncMultiply(PolinomDNC A, PolinomDNC B);

#endif