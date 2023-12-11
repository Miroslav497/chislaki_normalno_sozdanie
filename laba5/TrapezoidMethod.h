#pragma once

#include <iostream>
using namespace std;

double TrapezoidMethod(double a,double b,double fun(double),double e){
    int N = 2;
    double h = (b - a)/N;
    double xi;
    double sum = 0;
    double I1 = fun(a) + fun(b);
    double I2;
    do {
        I2 = I1;
        N *= 2;
        h = (b - a) / N;
        xi = a;
        sum = 0;
        for (int i = 0; i < N-1; i++) {
            xi += h;
            sum += fun(xi);
        }
        I1 = (fun(a) + fun(b) + 2 * sum )* (h / 2);
    } while (abs(I1 - I2) >= 3 * e);
    

    return I1;
}