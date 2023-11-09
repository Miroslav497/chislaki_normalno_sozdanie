#pragma once

#include <iomanip>
#include <vector>
#include <iostream>
using namespace std;

/*void Swap(const int &line1, const int &line2, vector<vector<double>>& a);

void method_Gaus(vector<vector<double>>& matrix, int N, int M);
void print(const vector<vector<double>>& matrix, int N, int M);
void print_vec(const vector<double>& vec);
void otvet(const vector<vector<double>>& matrix, int N, int M, vector<double>& F);
double vector_n(const vector<double>& F, const vector<vector<double>>& orig_mat, vector<double>& B2,vector<double>& B,vector<double>& Br,const int N);
double relative_error(const vector<double>& F, vector<vector<double>>& orig_mat, vector<double>& B2,vector<double>& F2,const int N,const int M);*/
//#include "fun.h"


void Swap(const int &line1, const int &line2, vector<vector<double>>& a) {
    vector<double> tmp = a[line1];
    a[line1] = a[line2];
    a[line2] = tmp;
}

void method_Gaus(vector<vector<double>>& matrix){
    int N = matrix.size();
    int M = matrix[0].size();
    for (int i = 0; i < N - 1; i++) {
        double tmp = 0;
        if (matrix[i][i] == 0) {
            for (int j = i + 1; j < N; j++) {
                if (matrix[j][i] != 0) {
                    Swap(i, j, matrix);
                    break;
                }
            }
        }

        for (int k = i + 1; k < N; k++) {
            tmp = matrix[k][i] / matrix[i][i];
            for (int j = i; j < M; j++) {
                matrix[k][j] = matrix[k][j] - matrix[i][j] * tmp;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        double dE = matrix[i][i];
        for (int j = i; j < M; j++) {
            matrix[i][j] /= dE;
        }
    }

}

void print(const vector<vector<double>>& matrix, int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << setw(8) << setprecision(2) << matrix[i][j];
        }
        cout << endl;
    }
    cout << endl << endl;
}
void print_vec(const vector<double>& vec){
    cout<<"{";
    for(int i = 0;i<vec.size();i++){
        cout<<vec[i]<<", ";
    }
    cout<<"}"<<endl;
}

void otvet(const vector<vector<double>>& matrix, vector<double>& F) {
    int N = matrix.size();
    int M = matrix[0].size();

    for (int i = N - 1; i >= 0; i--) {
        double sum = matrix[i][M - 1];
        for (int j = i + 1; j < N; j++) {
            sum -= matrix[i][j] * F[j];
        }
        F[i] = sum / matrix[i][i];
    }
    /*for (int i = 0; i < N; i++) {
        cout << "x" << i + 1 << ": " << F[i] << endl;
    }*/
}

double vector_n(const vector<double>& F, const vector<vector<double>>& orig_mat, vector<double>& B2,vector<double>& B,vector<double>& Br,const int N) {
    for (int i = 0; i < N; i++) {
        double sum = 0;
        for (int j = 0; j < N; j++) {
            sum += F[j] * orig_mat[i][j];
        }
        B2[i] = sum;
        Br[i] = B[i]-B2[i];
    }
    double norma = Br[0];
    for(int i = 0;i < Br.size();i++){
        if(norma<abs(Br[i]))norma = Br[i];
    }
    return norma;
}

double relative_error(const vector<double>& F, vector<vector<double>>& orig_mat, vector<double>& B2,vector<double>& F2){
    for(int i = 0; i<orig_mat.size();i++){
        orig_mat[i][orig_mat.size()] = B2[i];
    }
    method_Gaus(orig_mat);
    otvet(orig_mat,F2);

    double max_d = abs(F2[0]-F[0]);
    double max_x = abs(F[0]);
    for(int i = 1;i < F2.size();i++){
        if(max_d<abs(F2[i]-F[i])){
            max_d = abs(F2[i]-F[i]);
        }
        if(max_x < abs(F[i])){
            max_x = abs(F[i]);
        }
    }
    return max_d/max_x;
}