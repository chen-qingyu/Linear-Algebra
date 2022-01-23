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
}

SquareMatrix::SquareMatrix(const vector<Vector>& rows)
    : Matrix(rows)
{
    if (rows.begin()->size != rows.size())
    {
        throw std::runtime_error("Error: The rows and columns of the square matrix are not equal.");
    }
}

SquareMatrix::SquareMatrix(size_t n, double element)
    : Matrix(n, element)
{
}

SquareMatrix::SquareMatrix(const Matrix& m)
    : Matrix(m)
{
    if (m.size.row != m.size.col)
    {
        throw std::runtime_error("Error: The rows and columns of the square matrix are not equal.");
    }
}

SquareMatrix::SquareMatrix(Matrix::size_t n)
    : SquareMatrix(n, 0)
{
    for (size_t i = 0; i < size; ++i)
    {
        rows[i][i] = 1;
    }
}

/*
 * operator=
 */

SquareMatrix& SquareMatrix::operator=(const SquareMatrix& rhs)
{
    rows = rhs.rows;
    Matrix::size = rhs.Matrix::size;

    return *this;
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

/*
 * inverse matrix
 */

SquareMatrix SquareMatrix::inverse() const
{
    if (size == 0)
    {
        throw std::runtime_error("Error: The matrix are empty.");
    }

    if (rank() != size)
    {
        return SquareMatrix();
    }

    // 单位阵E
    SquareMatrix e(size);
    // 增广A -> A:E
    Matrix augmented = augment(e);
    // 将A化成上三角矩阵
    Matrix upper = augmented.upperTriangular();
    // 将A化为对角矩阵
    Matrix diag = upper.diagonal();
    // 将A化为单位阵
    for (size_t r = 0; r < diag.size.row; ++r)
    {
        diag.E(r, (double)(1 / diag[r][r]));
    }
    // 此时原先的E即为A的逆（写得这么清晰是花了功夫的）
    SquareMatrix result;
    for (size_t r = 0; r < size; ++r)
    {
        result.appendRows(Vector(diag[r].doubles.begin() + size, diag[r].doubles.end()));
    }
    return result;
}
