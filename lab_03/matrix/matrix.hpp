#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "matrix_base.hpp"

template <class T>
class Matrix : public MatrixBase<T>
{
public:
    typedef typename MatrixBase<T>::iterator iterator;
    typedef typename MatrixBase<T>::const_iterator const_iterator;

    explicit Matrix(int, int);
    explicit Matrix(int, int, const T &);
    Matrix(int, int, iterator, iterator);
    Matrix(int, int, const_iterator, const_iterator);
    Matrix(int, int, std::initializer_list<T>);
    Matrix(const Matrix &);
    Matrix(Matrix &&);
    virtual ~Matrix() = default;
    Matrix &operator=(const Matrix &);
    Matrix &operator=(Matrix &&);
    Matrix &operator=(std::initializer_list<T>);

    template <class U>
    friend Matrix<U> operator+(const Matrix<U> &, const Matrix<U> &);
    template <class U>
    friend Matrix<U> operator+(const Matrix<U> &, const U &);
    Matrix &operator+=(const Matrix &);
    Matrix &operator+=(const T &);
    template <class U>
    friend Matrix<U> operator-(const Matrix<U> &, const Matrix<U> &);
    template <class U>
    friend Matrix<U> operator-(const Matrix<U> &, const U &);
    Matrix &operator-=(const Matrix &);
    Matrix &operator-=(const T &);
    template <class U>
    friend Matrix<U> operator*(const Matrix<U> &, const Matrix<U> &);
    template <class U>
    friend Matrix<U> operator*(const Matrix<U> &, const U &);
    Matrix &operator*=(const Matrix &);
    Matrix &operator*=(const T &);
    template <class U>
    friend Matrix<U> operator/(const Matrix<U> &, const U &);
    Matrix &operator/=(const T &);
};

template <class T>
Matrix<T>::Matrix(int row_count, int col_count)
    : MatrixBase<T>(row_count, col_count)
{
}

template <class T>
Matrix<T>::Matrix(int row_count, int col_count, const T &value)
    : MatrixBase<T>(row_count, col_count, value)
{
}

template <class T>
Matrix<T>::Matrix(int row_count, int col_count, iterator first, iterator last)
    : MatrixBase<T>(row_count, col_count, first, last)
{
}

template <class T>
Matrix<T>::Matrix(int row_count, int col_count, const_iterator first, const_iterator last)
    : MatrixBase<T>(row_count, col_count, first, last)
{
}

template <class T>
Matrix<T>::Matrix(int row_count, int col_count, std::initializer_list<T> lst)
    : MatrixBase<T>(row_count, col_count, lst)
{
}

template <class T>
Matrix<T>::Matrix(const Matrix &other)
    : MatrixBase<T>(other)
{
}

template <class T>
Matrix<T>::Matrix(Matrix &&other)
    : MatrixBase<T>(std::move(other))
{
}

template <class T>
Matrix<T> &Matrix<T>::operator=(const Matrix<T> &rhs)
{
    MatrixBase<T>::operator=(rhs);

    return *this;
}

template <class T>
Matrix<T> &Matrix<T>::operator=(Matrix<T> &&rhs)
{
    MatrixBase<T>::operator=(std::move(rhs));

    return *this;
}

template <class T>
Matrix<T> &Matrix<T>::operator=(std::initializer_list<T> lst)
{
    MatrixBase<T>::operator=(lst);

    return *this;
}

template <class T>
Matrix<T> operator+(const Matrix<T> &lhs, const Matrix<T> &rhs)
{
    Matrix<T> result = lhs;
    int rows_count = lhs.rows() < rhs.rows() ? lhs.rows() : rhs.rows();
    int cols_count = lhs.columns() < rhs.columns() ? lhs.columns() : rhs.columns();

    for (int i = 0; i < rows_count; ++i)
    {
        for (int j = 0; j < cols_count; ++j)
        {
            result[i][j] += rhs[i][j];
        }
    }

    return result;
}

template <class T>
Matrix<T> operator+(const Matrix<T> &mtx, const T &value)
{
    Matrix<T> result = mtx;

    for (int i = 0; i < mtx.capacity(); ++i)
    {
        result._data[i] += value;
    }

    return result;
}

template <class T>
Matrix<T> &Matrix<T>::operator+=(const Matrix<T> &rhs)
{
    int rows_count = this->rows() < rhs.rows() ? this->rows() : rhs.rows();
    int cols_count = this->columns() < rhs.columns() ? this->columns() : rhs.columns();

    for (int i = 0; i < rows_count; ++i)
    {
        for (int j = 0; j < cols_count; ++j)
        {
            (*this)[i][j] += rhs[i][j];
        }
    }

    return *this;
}

template <class T>
Matrix<T> &Matrix<T>::operator+=(const T &value)
{
    for (int i = 0; i < this->capacity(); ++i)
    {
        this->_data[i] += value;
    }

    return *this;
}

template <class T>
Matrix<T> operator-(const Matrix<T> &lhs, const Matrix<T> &rhs)
{
    Matrix<T> result = lhs;
    int rows_count = lhs.rows() < rhs.rows() ? lhs.rows() : rhs.rows();
    int cols_count = lhs.columns() < rhs.columns() ? lhs.columns() : rhs.columns();

    for (int i = 0; i < rows_count; ++i)
    {
        for (int j = 0; j < cols_count; ++j)
        {
            result[i][j] -= rhs[i][j];
        }
    }

    return result;
}

template <class T>
Matrix<T> operator-(const Matrix<T> &mtx, const T &value)
{
    Matrix<T> result = mtx;

    for (int i = 0; i < mtx.capacity(); ++i)
    {
        result._data[i] -= value;
    }

    return result;
}

template <class T>
Matrix<T> &Matrix<T>::operator-=(const Matrix<T> &rhs)
{
    int rows_count = this->rows() < rhs.rows() ? this->rows() : rhs.rows();
    int cols_count = this->columns() < rhs.columns() ? this->columns() : rhs.columns();

    for (int i = 0; i < rows_count; ++i)
    {
        for (int j = 0; j < cols_count; ++j)
        {
            (*this)[i][j] -= rhs[i][j];
        }
    }

    return *this;
}

template <class T>
Matrix<T> &Matrix<T>::operator-=(const T &value)
{
    for (int i = 0; i < this->capacity(); ++i)
    {
        this->_data[i] -= value;
    }

    return *this;
}

template <class T>
Matrix<T> operator*(const Matrix<T> &lhs, const Matrix<T> &rhs)
{
    if (lhs.columns() == rhs.rows())
    {
        Matrix<T> result = lhs;

        for (int i = 0; i < lhs.rows(); ++i)
        {
            for (int j = 0; j < rhs.columns(); ++j)
            {
                for (int k = 0; k < lhs.columns(); ++k)
                {
                    result[i][j] += lhs[i][k] * rhs[k][j];
                }
            }
        }

        return result;
    }
    else
    {
        std::string message = "Error in Matrix operator *";
        throw RangeError(message);
    }
}

template <class T>
Matrix<T> &operator*(const Matrix<T> &mtx, const T &value)
{
    Matrix<T> result = mtx;

    for (int i = 0; i < mtx.capacity(); ++i)
    {
        result._data[i] *= value;
    }

    return result;
}

template <class T>
Matrix<T> &Matrix<T>::operator*=(const Matrix<T> &rhs)
{
    if (this->columns() == rhs.rows())
    {
        for (int i = 0; i < this->rows(); ++i)
        {
            for (int j = 0; j < rhs.columns(); ++j)
            {
                for (int k = 0; k < this->columns(); ++k)
                {
                    (*this)[i][j] = (*this)[i][k] * rhs[k][j];
                }
            }
        }

        return *this;
    }
    else
    {
        std::string message = "Error in Matrix operator *=";
        throw RangeError(message);
    }
}

template <class T>
Matrix<T> &Matrix<T>::operator*=(const T &value)
{
    for (int i = 0; i < this->capacity(); ++i)
    {
        this->_data[i] *= value;
    }

    return *this;
}

template <class T>
Matrix<T> &operator/(const Matrix<T> &mtx, const T &value)
{
    Matrix<T> result = mtx;

    for (int i = 0; i < mtx.capacity(); ++i)
    {
        result._data[i] /= value;
    }

    return result;
}

template <class T>
Matrix<T> &Matrix<T>::operator/=(const T &value)
{
    for (int i = 0; i < this->capacity(); ++i)
    {
        this->_data[i] /= value;
    }

    return *this;
}

#endif
