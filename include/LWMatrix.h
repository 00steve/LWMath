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
    LWMatrix operator *(LWMatrix o){
        if(columnCount != o.rowCount) return LWMatrix<T>(0,0,new T[0]{});


        LWMatrix p = LWMatrix(o.columnCount,rowCount);
        y = 0;
        i = 0;
        while(y < rowCount){
            x = 0;
            p[i] = 0;
            while(x < o.columnCount){
                cout << cell[y] << "*" << o.cell[x] << endl;
                p[i++] += cell[y]*o.cell[x];
                ++x;
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


};






#endif // LWMATRIX_H
