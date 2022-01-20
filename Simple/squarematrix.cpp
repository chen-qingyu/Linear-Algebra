/******************************************
 * FileName: squarematrix.cpp
 * Brief: 方阵
 * Author: 青羽
 * Blog: https://chen-qingyu.github.io/
 * CreateDate: 2022.01.12
 ******************************************/

#include "squarematrix.h"

/*******************
 * public function
 *******************/

/*
 * constructor
 */

SquareMatrix::SquareMatrix()
{
    rows = {};
    n = 0;
    size = {n, n};
}

SquareMatrix::SquareMatrix(const vector<Vector>& rows)
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
    if (rows.begin()->size != rows.size())
    {
        throw std::runtime_error("Error: The number of rows and columns is not equal.");
    }

    this->rows = rows;
    n = rows.size();
    size = {n, n};
}

SquareMatrix::SquareMatrix(size_t n, double element)
{
    if (n == 0)
    {
        throw std::runtime_error("Error: The matrix are empty.");
    }

    this->n = n;
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

SquareMatrix::SquareMatrix(const Matrix& m)
{
    if (m.size.row != m.size.col)
    {
        throw std::runtime_error("Error: A matrix with unequal rows and columns can not be converted to a square matrix");
    }

    if (m.size.row == 0)
    {
        throw std::runtime_error("Error: The matrix are empty.");
    }

    n = m.size.row;
    size = {n, n};

    Vector v;
    for (size_t i = 0; i < n; ++i)
    {
        rows.insert(rows.end(), m[i]);
    }
}

/*
 * determinant
 */

double SquareMatrix::det() const
{
    if (n == 0)
    {
        throw std::runtime_error("Error: The matrix are empty.");
    }

    SquareMatrix upper = upperTriangular();
    double det = 1;
    for (size_t i = 0; i < upper.n; ++i)
    {
        det *= upper.rows[i][i];
    }

    return det;
}
