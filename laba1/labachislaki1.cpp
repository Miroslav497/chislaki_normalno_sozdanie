#include <iostream>
#include <iomanip>
#include <vector>
#include "fun.h"
using namespace std;

int main() {
    const int N = 3, M = 4;

    vector<vector<double>> matrix(N, vector<double>(M));
    vector<double> B = {1.0, 1.0, 2.0};
    vector<double> B2(N), Br(N);

    vector<vector<double>> orig_mat(N, vector<double>(M));

    matrix[0] = { 1.0, 2.0, 1.0, 1.0 };
    matrix[1] = { -1.0, -2.0, 2.0, 1.0 };
    matrix[2] = { 0, 1.0, 1.0, 2.0 };
    

    orig_mat = matrix;

    print(matrix, N, M);

    method_Gaus(matrix,N,M);

    print(matrix, N, M);
    vector<double> F(N);
    vector<double> F2(N);
    otvet(matrix, N, M, F);

    for (int i = 0; i < F.size(); i++){
        cout << "x" << i + 1 << ": " << F[i] << endl;
    }

    cout<<"Норма вектора невязки:"<<vector_n(F,orig_mat,B2,B,Br,N)<<endl;
    print_vec(Br);
    cout<<"относительная погрешность:"<<relative_error(F,orig_mat,B2,F2,N,M)<<endl;
}
