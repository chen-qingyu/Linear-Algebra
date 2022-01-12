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
    size = 0;
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
    size = rows.size();
}

SquareMatrix::SquareMatrix(size_t n, double element)
{
    if (n == 0)
    {
        throw std::runtime_error("Error: The vectors are empty.");
    }

    size = n;

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
