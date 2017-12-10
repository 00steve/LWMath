#include <iostream>

#include "include/LWMatrix_test.h"
#include "include/LWVector2_test.h"

using namespace std;

int main(){

    //LWMatrx_test();


    LWVector2<int> a = LWVector2<int>(1,2);
    LWVector2<int> b = LWVector2<int>(9,-10);

    LWVector2<int> s = a-b;

    s.Print();


    return 0;
}
