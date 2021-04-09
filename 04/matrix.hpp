#pragma once
#include <iostream>


class Matrix {
	class ProxyRow {
	public:
		ProxyRow();

        	int32_t& operator[](size_t j);

		void arr_mal(uint32_t cols);

		~ProxyRow();
	private:
		int32_t *data_;
		uint32_t cols_;

    };

    public:
    	Matrix(uint32_t rows, uint32_t cols);

    	ProxyRow& operator[](size_t i);

    	uint32_t GetRows();

    	uint32_t GetCols();

    	Matrix& operator*=(int32_t mult);

   	Matrix operator+(Matrix& other);
	
	bool operator==(Matrix& other);

   	bool operator!=(Matrix& other);

   	friend std::ostream& operator<<(std::ostream &out, Matrix& m);

    	~Matrix();

    private:
	uint32_t cols_;
	uint32_t rows_;
	ProxyRow *prows_;
};

std::ostream& operator<<(std::ostream &out, Matrix& m);
