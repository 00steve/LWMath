#ifndef LWMATRIX_H
#include <iostream>
#include <cstring>

using namespace std;

template <class T>
class LWMatrix {
private:
    unsigned int columnCount;
    unsigned int rowCount;
    unsigned int totalCount;
    T *cell;

    bool valid;
    unsigned int byteSize;

    //internal variables (declare once)
    unsigned int x,y,i;


public:
    LWMatrix(unsigned int columns,unsigned int rows) :
            columnCount(columns),
            rowCount(rows),
            totalCount(columnCount * rowCount),
            cell(new T[totalCount]),
            valid(false),
            byteSize(sizeof(T)*totalCount)
            {
    };

    LWMatrix(unsigned int columns,unsigned int rows,T *values) :
            columnCount(columns),
            rowCount(rows),
            totalCount(columnCount * rowCount),
            cell(values),
            valid(true),
            byteSize(sizeof(T)*totalCount)
            {
    };


    unsigned int ColumnSize(){ return columnCount; }


    void Print(){
        cout << "matrix\n-------------\n";
        cout << "columns : " << columnCount << endl;
        cout << "rows    : " << rowCount << endl;
        cout << "values:" << endl;
        y = 0;
        i = 0;
        while(y < rowCount ){
            x = 0;
            while(x < columnCount){
                cout << "\t[" << cell[i++] << "]";
                ++x;
            }
            cout << endl;
            ++y;
        }
    }


    unsigned int RowSize(){ return rowCount; }


    LWMatrix Transpose(){
        LWMatrix p = LWMatrix<T>(rowCount,columnCount);
        i = 0;//0
        y = 0;//0

        int nmc = 0;
        int omc = 0;
        while(y < rowCount){
            x = 0;//0
            while(x < columnCount){

                p.cell[x*rowCount + y] = cell[i];

                ++i;
                ++x;
            }
            ++y;
        }
        /*
        unsigned int f = 0;
        while(y < rowCount){
            x = 0;//0
            while(x < columnCount){

                p.cell[i] = cell[rowCount * x + y];
                //p.cell[i] = cell[rowCount * y + x];
                //0*4=0+0=0 : 0*2=0+0=0
                //1*4=4+0=4 : 0*2=0+1=1
                //f = columnCount * x

                ++i;
                ++x;
            }
            ++y;
        }
        */
        /*while(i < totalCount){
            p.cell[i] = cell[i];
            ++i;
        }*/
        return p;
    }


    T Value(unsigned int column, unsigned int row){
        return cell[column*columnCount + row];
    }


    T &operator [](unsigned int i){
        return cell[i];
    }


    /*
    You can only multiply two matrices if their dimensions are compatible , which means
    the number of columns in the first matrix is the same as the number of rows in the second matrix.
    */
    LWMatrix operator *(const LWMatrix o){
        if(columnCount != o.rowCount) return LWMatrix<T>(0,0,new T[0]{});
        //create a matrix with a size based on the column count of the left matrix and row count of the right matrix
        LWMatrix p = LWMatrix(o.columnCount,rowCount);
        //loop through rows of left matrix and multiply by columns of right matrix
        i = 0;
        y = 0;
        unsigned int mi = 0;//multiply index
        while(y < rowCount){ //loop through rows of left matrix
            x = 0;
            while(x < o.columnCount){//loop through columns of right matrix
                mi = 0;
                p.cell[i] = 0;
                while(mi < columnCount){
                    p.cell[i] += cell[y*columnCount + mi] * o.cell[mi*o.columnCount + x];
                    ++mi;
                }
                ++x;
                ++i;
            }
            ++y;
        }
        return p;
    }


    LWMatrix operator *(const T f){
        LWMatrix p = LWMatrix(columnCount,rowCount);
        y = 0;
        i = 0;
        while(y < rowCount){
            x = 0;
            while(x < columnCount){
                p.cell[i] = cell[i] * f;
                ++i;
                ++x;
            }
            ++y;
        }
        return p;
    }


    bool operator ==(const LWMatrix o){
        if(columnCount != o.columnCount
        || rowCount != o.rowCount
        || memcmp(cell,o.cell,byteSize) != 0) return false;

        return true;
    }

    LWMatrix operator -(const LWMatrix o){
        if(columnCount != o.columnCount
           || rowCount != o.rowCount) return LWMatrix<T>(0,0,new T[0]{});
        LWMatrix p = LWMatrix<T>(columnCount,rowCount,new T[totalCount]{});
        i = 0;
        while(i < totalCount){
            p.cell[i] = cell[i] - o.cell[i];
            ++i;
        }
        return p;
    }


};






#endif // LWMATRIX_H
