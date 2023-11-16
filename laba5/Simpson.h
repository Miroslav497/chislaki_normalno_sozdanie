#pragma once;

double Simpson(double a, double b, double fun(double),double e){
    int N = 2;
    double sumCH = 0;
    double sumNeCH = 0;
    double h = (b-a)/N;
    double I1 = fun(a)+fun(b);
    double xi = a;
    double I2;
    do{
        I2 = I1;
        N *= 2;
        h = (b - a)/N;
        xi = a + h;
        sumNeCH = 0;
        sumCH = 0;
        for(int i = 0;i<N;i++){
            if((i%2)==0){sumCH += fun(xi);}
            else{sumNeCH += fun(xi);}
            xi += h;
        }
        I1 = (h/3)*(fun(a)+fun(b) + 4*sumNeCH+2*sumCH);
    }while(fabs(I1-I2)>15*e);
    return I1;
}