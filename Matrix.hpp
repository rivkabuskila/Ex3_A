//
// Created by rivka on 03/04/2022.
//

#ifndef MATRIX_CALCULATOR_A_MATRIX_H
#define MATRIX_CALCULATOR_A_MATRIX_H

#include <iostream>
#include <vector>

using namespace std;
namespace zich {
    class Matrix {
    private:
        vector<double> mat;
        int column;
        int row;
    public:
        Matrix();
        Matrix(const vector<double> &v, const int column,const int row);
        Matrix(const Matrix &other);

        Matrix& operator+(const Matrix &matrix);
        Matrix& operator+=(const Matrix &matrix);
        Matrix& operator+();

        Matrix& operator-(const Matrix &matrix);
        Matrix& operator-=(const Matrix &matrix);
        Matrix& operator-();

        bool operator==(const Matrix &matrix);
        bool operator<=(const Matrix &matrix);
        bool operator<(const Matrix &matrix);
        bool operator>=(const Matrix &matrix);
        bool operator>(const Matrix &matrix);
        bool operator!=(const Matrix &matrix);

        Matrix& operator*(const double num);
        Matrix& operator*=(const double num);
        friend Matrix& operator*(const double num, Matrix &matrix);
        Matrix& operator*(const Matrix &matrix);
        Matrix& operator*=(const Matrix &matrix);
        Matrix& operator++();    //before
        Matrix operator++(int num);
        Matrix& operator--();    //before
        Matrix operator--(int num);

        friend std::ostream& operator<<(std::ostream &os, const Matrix &matrix);
        friend std::istream& operator>>(std::istream &is, Matrix &matrix);

        ~Matrix();
//
//
    };
};

#endif //MATRIX_CALCULATOR_A_MATRIX_H
