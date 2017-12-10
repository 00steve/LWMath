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




/*
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

    [100112]⋅⎡⎣⎢3−1250−1⎤⎦
    */

/*
    LWMatrix<double> m = LWMatrix<double>(3,1,new double[3]{1,4,0});
    LWMatrix<double> m1 = LWMatrix<double>(1,3,new double[3]{2,-1,5});
    m.Print();
    m1.Print();
    //LWMatrix<double> AB = m*m1;
    LWMatrix<double> BA = m1*m;
    //AB.Print();
    BA.Print();
*/
    /*

    LWMatrix<double> a = LWMatrix<double>(3,2,new double[6]{1,0,2,-1,1,0});
    LWMatrix<double> b = LWMatrix<double>(2,3,new double[6]{1,4,2,5,3,6});
    LWMatrix<double> x = LWMatrix<double>(1,3,new double[3]{3,2,1});
    LWMatrix<double> i = LWMatrix<double>(3,3,new double[9]{1,0,0,0,1,0,0,0,1});

    a.Print();
    b.Print();
    x.Print();
    i.Print();

    LWMatrix<double> ax = a*x;
    ax.Print();
    LWMatrix<double> ix = i*x;
    ix.Print();
    LWMatrix<double> ab = a*b;
    ab.Print();
    LWMatrix<double> ib = i * b;
    ib.Print();
    */

    /*
    //https://www.youtube.com/watch?v=DM6ILHA8aWU
    LWMatrix<double> a = LWMatrix<double>(2,2,new double[6]{1,3,2,4});
    LWMatrix<double> b = LWMatrix<double>(2,2,new double[6]{5,6,7,8});
    a.Print();
    b.Print();

    LWMatrix<double> ab = a * b;
    ab.Print();
    LWMatrix<double> ba = b * a;
    ba.Print();*/


    /*
    //transpose testing

        LWMatrix<int> a = LWMatrix<int>(2,4,new int[8]{5,4,4,0,7,10,-1,8});
    a.Print();
    LWMatrix<int> b = a.Transpose();
    b.Print();


    LWMatrix<int> c = LWMatrix<int>(3,3,new int[9]{0,1,2,3,4,5,6,7,8});
    c.Print();
    LWMatrix<int> d = c.Transpose();
    d.Print();


    LWMatrix<int> e = LWMatrix<int>(6,2,new int[12]{1,2,3,4,5,6,-1,-2,-3,-4,-5,-6});
    e.Print();
    LWMatrix<int> f = e.Transpose();
    f.Print();

    */

    /*//addition and subtraction
        LWMatrix<float> a = LWMatrix<float>(3,3,new float[9]{5,4,3,4,0,4,7,10,3});
    LWMatrix<float> b = LWMatrix<float>(3,3,new float[9]{1,-2,3,4,5,6,7,8,9});

    LWMatrix<float> r = a-b;

    r.Print();

    LWMatrix<float> x = LWMatrix<float>(2,1,new float[2]{-3,4});
    LWMatrix<float> y = LWMatrix<float>(2,1,new float[2]{5,-2});

    LWMatrix<float> v = y+x;

    v.Print();


    */



    return true;
};



#endif // LWMatrix_test_H
