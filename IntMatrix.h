#ifndef INTMATRIX_H_
#define INTMATRIX_H_

class IntMatrix {
	int* matrixarr;						// matrix array
	int width, height;					// dimesniosn
public:
	IntMatrix();						// initializes empty array, and 0 dimensions
	IntMatrix(int, int);				// initializes array with given width and height
	IntMatrix(int*, int, int);			// initializes array with given array, width, and height
	~IntMatrix();

	int getwidth();						
	int getheight();
	void setwidth(int);
	void setheight(int);
	int getelem(int, int);				// gets element from matrixarr, coordinates given in function params
	void setelem(int, int, int);		// sets given value in matrixarr in given coordinates
	void read();						// prints whole matrix
	void write(int*);			// writes whole matrix to memory

	
	IntMatrix operator +(IntMatrix&);
	IntMatrix operator -(IntMatrix);
	IntMatrix operator *(int);
	IntMatrix operator *(IntMatrix);
	void operator =(IntMatrix&);


};

#endif // !"INTMATRIX_H_"

