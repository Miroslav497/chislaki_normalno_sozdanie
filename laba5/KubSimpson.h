#pragma once

#include <vector>
#include <iostream>
using namespace std;

double KubSimpson(const double& m,const double& n,const double& a, const double& b,const double& c, const double& d, double function(const double&, const double&)){
    double hx = (b-a)/(2*n);
    double hy = (d-c)/(2*m);
    double sum = 0.0;
    double I = 0.0;
    double xi = a;
    double yi = c;

    vector<double> Xi;
    do{
        Xi.push_back(xi);
        xi+=hx;
    } while (xi <= b);
    vector<double> Yi;
    do{
        Yi.push_back(yi);
        yi+=hy;
    } while (yi <= d);

    for(int i = 0; i< n; i++){
        for(int j=0; j<m; j++){
            sum+=function(Xi[2*i],Yi[2*j])+function(Xi[2*i+2],Yi[2*j])+function(Xi[2*i],Yi[2*j+2])+function(Xi[2*i+2],Yi[2*j+2])
            +4*function(Xi[2*i+1],Yi[2*j])+4*function(Xi[2*i],Yi[2*j+1])+4*function(Xi[2*i+2],Yi[2*j+1])+4*function(Xi[2*i+1],Yi[2*j+2])
            +16*function(Xi[2*i+1],Yi[2*j+1]);
        }
    }
    I+=sum;
    I*=((hx*hy)/9);
    return I;
}