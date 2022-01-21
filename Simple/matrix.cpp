/******************************************
 * FileName: matrix.cpp
 * Brief: 矩阵
 * Author: 青羽
 * Blog: https://chen-qingyu.github.io/
 * CreateDate: 2022.01.12
 ******************************************/

#include <algorithm>

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
        throw std::runtime_error("Error: The matrix are empty.");
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
        throw std::runtime_error("Error: The matrix are empty.");
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

Matrix Matrix::upperTriangular() const
{
    Matrix result = Matrix(*this);

    // step 1: Gaussian elimination
    for (size_t i = 0; i < result.size.row; ++i)
    {
        size_t j = 0;
        while (j < result.size.col && eq(result[i][j], 0))
        {
            ++j;
        }
        for (size_t k = i + 1; k < result.size.row; ++k)
        {
            if (j < result.size.col && result[i][j] != 0)
            {
                result.E(k, i, -(result[k][j] / result[i][j]));
            }
        }
    }

    // step 2: To the upper triangular. It's so elegant, I'm a genius haha.
    std::sort(result.rows.begin(), result.rows.end(), [=](const Vector& v1, const Vector& v2) -> bool { return v1.countLeadingZeros() < v2.countLeadingZeros(); });

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

size_t Matrix::rank() const
{
    if (size.row == 0 || size.col == 0)
    {
        throw std::runtime_error("Error: The matrix are empty.");
    }

    Matrix upper = upperTriangular();
    size_t zeros = 0;
    for (const auto& r : upper.rows)
    {
        if (r.isZero()) // 这里不取非是因为循环内尽量减少操作
        {
            ++zeros;
        }
    }
    return upper.size.row - zeros;
}

Matrix Matrix::augment(const Matrix& m) const
{
    if (size.row != m.size.row)
    {
        throw std::runtime_error("Error: Two matrices have different row numbers.");
    }

    Matrix result = Matrix(*this);
    for (size_t i = 0; i < size.row; ++i)
    {
        result[i].append(m[i]);
    }
    result.size.col += m.size.col;
    return result;
}

Matrix Matrix::diagonal() const
{
    Matrix upper = upperTriangular();
    for (size_t c = 0; c < upper.size.row; ++c)
    {
        for (size_t r = 0; r < c; ++r)
        {
            upper.E(r, c, -(upper[r][c] / upper[c][c]));
        }
    }

    return upper;
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
