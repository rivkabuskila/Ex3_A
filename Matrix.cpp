//
// Created by rivka on 03/04/2022.
//

#include "Matrix.hpp"
namespace zich {
    Matrix::Matrix(){
        column = 0;
        row = 0;
    }
    Matrix::Matrix(const vector<double> &v, const int newColumn,const int newRow) {
        mat = v;
        column = newColumn;
        row = newRow;
    }

    Matrix::Matrix(const Matrix &other) {
        mat = other.mat;
        column = other.column;

        row = other.row;    }

    Matrix& Matrix::operator+(const Matrix &matrix){
        return *this;
    }

    Matrix& Matrix::operator+=(const Matrix &matrix) {
        return *this;
    }

    Matrix& Matrix::operator+() {
        return *this;
    }

    Matrix& Matrix::operator-(const Matrix &matrix) {
        return *this;
    }

    Matrix& Matrix::operator-=(const Matrix &matrix) {
        return *this;
    }

    Matrix& Matrix::operator- (){
        return *this;
    }

    bool Matrix::operator< (const Matrix &matrix){
        return true;
    }

    bool Matrix:: operator<=(const Matrix &matrix) {
        return true;
    }

    bool Matrix::operator>(const Matrix &matrix) {
        return true;
    }

    bool Matrix::operator>=(const Matrix &matrix) {
        return true;
    }

    bool Matrix::operator==(const Matrix &matrix) {
        return true;
    }

    bool Matrix::operator!=(const Matrix &matrix) {
        return true;
    }

    Matrix& Matrix::operator++() {
        return *this;
    }   //before
    Matrix Matrix::operator++(int num) {
        return *this;
    }
    Matrix& Matrix::operator--() {
        return *this;
    }   //before
    Matrix Matrix::operator--(int num) {
        return *this;
    }
    Matrix& Matrix::operator*(const double num) {
        return *this;
    }
    Matrix& Matrix::operator*=(const double num){
        return *this;
    }
    Matrix& Matrix::operator*(const Matrix &matrix){
        return *this;
    }
    Matrix& operator*(double num, Matrix &matrix){
        return matrix;
    }
    Matrix& Matrix::operator*=(const Matrix &matrix){
        return *this;
    }
    std::ostream &operator<<(std::ostream &os, const Matrix &matrix){
        return os;
    }
    std::istream& operator>>(std::istream &is, Matrix &matrix){
        return is;
    }
    Matrix::~Matrix() {
    }
}