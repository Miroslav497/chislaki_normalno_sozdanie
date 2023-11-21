#include <iostream>
#include "function.h"
#include "TrapezoidMethod.h"
#include "Simpson.h"
#include "KubSimpson.h"
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
    double a = 1.3;
    double b = 2.621;
    double e1 = 1e-4;
    double e2 = 1e-5;

    cout <<"Метод трапеций: " << endl;
    cout << setprecision(10) << "I: " << TrapezoidMethod(a,b,function,e1) <<endl;
    cout << "Метод симпсона: " << endl;
    cout << setprecision(10) <<"I: " << Simpson(a,b,function,e2) << endl;

    double ak = 0;
    double bk = M_PI/2;
    double ck = 0;
    double dk = M_PI/4;
    int m,n;
    cout<<"Введите уточнение m и n"<<endl;
    cin>>m>>n;
    cout <<"Кубатрный метод Симпсона: " << endl;
    cout << setprecision(10) << "I: " << KubSimpson(m,n,ak,bk,ck,dk,fun) <<endl;
    
}