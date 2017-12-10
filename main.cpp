#include <iostream>

#include "include/LWMatrix_test.h"

using namespace std;

int main(){

    //LWMatrx_test();

    LWMatrix<float> a = LWMatrix<float>(3,3,new float[9]{5,4,3,4,0,4,7,10,3});
    LWMatrix<float> b = LWMatrix<float>(3,3,new float[9]{1,-2,3,4,5,6,7,8,9});

    LWMatrix<float> r = a-b;

    r.Print();

    LWMatrix<float> x = LWMatrix<float>(2,1,new float[2]{-3,4});
    LWMatrix<float> y = LWMatrix<float>(2,1,new float[2]{5,-2});

    LWMatrix<float> v = y-x;

    v.Print();

    return 0;
}
