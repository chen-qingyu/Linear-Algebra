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

SquareMatrix::SquareMatrix(const vector<Vector>& vv)
    : Matrix(vv)
{
    if (vv.begin()->size != vv.size())
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

SquareMatrix::SquareMatrix(const initializer_list<Vector>& il)
    : Matrix(il)
{
    if (il.begin()->size != il.size())
    {
        throw std::runtime_error("Error: The rows and columns of the square matrix are not equal.");
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

    SquareMatrix echelon = rowEchelon();
    double det = 1;
    for (size_t i = 0; i < echelon.size; ++i)
    {
        det *= echelon.rows[i][i];
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

    // 1. 生成size阶单位阵 E
    // 2. 生成增广矩阵 A:E 
    // 3. 将 A:E 化为阶梯矩阵
    // 4. 将 A 化为对角矩阵
    Matrix diag = augment(SquareMatrix(size)).rowEchelon().diagonal(); // 链式调用提高效率
    // 5. 将 A 化为单位阵
    for (size_t r = 0; r < diag.size.row; ++r)
    {
        diag.E(r, (double)(1 / diag[r][r]));
    }
    // 6. 此时原先的 E 即为 A 的逆（写得这么清晰是花了功夫的）
    SquareMatrix result;
    for (size_t r = 0; r < size; ++r)
    {
        result.appendRows(Vector(diag[r].doubles.begin() + size, diag[r].doubles.end()));
    }
    return result;
}
