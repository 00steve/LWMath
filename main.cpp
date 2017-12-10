#include <iostream>

#include "include/LWMatrix_test.h"

using namespace std;

int main(){

    //LWMatrx_test();

    LWMatrix<int> a = LWMatrix<int>(2,4,new int[8]{5,4,4,0,7,10,-1,8});
    a.Print();
    LWMatrix<int> b = a.Transpose();
    b.Print();

    return 0;
}
