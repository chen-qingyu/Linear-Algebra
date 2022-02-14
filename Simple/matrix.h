/******************************************
 * FileName: matrix.h
 * Brief: 矩阵
 * Author: 青羽
 * Blog: https://chen-qingyu.github.io/
 * CreateDate: 2022.01.12
 ******************************************/

#ifndef MATRIX_H
#define MATRIX_H

#include "vector.h"

class Matrix
{
protected:
    vector<Vector> rows; // 每个元素都是行向量

    struct _size
    {
        size_t row;
        size_t col;
    } size; // 行列数

public:
    using size_t = vector<Vector>::size_type;

    enum enumRowOrCol
    {
        ROW,
        COL
    };

    /*
     * constructor
     */
    Matrix();
    Matrix(const vector<Vector>& vv);
    Matrix(size_t n, double element);
    Matrix(size_t row, size_t col, double element);
    Matrix(const initializer_list<Vector>& il);

    /*
     * get size
     */
    size_t rowSize() const;
    size_t colSize() const;

    /*
     * Matrix[]
     */
    Vector& operator[](size_t idx);
    const Vector& operator[](size_t idx) const;

    /*
     * Matrix == != Matrix
     */
    bool operator==(const Matrix& m) const;
    bool operator!=(const Matrix& m) const;

    /*
     * type conversion
     */
    string toString() const;

    /*
     * combine and split
     */
    Matrix combine(enumRowOrCol flag, const Matrix& m) const;
    vector<Matrix> split(enumRowOrCol flag, size_t n) const;

    /*
     * Matrix + - * Matrix
     */
    const Matrix operator+(const Matrix& m) const;
    const Matrix operator-(const Matrix& m) const;
    const Matrix operator*(const Matrix& m) const;

    /*
     * scalar multiplication
     */
    const Matrix operator*(const double& d) const;
    const Matrix operator/(const double& d) const;

    /*
     * elementary row transformation
     */
    Matrix& E(size_t i, size_t j);
    Matrix& E(size_t i, double k);
    Matrix& E(size_t i, size_t j, double k);

    /*
     * othors
     */
    Matrix transpose() const;
    Matrix rowEchelon() const;
    Matrix& zeroAdjust();
    size_t rank() const;

    /*******************
     * friend function
     *******************/

    /*
     * std::cout << Matrix
     */
    friend std::ostream& operator<<(std::ostream& os, const Matrix& m);

    /*
     * scalar multiplication
     */
    friend Matrix operator*(const double& d, const Matrix& m);
};

#endif // MATRIX_H
