#include "matrix.hpp"
#include <iostream>
#include <cassert>

void TestAdd()
{
	Matrix m1 = Matrix(5, 5);
	Matrix m2 = Matrix(5, 5);
	
	uint32_t r = m1.GetRows();
	uint32_t c = m1.GetCols();
	for (size_t i = 0; i < r; i++) {
		for (size_t j = 0; j < c; j++) {
			m1[i][j] = 1;
			m2[i][j] = 2;
		}
	}
	
	Matrix m3 = m1 + m2;
	for (size_t i = 0; i < r; i++) {
		for (size_t j = 0; j < c; j++) {
			assert(m3[i][j] == 3);
		}
	}
	std::cout<<"TestMult: Success!"<<std::endl;
}

void TestCmp()
{
	Matrix m1 = Matrix(5, 5);
	Matrix m2 = Matrix(5, 6);
	Matrix m3 = Matrix(5, 5);
	Matrix m4 = Matrix(5, 5);
	for (size_t i = 0; i < 5; i++) {
		for (size_t j = 0; j < 5; j++) {
			m1[i][j] = i + j;
			m2[i][j] = i + j;
			m3[i][j] = i + j;
			m4[i][j] = 0;
		}
	}

	assert(m1 == m3);
	assert(m1 != m2);
	assert(m1 != m4);
	std::cout<<"TestCmp: Success!"<<std::endl;
		
}


void TestOutput(){
	Matrix m1(4,4);
	for (size_t i = 0; i < 4; i++){
		for (size_t j = 0; j < 4; j++) {
			m1[i][j] = 1;
		}
	}

	std::cout<<m1<<std::endl;
}

int main()
{

	TestAdd();
	TestCmp();
	TestOutput();

	return 0;
}
