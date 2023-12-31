#pragma once 

#include <vector>
#include "gauss.h"
#include <cmath>

double function1(const double& x1, const double& x2) {
    return x1 - x2 - 6*log10(x1) - 1;
}

double function2(const double& x1, const double& x2) {
    return x1 - 3*x2 - 6*log10(x2)-2;
}

double getD1(const vector<double>& x) {
    double f1 = function1(x[0], x[1]);
    double f2 = function2(x[0], x[1]);
    if(abs(f1)> abs(f2)){
        return abs(f1);
    }else{
        return abs(f2);
    }
}

double getD2(const vector<double>& x, const vector<double>& xKplus1) {
    double max = 0;
    for (int i = 0; i < x.size(); i++) {
        if (abs(xKplus1[i]) < 1) {
            if (abs(xKplus1[i] - x[i]) > max)
                max = abs(xKplus1[i] - x[i]);
        } else {
            if (abs((xKplus1[i] - x[i]) / xKplus1[i]) > max)
                max = abs((xKplus1[i] - x[i]) / xKplus1[i]);
        }
    }
    return max;
}



double J1Dx01(const double& x1, const double& x2) {
    return 1 - 6/(x1*log(10));
}

double J1Dx02(const double& x1, const double& x2) {
    return -1;
}

double J2Dx01(const double& x1, const double& x2) {
    return 1;
}
 
double J2Dx02(const double& x1, const double& x2) {
    return -3 - 6/(x2*log(10));
}

void jakobianMethod1(vector<vector<double>>& matrix, const vector<double>& x) {
    matrix[0][0] = J1Dx01(x[0], x[1]);
    matrix[0][1] = J1Dx02(x[0], x[1]);
    matrix[1][0] = J2Dx01(x[0], x[1]);
    matrix[1][1] = J2Dx02(x[0], x[1]);
}

void jakobianMethod2(vector<vector<double>>& matrix, const vector<double>& x, const double& M) {
    matrix[0][0] = (function1(x[0] + M * x[0], x[1]) - function1(x[0], x[1])) / (M * x[0]);
    matrix[0][1] = (function1(x[0], x[1] + M * x[1]) - function1(x[0], x[1])) / (M * x[1]);
    matrix[1][0] = (function2(x[0] + M * x[0], x[1]) - function2(x[0], x[1])) / (M * x[0]);
    matrix[1][1] = (function2(x[0], x[1] + M * x[1]) - function2(x[0], x[1])) / (M * x[1]);
}