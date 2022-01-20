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
    : Matrix()
{
    size = 0;
}

SquareMatrix::SquareMatrix(const vector<Vector>& rows)
    : Matrix(rows)
{
    if (rows.begin()->size != rows.size())
    {
        throw std::runtime_error("Error: The rows and columns of the square matrix are not equal.");
    }

    size = rows.size();
}

SquareMatrix::SquareMatrix(size_t n, double element)
    : Matrix(n, element)
{
    size = n;
}

SquareMatrix::SquareMatrix(const Matrix& m)
    : Matrix(m)
{
    if (m.size.row != m.size.col)
    {
        throw std::runtime_error("Error: The rows and columns of the square matrix are not equal.");
    }

    size = m.size.row;
}

/*
 * determinant
 */

double SquareMatrix::det() const
{
    if (size == 0)
    {
        throw std::runtime_error("Error: The matrix are empty.");
    }

    SquareMatrix upper = upperTriangular();
    double det = 1;
    for (size_t i = 0; i < upper.size; ++i)
    {
        det *= upper.rows[i][i];
    }

    return det;
}
