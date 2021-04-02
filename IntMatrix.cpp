#include "IntMatrix.h"
#include <iostream>

IntMatrix::IntMatrix() {
	matrixarr = new int[0];
	width = 0;
	height = 0;
}
IntMatrix::IntMatrix(int width_, int height_) {
	matrixarr = new int[width_ * height_];
	width = width_;
	height = height_;
}
IntMatrix::IntMatrix(int* matrixarr_, int width_, int height_) {
		width = width_;
		height = height_;
		matrixarr = new int[width * height];
		this->write(matrixarr_);
}
IntMatrix::~IntMatrix() {
	delete[] matrixarr;
}

int IntMatrix::getwidth() { return width; }
int IntMatrix::getheight() { return height; }
void IntMatrix::setwidth(int width_) { width = width_; }
void IntMatrix::setheight(int height_) { height = height_; }

int IntMatrix::getelem(int width_, int height_){
	if (width_ <= width && height >= height_) {
		return *(matrixarr + width_ + (width * height_));
	}
	std::cout << "Exception: 0x0001 at IntMatrix::getelem(), given dimensons aren't valid;" << std::endl;
	return 0;
}
void IntMatrix::setelem(int value_, int width_, int height_){
	*(matrixarr + width_ + (width * height_)) = value_;
}
void IntMatrix::read() {
	std::cout << std::endl;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			std::cout << "	" << this->getelem(j, i) << "	";
		}
		std::cout << std::endl;
	}
}
void IntMatrix::write(int* arr_) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			this->setelem(*(arr_ + j + (width * i)),j, i);
		}
	}
}

IntMatrix IntMatrix::operator +(IntMatrix& rhs) {
	if (rhs.getheight() == this->getheight() && rhs.getwidth() == this->getwidth()) {
		int* arr = new int[rhs.getheight() * rhs.getwidth()];
		for (int i = 0; i < this->getheight(); i++) {
			for (int j = 0; j < this->getwidth(); j++) {
				*(arr + j + (width * i)) = this->getelem(j, i) + rhs.getelem(j, i);
			}
		}
		return IntMatrix(arr, this->getheight(), this->getheight());
	}
}

void IntMatrix::operator =(IntMatrix& rhs) {
	if (rhs.getheight() == this->getheight() && rhs.getwidth() == this->getwidth()) {
		int* arr = new int[rhs.getheight() * rhs.getwidth()];
		for (int i = 0; i < this->getheight(); i++) {
			for (int j = 0; j < this->getwidth(); j++) {
				this->setelem(rhs.getelem(j, i), j, i);
			}
		}
	}
}