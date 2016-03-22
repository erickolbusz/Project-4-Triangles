#include "triangles.h"

#include<iostream>
using std::cout;
using std::endl;

int main(void) {
	// TODO: write some code to test out your program.
	// This won't be graded- it is just for your benefit
	// and to aid your testing / debugging.
	triangle a = triangle(11,13,17);
	triangle b = triangle(17,11,13);
	triangle c = triangle(9,15,12);
	cout << "Perimeter t1 = " << a.perimeter() << endl << "Area t1 = " << a.area() << endl;
	cout << "Perimeter t2 = " << b.perimeter() << endl << "Area t2 = " << b.area() << endl;
	cout << "Congruent or na = " << congruent(a,b) << endl;
	cout << "Are they similar tho = " << similar(a,c) << endl;
	cout << "Triangles that have perimeter between 20 and 50:\n";
	vector<triangle> retval=findRightTriangles(20,50);
	for(int i =0; i<retval.size();i++){
		retval[i].print();
		cout << "\n";
	}
	cout << "Triangles that have perimeter between 10020 and 10100:\n";
	retval = findRightTriangles(10020,10100);
	for(int i =0; i<retval.size();i++){
		retval[i].print();
		cout << "\n";
	}
	return 0;
}
