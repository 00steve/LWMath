#ifndef LWVector_H
#define LWVector_H


template<class T>
class LWVector2{
private:
    T x;
    T y;


public:

    LWVector2(T x,T y) :
        x(x),
        y(y) {
    }

    void Print(){
        cout << "(" << x << "," << y << ")\n";
    }


    T operator *(const LWVector2 o){
        T m = atan2()
    }


    LWVector2 operator +(const LWVector2 o){
        return LWVector2(x+o.x,y+o.y);
    }

    LWVector2 operator -(const LWVector2 o){
        return LWVector2(x-o.x,y-o.y);
    }


};


#endif
