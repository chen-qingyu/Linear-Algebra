/******************************************
 * FileName: matrix.cpp
 * Brief: 矩阵
 * Author: 青羽
 * Blog: https://chen-qingyu.github.io/
 * CreateDate: 2022.01.12
 ******************************************/

#include "matrix.h"

/*******************
 * public function
 *******************/

/*
 * constructor
 */

Matrix::Matrix()
{
    rows = {};
    size = {0, 0};
}

Matrix::Matrix(const vector<Vector>& rows)
{
    if (rows.begin()->size == 0)
    {
        throw std::runtime_error("Error: The vectors are empty.");
    }
    for (const auto& row : rows)
    {
        if (row.size != rows.begin()->size)
        {
            throw std::runtime_error("Error: The row vectors are not of equal size.");
        }
    }

    this->rows = rows;
    size = {rows.size(), rows.begin()->size};
}

Matrix::Matrix(size_t n, double element)
{
    if (n == 0)
    {
        throw std::runtime_error("Error: The vectors are empty.");
    }

    size = {n, n};

    Vector v;
    for (size_t i = 0; i < n; ++i)
    {
        v.append(element);
    }
    for (size_t i = 0; i < n; ++i)
    {
        rows.insert(rows.end(), v);
    }
}

Matrix::Matrix(size_t row, size_t col, double element)
{
    if (row == 0 || col == 0)
    {
        throw std::runtime_error("Error: The vectors are empty.");
    }

    size = {row, col};

    Vector v;
    for (size_t i = 0; i < col; ++i)
    {
        v.append(element);
    }
    for (size_t i = 0; i < row; ++i)
    {
        rows.insert(rows.end(), v);
    }
}

/*
 * Matrix[]
 */

Vector& Matrix::operator[](size_t idx)
{
    if (idx >= size.row)
    {
        throw std::runtime_error("Error: Matrix index out of bounds.");
    }

    return rows[idx];
}

Vector Matrix::operator[](size_t idx) const
{
    if (idx >= size.row)
    {
        throw std::runtime_error("Error: Matrix index out of bounds.");
    }

    return rows[idx];
}

/*
 * Matrix == != Matrix
 */

bool Matrix::operator==(const Matrix& m) const
{
    if ((size.row != m.size.row) || (size.col != m.size.col))
    {
        return false;
    }

    for (size_t i = 0; i < size.row; ++i)
    {
        if (rows[i] != m.rows[i])
        {
            return false;
        }
    }

    return true;
}

bool Matrix::operator!=(const Matrix& m) const
{
    return !operator==(m);
}

/*
 * type conversion
 */

string Matrix::toString() const
{
    if (size.row == 0 || size.col == 0)
    {
        return "[]";
    }

    string str = "";
    for (const auto& r : rows)
    {
        str += r.toString();
        str += '\n';
    }
    str.pop_back();
    return str;
}

/*
 * Matrix + - * Matrix
 */

Matrix Matrix::operator+(const Matrix& m) const
{
    if ((size.row != m.size.row) || (size.col != m.size.col))
    {
        throw std::runtime_error("Error: Add two matrices of different size.");
    }
    if (size.row == 0 || size.col == 0)
    {
        throw std::runtime_error("Error: The matrices are empty.");
    }

    Matrix result = Matrix(*this);
    for (size_t i = 0; i < size.row; ++i)
    {
        result[i] = result[i] + m.rows[i];
    }
    return result;
}

Matrix Matrix::operator-(const Matrix& m) const
{
    if ((size.row != m.size.row) || (size.col != m.size.col))
    {
        throw std::runtime_error("Error: Subtract two matrices of different size.");
    }
    if (size.row == 0 || size.col == 0)
    {
        throw std::runtime_error("Error: The matrices are empty.");
    }

    Matrix result = Matrix(*this);
    for (size_t i = 0; i < size.row; ++i)
    {
        result[i] = result[i] - m.rows[i];
    }
    return result;
}

Matrix Matrix::operator*(const Matrix& m) const
{
    if (size.col != m.size.row)
    {
        throw std::runtime_error("Error: The row and column size don't match.");
    }
    if (size.row == 0 || size.col == 0 || m.size.row == 0 || m.size.col == 0)
    {
        throw std::runtime_error("Error: The matrices are empty.");
    }

    Matrix result = Matrix(size.row, m.size.col, 0);
    Matrix tmp = m.transpose();
    for (size_t i = 0; i < size.row; ++i)
    {
        for (size_t j = 0; j < m.size.col; ++j)
        {
            result[i][j] = rows[i] * tmp.rows[j];
        }
    }
    return result;
}

/*
 * scalar multiplication
 */

Matrix Matrix::operator*(const double& d) const
{
    Matrix result = Matrix(*this);
    for (size_t i = 0; i < size.row; ++i)
    {
        result[i] = result[i] * d;
    }
    return result;
}

Matrix Matrix::operator/(const double& d) const
{
    Matrix result = Matrix(*this);
    for (size_t i = 0; i < size.row; ++i)
    {
        result[i] = result[i] / d;
    }
    return result;
}

/*
 * elementary row transformation
 */

Matrix& Matrix::E(size_t i, size_t j)
{
    Vector tmp = (*this)[i];
    (*this)[i] = (*this)[j];
    (*this)[j] = tmp;

    return *this;
}

Matrix& Matrix::E(size_t i, double k)
{
    (*this)[i] = (*this)[i] * k;

    return *this;
}

Matrix& Matrix::E(size_t i, size_t j, double k)
{
    (*this)[i] = (*this)[i] + (*this)[j] * k;

    return *this;
}

/*
 * othors
 */

Matrix Matrix::transpose() const
{
    Matrix result = Matrix(size.col, size.row, 0);
    for (size_t i = 0; i < size.row; ++i)
    {
        for (size_t j = 0; j < size.col; ++j)
        {
            result[j][i] = (*this)[i][j];
        }
    }
    return result;
}

// TODO
Matrix Matrix::upperTriangular() const
{
    Matrix result = Matrix(*this);

    for (size_t i = 0; i < size.row; ++i)
    {
        for (size_t j = i + 1; j < size.row; ++j)
        {
            size_t m = 0;
            while (eq((*this)[i][m], 0))
            {
                ++m;
            }
            if ((*this)[i][m] != 0)
            {
                //                double k =
            }
        }
    }

    return result.zeroAdjust();
}

Matrix& Matrix::zeroAdjust()
{
    for (auto& r : rows)
    {
        r.zeroAdjust();
    }
    return *this;
}

// TODO
size_t Matrix::rank() const
{
    return 0;
}

/*******************
 * friend function
 *******************/

/*
 * std::cout << Matrix
 */

std::ostream& operator<<(std::ostream& os, const Matrix& m)
{
    return os << m.toString();
}

/*
 * scalar multiplication
 */

Matrix operator*(const double& d, const Matrix& m)
{
    return m * d;
}
