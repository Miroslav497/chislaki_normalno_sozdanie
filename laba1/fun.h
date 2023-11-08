#pragma once

#include <iomanip>
#include <vector>
#include <iostream>
// #include "fun.h"
using namespace std;

void Swap(const int &line1, const int &line2, vector<vector<double>>& a);

void method_Gaus(vector<vector<double>>& matrix, int N, int M);
void print(const vector<vector<double>>& matrix, int N, int M);
void print_vec(const vector<double>& vec);
void otvet(const vector<vector<double>>& matrix, int N, int M, vector<double>& F);
double vector_n(const vector<double>& F, const vector<vector<double>>& orig_mat, vector<double>& B2,vector<double>& B,vector<double>& Br,const int N);
double relative_error(const vector<double>& F, vector<vector<double>>& orig_mat, vector<double>& B2,vector<double>& F2,const int N,const int M);