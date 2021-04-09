#include <iostream>
#include "matrix.hpp"

	Matrix::ProxyRow::ProxyRow() { };

        int32_t& Matrix::ProxyRow::operator[](size_t j)
        {
	    if (j >= cols_)
	    {
	    	throw std::out_of_range("");
	    }
            return data_[j];
        }


	void Matrix::ProxyRow::arr_mal(uint32_t cols)
	{
		cols_ = cols;
		data_ = new int32_t[cols_];
	}
	Matrix::ProxyRow::~ProxyRow()
	{
		delete[] data_;
		//std::cout<<"~ProxyRow()"<<std::endl;
	}



    
    Matrix::Matrix(uint32_t rows, uint32_t cols) 
    {
        rows_ = rows;
        cols_ = cols;
        prows_ = new ProxyRow[rows_];	
	for (size_t i = 0; i < rows_; i++){
		prows_[i].arr_mal(cols_);
	}

	//std::cout<<"Matrix()"<<std::endl;
    }

    Matrix::ProxyRow& Matrix::operator[](size_t i)
    {
	if (i >= rows_) 
	{
		throw std::out_of_range("");
	}
        return prows_[i];
    }

    uint32_t Matrix::GetRows() 
    {
    	return rows_;
    }

    uint32_t Matrix::GetCols()
    {
    	return cols_;
    }


    Matrix& Matrix::operator*=(int32_t mult)
    {
    	for (size_t i = 0; i < rows_; i++) {
		for (size_t j = 0; j < cols_; j++) {
			(*this)[i][j] = (*this)[i][j] * mult;
		}
	}
    	return *this;
    } 

 	
   Matrix Matrix::operator+(Matrix& other)
   {
	if((this->rows_ != other.rows_) || (this->cols_ != other.cols_)) 
	{
		throw "WARNING";
	}
	
	Matrix m = Matrix(this->rows_, this->cols_);

	for (size_t i = 0; i < this->rows_; i++) {
		for (size_t j = 0; j < this->cols_; j++) {
			m[i][j] =  (*this)[i][j] + other[i][j];
		}
	}


	return m;
   }
   
	

   bool Matrix::operator==(Matrix& other)
   {
   	if (this->rows_ != other.rows_ || this->cols_ != other.cols_)
	{
		return false;
	}

	for (size_t i = 0; i < this->rows_; i++) {
		for (size_t j = 0; j < this->cols_; j++) {
			if ((*this)[i][j] != other[i][j]) {
				return false;
			}
		}
	}
	return true;
   }

   bool Matrix::operator!=(Matrix& other)
   {
   	return !((*this)==other);
   }

    //friend std::ostream& Matrix::operator<<(std::ostream &out);


    Matrix::~Matrix()
    {
	delete[] prows_;
    }

    std::ostream& operator<<(std::ostream &out, Matrix& m)
    {
		for (size_t i = 0; i < m.rows_; i++) {
			for (size_t j = 0; j < m.cols_; j++) {
				out<<m[i][j]<<" ";
				}
			out<<std::endl;
		}
		return out;
    }
