#ifndef INTMATRIX_H_
#define INTMATRIX_H_

class IntMatrix {
	int* matrixarr;
	int width, height;
public:
	IntMatrix();
	IntMatrix(int*, int, int);
	~IntMatrix();

	int getwidth();
	int getheight();
	int getelem();
	int setelem();

	IntMatrix operator +(IntMatrix);
	IntMatrix operator -(IntMatrix);
	IntMatrix operator *(int);
	IntMatrix operator *(IntMatrix);
	IntMatrix operator /(int);
};

#endif // !"INTMATRIX_H_"

