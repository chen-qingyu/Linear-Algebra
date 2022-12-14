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

Matrix::Matrix(const vector<Vector>& vv)
{
    if (vv.begin()->size == 0)
    {
        throw std::runtime_error("Error: The matrix are empty.");
    }
    for (const auto& row : vv)
    {
        if (row.size != vv.begin()->size)
        {
            throw std::runtime_error("Error: The row vectors are not of equal size.");
        }
    }

    rows = vv;
    size = {rows.size(), rows.begin()->size};
}

Matrix::Matrix(size_t n, double element)
{
    if (n == 0)
    {
        throw std::runtime_error("Error: The matrix are empty.");
    }

    size = {n, n};

    Vector v(n, element);
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

    Vector v(col, element);
    for (size_t i = 0; i < row; ++i)
    {
        rows.insert(rows.end(), v);
    }
}

Matrix::Matrix(const initializer_list<Vector>& il)
{
    if (il.begin()->size == 0)
    {
        throw std::runtime_error("Error: The matrix are empty.");
    }
    for (const auto& row : il)
    {
        if (row.size != il.begin()->size)
        {
            throw std::runtime_error("Error: The row vectors are not of equal size.");
        }
    }

    rows.insert(rows.end(), il.begin(), il.end());
    size = {rows.size(), rows.begin()->size};
}

/*
 * get size
 */

size_t Matrix::rowSize() const
{
    return size.row;
}

size_t Matrix::colSize() const
{
    return size.col;
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

const Vector& Matrix::operator[](size_t idx) const
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

Matrix::operator string() const
{
    if (size.row == 0 || size.col == 0)
    {
        return "[]";
    }

    string str = "";
    for (const auto& r : rows)
    {
        str += (string)r;
        str += '\n';
    }
    str.pop_back();
    return str;
}

/*
 * combine and split
 */

Matrix Matrix::combine(enumRowOrCol flag, const Matrix& m) const
{
    Matrix result(*this);
    switch (flag)
    {
        case ROW:
            if (m.size.col != size.col)
            {
                throw std::runtime_error("Error: Two matrices have different col numbers.");
            }

            result.rows.insert(result.rows.end(), m.rows.begin(), m.rows.end());
            result.size.row += m.size.row;

            break;

        case COL:
            if (m.size.row != size.row)
            {
                throw std::runtime_error("Error: Two matrices have different row numbers.");
            }

            for (size_t i = 0; i < size.row; ++i)
            {
                result[i].append(m[i]);
            }
            result.size.col += m.size.col;

            break;

        default:
            throw std::runtime_error("Error: Invalid flag.");
            break;
    }
    return result;
}

vector<Matrix> Matrix::split(enumRowOrCol flag, size_t n) const
{
    vector<Matrix> vm;
    Matrix tmp;
    switch (flag)
    {
        case ROW:
            if (n >= size.row || n == 0)
            {
                throw std::runtime_error("Error: Invalid position.");
            }

            tmp.rows.clear();
            tmp.size = {n, size.col};
            tmp.rows.insert(tmp.rows.end(), rows.begin(), rows.begin() + n);
            vm.insert(vm.end(), tmp);

            tmp.rows.clear();
            tmp.size = {size.row - n, size.col};
            tmp.rows.insert(tmp.rows.end(), rows.begin() + n, rows.end());
            vm.insert(vm.end(), tmp);

            break;

        case COL:
            if (n >= size.col || n == 0)
            {
                throw std::runtime_error("Error: Invalid position.");
            }

            tmp.rows.clear();
            tmp.size = {size.row, n};
            for (size_t i = 0; i < size.row; ++i)
            {
                tmp.rows.insert(tmp.rows.end(), Vector(rows[i].doubles.begin(), rows[i].doubles.begin() + n));
            }
            vm.insert(vm.end(), tmp);

            tmp.rows.clear();
            tmp.size = {size.row, size.col - n};
            for (size_t i = 0; i < size.row; ++i)
            {
                tmp.rows.insert(tmp.rows.end(), Vector(rows[i].doubles.begin() + n, rows[i].doubles.end()));
            }
            vm.insert(vm.end(), tmp);

            break;

        default:
            throw std::runtime_error("Error: Invalid flag.");
            break;
    }
    return vm;
}

/*
 * Matrix + - * Matrix
 */

const Matrix Matrix::operator+(const Matrix& m) const
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

const Matrix Matrix::operator-(const Matrix& m) const
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

const Matrix Matrix::operator*(const Matrix& m) const
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

const Matrix Matrix::operator*(const double& d) const
{
    Matrix result = Matrix(*this);
    for (size_t i = 0; i < size.row; ++i)
    {
        result[i] = result[i] * d;
    }
    return result;
}

const Matrix Matrix::operator/(const double& d) const
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

Matrix Matrix::rowEchelon() const
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

    // step 2: To the row echelon form. It's so elegant, I'm a genius haha.
    std::sort(result.rows.begin(), result.rows.end(), [](const Vector& v1, const Vector& v2) -> bool { return v1.countLeadingZeros() < v2.countLeadingZeros(); });

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

    Matrix echelon = rowEchelon();
    size_t zeros = 0;
    for (const auto& r : echelon.rows)
    {
        if (r.isZero()) // 这里不取非是因为循环内尽量减少操作
        {
            ++zeros;
        }
    }
    return echelon.size.row - zeros;
}

/*******************
 * friend function
 *******************/

/*
 * std::cout << Matrix
 */

std::ostream& operator<<(std::ostream& os, const Matrix& m)
{
    return os << (string)m;
}

/*
 * scalar multiplication
 */

Matrix operator*(const double& d, const Matrix& m)
{
    return m * d;
}
