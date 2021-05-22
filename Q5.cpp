// CS 115 Final Exam -- U of R Fall 2020
// Solution for Question 5
// Instructor: Gurmail Singh
// Student Name:
// Student ID:

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// DO NOT EDIT AREA -- BEGIN
class matrix {
public:
	matrix(int m[2][2]);
	matrix operator=(int m[2][2]);
	matrix operator+(matrix &m);
	matrix operator-(matrix &m);
	int g[2][2]; // value storage
};
// constructor -- an easy way to get all 4 values in at once
matrix::matrix(int m[2][2]) {
	g[0][0] = m[0][0];
	g[0][1] = m[0][1];
	g[1][0] = m[1][0];
	g[1][1] = m[1][1];
}
// assignment operator -- takes new matrix in, assigns itself to it, and returns itself
matrix matrix::operator=(int m[2][2]) {
	g[0][0] = m[0][0];
	g[0][1] = m[0][1];
	g[1][0] = m[1][0];
	g[1][1] = m[1][1];
	return *this; // returns poinater to itself
}
// helper function to print contents of some named matrix
void printMatrix(matrix M, string name) {
	cout << endl << "The [" << name << "] matrix is:" << endl;
	cout << M.g[0][0] << " " << M.g[0][1] << endl;
	cout << M.g[1][0] << " " << M.g[1][1] << endl;
	return;
}
// DO NOT EDIT AREA -- END

// TO DO: the two functions to overload + and - operations
matrix matrix::operator+(matrix &m) {
	int z[2][2] = { { 0,0 } ,{ 0,0 } }; // zero matrix
	matrix C(z); // the dummy matrix to be returned

	// calculate C = A + B
	for(int i=0;i<2;i++)
		for (int j = 0; j < 2; j++)
		{
			C.g[i][j] = g[i][j] + m.g[i][j];
		}

	return C; // return the calculated matrix
}

matrix matrix::operator-(matrix &m) {
	int z[2][2] = { { 0,0 } ,{ 0,0 } }; // zero matrix
	matrix C(z); // the dummy matrix to be returned

	// calculate C = A - B
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
		{
			C.g[i][j] = g[i][j] - m.g[i][j];
		}

	return C; // return the calculated matrix
}

int main() {
	int z[2][2] = { {0,0} ,{0,0} }; // zero matrix
	int a[2][2] = { { 1,2 } ,{ 3,4 } }; // first matrix values
	int b[2][2] = { { 5,6 } ,{ 7,8 } }; // second matrix values
	matrix result1(z), result2(z), first(a), second(b); // initialize matrices

	printMatrix(first, "first");
	printMatrix(second, "second");

	cout << "Now calculating the resulting matrices..." << endl;

	// you should be able to uncomment two lines below and run successfully

	 result1 = first + second;
	 result2 = first - second;

	// and then the resulting matrices will be printed with correct values

	printMatrix(result1, "result1");
	printMatrix(result2, "result2");
	printMatrix(first, "first");
	printMatrix(second, "second");

	cin.ignore();
	cin.get();
	return 0;
}
