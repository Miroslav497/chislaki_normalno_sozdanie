#pragma once

#include <iomanip>
#include <vector>
#include <iostream>
using namespace std;

void Swap(const int &line1, const int &line2, vector<vector<double>>& a) {
    vector<double> tmp = a[line1];
    a[line1] = a[line2];
    a[line2] = tmp;
}

void method_Gaus(vector<vector<double>>& matrix, int N, int M) {
    for (int k = 0; k < N - 1; k++) {
        double koef = 0;
        if (matrix[k][k] == 0) {
            for (int i = k + 1; i < N; i++) {
                if (matrix[i][k] != 0) {
                    Swap(k, i, matrix);
                    break;
                }
            }
        }
        for (int i = k + 1; i < N; i++) {
            koef = matrix[i][k] / matrix[k][k];
            for (int j = k; j < M; j++) {
                matrix[i][j] = matrix[i][j] - matrix[k][j] * koef;
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

void otvet(vector<vector<double>>& matrix, int N, int M, vector<double>& B) {
    method_Gaus(matrix, N, M);
    B[N - 1] = matrix[N - 1][M - 1];
    for (int i = N - 2; i > -1; i--) {
        double sum = 0;
        for (int k = i + 1; k < N; k++) {
            sum += matrix[i][k] * B[k];
        }
        B[i] = matrix[i][N] - sum;
    }
}

