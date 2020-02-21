#ifndef __POLINOMBF_H__
#define __POLINOMBF_H__

#include "global.h"
#include <bits/stdc++.h>

using namespace std;

struct PolinomBF {
    int derajat;
    vector<int> v;
    PolinomBF(int n);
    PolinomBF& operator=(const PolinomBF& P);
    void GeneratePolinom(int seed);
    void InputPolinom();
    void PrintPolinom();
};

PolinomBF bruteMultiply(PolinomBF A, PolinomBF B);

#endif