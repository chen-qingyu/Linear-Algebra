/******************************************
 * FileName: squarematrix.h
 * Brief: 方阵
 * Author: 青羽
 * Blog: https://chen-qingyu.github.io/
 * CreateDate: 2022.01.12
 ******************************************/

#ifndef SQUAREMATRIX_H
#define SQUAREMATRIX_H

#include "matrix.h"

class SquareMatrix : public Matrix
{
public:
    size_t size; // 阶数

    /*
     * constructor
     */
    SquareMatrix();
    SquareMatrix(const vector<Vector>& rows);
    SquareMatrix(size_t n, double element);
    SquareMatrix(const Matrix& m);
    SquareMatrix(size_t n);

    /*
     * determinant
     */
    double det() const;

    /*
     * inverse matrix
     */
    SquareMatrix inverse() const;

    /*
     * eigen values
     */
    vector<double> eigen() const;

    /*
     * adjoint matrix
     */
    SquareMatrix adjoint() const;
};

#endif // SQUAREMATRIX_H
