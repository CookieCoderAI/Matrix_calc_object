#include <iostream>
#include "IntMatrix.h"

int main(){
    int arr[9] = { 1,2,3,4,5,6,7,8,9 };
    IntMatrix matrix(arr, 3, 3), matrix2(3,3), matrix3(3,3);
    matrix2.write(arr);
    matrix.read();
    matrix2.read();

    std::cout << &matrix << "   " << &matrix2;
 
    matrix + matrix2;
}
