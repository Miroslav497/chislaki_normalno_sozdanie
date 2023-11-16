#include <iostream>
#include "function.h"
#include "TrapezoidMethod.h"
#include "Simpson.h"
#include <iomanip>

using namespace std;

int main(){
    int N = 25;
    double a = 1.3;
    double b = 2.621;
    double e1 = 1e-4;
    double e2 = 1e-5;

    cout <<"TrapezoidalMethod: " << endl;
    cout << setprecision(20) << "I: " << TrapezoidMethod(a,b,function,e1) <<endl;
    cout << "SimpsonMethod: " << endl;
    cout << setprecision(20) <<"I: " << Simpson(a,b,function,e2) << endl;
    return 0;
}