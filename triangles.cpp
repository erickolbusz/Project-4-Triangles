/*
 * CSc103 Project 4: Triangles
 * See readme.html for details.
 * Please list all references you made use of in order to complete the
 * assignment: your classmates, websites, etc.  Aside from the lecture notes
 * and the book, please list everything.  And remember- citing a source does
 * NOT mean it is okay to COPY THAT SOURCE.  What you submit here **MUST BE
 * YOUR OWN WORK**.
 * References:
 * http://stackoverflow.com/questions/9424173/c-find-the-smallest-amongst-3-numbers
 *
 *
 *
 * Finally, please indicate approximately how many hours you spent on this:
 * #hours:
 */

#include "triangles.h" // import the prototypes for our triangle class.
#include <iostream>
using std::cout;
#include <vector>
using std::vector;
#include <algorithm>
using std::sort;
#include <math.h>

// note the "triangle::" part.  We need to specify the function's
// FULL name to avoid confusion.  Else, the compiler will think we
// are just defining a new function called "perimeter"
unsigned long triangle::perimeter() {
	return s1+s2+s3;
}

unsigned long triangle::area() {
	// TODO: write this function.
	// Note: why is it okay to return an integer here?  Recall that
	// all of our triangles have integer sides, and are right triangles...
	return s1*s2/2;
}

void triangle::print() {
	cout << "[" << s1 << "," << s2 << "," << s3 << "]";
}

bool congruent(triangle t1, triangle t2) {
	vector<int> sides_t1, sides_t2;
	sides_t1.push_back(t1.s1);
	sides_t1.push_back(t1.s2);
	sides_t1.push_back(t1.s3);
	sides_t2.push_back(t2.s1);
	sides_t2.push_back(t2.s2);
	sides_t2.push_back(t2.s3);
	sort(sides_t1.begin(), sides_t1.end());
	sort(sides_t2.begin(), sides_t2.end());
	return (sides_t1[0]==sides_t2[0] && sides_t1[1]==sides_t2[1] && sides_t1[2]==sides_t2[2]);
}

bool similar(triangle t1, triangle t2) {
	//if the smaller leg and hypotnuse are similar then the longer leg must also be similar
        double min_t1 = double(std::min(std::min(t1.s1,t1.s2),t1.s3));
        double max_t1 = double(std::max(std::max(t1.s1,t1.s2),t1.s3));
        double min_t2 = double(std::min(std::min(t2.s1,t2.s2),t2.s3));
        double max_t2 = double(std::max(std::max(t2.s1,t2.s2),t2.s3));
	return (max_t2/max_t1 == min_t2/min_t1);
}

vector<triangle> findRightTriangles(unsigned long l, unsigned long h) {
	// TODO: find all the right triangles with integer sides,
	// subject to the perimeter bigger than l and less than h
	vector<triangle> retval; // storage for return value.
	for(unsigned long b=4;b<h/2;b++){
		for(unsigned long a=3;a<b;a++){
			long double c= sqrt(a*a + b*b);
			unsigned long k=c;
			if(k==c){
				triangle temp = triangle(a,b,c);
				//unsigned long perimeter = a+b+c;
				unsigned long perimeter = temp.perimeter();
				if ((perimeter>l)&&(perimeter<h)){
					retval.push_back(temp);
				}
			}
		}
	}
	return retval;
}
