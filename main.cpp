#include <iostream>

#include "include/LWMatrix_test.h"

using namespace std;

int main(){

    LWMatrx_test();


    LWMatrix<double> m = LWMatrix<double>(3,1,new double[3]{1,2,3});
    LWMatrix<double> m1 = LWMatrix<double>(1,3,new double[3]{4,5,6});

    m.Print();
    m1.Print();

    LWMatrix<double> AB = m*m1;
    LWMatrix<double> BA = m1*m;

    cout << m[0] << endl;
    m[0] = 10;
    cout << m[0] << endl;

    AB.Print();
    BA.Print();

    return 0;
}
