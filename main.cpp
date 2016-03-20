#include "triangles.h"

#include<iostream>
using std::cout;
using std::endl;

int main(void) {
	// TODO: write some code to test out your program.
	// This won't be graded- it is just for your benefit
	// and to aid your testing / debugging.
	triangle a = triangle(3,4,5);
	triangle b = triangle(4,5,6);
	triangle c = triangle(9,15,12);
	cout << "Perimeter t1 = " << a.perimeter() << endl << "Area t1 = " << a.area() << endl;
	cout << "Perimeter t2 = " << b.perimeter() << endl << "Area t2 = " << b.area() << endl;
	cout << "Congruent or na = " << congruent(a,b) << endl;
	cout << "Are they similar tho = " << similar(a,c) << endl;
	findRightTriangles(100,300);

	return 0;
}
