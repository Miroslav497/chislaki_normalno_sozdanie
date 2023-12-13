#include <iostream>
#include <iomanip>
#include <vector>
#include "Niuton.h"
using namespace std;


int main() {
    vector<double> MParametr = {0.0, 0.01, 0.05, 0.1};
    for (const double& M : MParametr) {
        cout << "MParametr = " << M << endl;
        NiutonMethod(M);
        cout << "--------------------------" << endl;
    }

    return 0;
}