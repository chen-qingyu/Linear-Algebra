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
    // TODO
    //    size_t& size = Matrix::size.row; // 阶数
    size_t size;

    /*
     * constructor
     */
    SquareMatrix();
    SquareMatrix(const vector<Vector>& rows);
    SquareMatrix(size_t n, double element);
    SquareMatrix(const Matrix& m);
    SquareMatrix(size_t n);

    /*
     * operator=
     */
    // TODO
    //    SquareMatrix& operator=(const SquareMatrix& sm);

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
