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
protected:
    size_t& size = Matrix::size.row; // 阶数

public:
    /*
     * constructor
     */
    SquareMatrix();
    SquareMatrix(const vector<Vector>& vv);
    SquareMatrix(size_t n, double element);
    SquareMatrix(const Matrix& m);
    SquareMatrix(size_t n);
    SquareMatrix(const initializer_list<Vector>& il);

    /*
     * get size
     */
    size_t getSize() const;

    /*
     * operator=
     */
    SquareMatrix& operator=(const SquareMatrix& rhs);

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
