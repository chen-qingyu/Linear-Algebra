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
private:
    vector<Vector> rows; // 每个元素都是行向量

public:
    using size_t = vector<Vector>::size_type;

    struct
    {
        size_t row;
        size_t col;
    } size; // 行列数

    /*
     * constructor
     */
    Matrix();
    Matrix(const vector<Vector>& rows);
    Matrix(size_t n, double element);
    Matrix(size_t row, size_t col, double element);

    /*
     * Matrix[]
     */
    Vector& operator[](size_t idx);
    Vector operator[](size_t idx) const;

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
     * Matrix + - * Matrix
     */
    Matrix operator+(const Matrix& m) const;
    Matrix operator-(const Matrix& m) const;
    Matrix operator*(const Matrix& m) const;

    /*
     * scalar multiplication
     */

    /*
     * othors
     */
    Matrix transpose() const;
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
};

#endif // MATRIX_H