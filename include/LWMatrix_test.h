#ifndef LWMatrix_test_H
#define LWMatrix_test_H

#include "LWMatrix.h"

bool LWMatrx_test(){




    //multiply by single value
    /*
    2×4=8	2×0=0
    2×1=2	2×-9=-18
    */
    int t1a = 2;
    LWMatrix<int> t1b = LWMatrix<int>(2,2,new int[4]{4,0,1,-9});
    LWMatrix<int> t1p = LWMatrix<int>(2,2,new int[4]{8,0,2,-18});
    LWMatrix<int> t1r = t1b * t1a;
    cout << "Multiply by integer : " << (t1p == t1r ? "PASS" : "FAIL") << endl;


    return true;
};



#endif // LWMatrix_test_H
