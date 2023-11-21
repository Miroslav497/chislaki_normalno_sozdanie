#pragma once

#include <cmath>
#include <iostream>
using namespace std;

double function(double x){
    return pow(x*x*x - 1, -0.5);
}
double fun(const double& x, const double& y){
    return sin(x+y);
}