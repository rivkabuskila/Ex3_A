//
// Created by rivka on 03/04/2022.
//
// Created by rivka on 06/03/2022.
//
#include "doctest.h"
#include "Matrix.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;
using namespace zich;
vector<double> vector1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
vector<double> vector2 = {3, 0, 0, 0};
vector<double> vector3 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
vector<double> vector4 = {-1, -2, -3, -4, -5, -6, -7, -8, -9};
vector<double> vector5 = {0, 0, 0, 0, 0, 0, 0, 0, 0};
vector<double> vector6 = {2, 2, 3, 4, 6, 6, 7, 8, 10};
vector<double> vector7 = {-30, -36, -42, -66, -81, -96, -102, -126, -150};
vector<double> vector8 = {1, 2, 3, 4, 5, 6};
vector<double> vector9 = {3, 0, 9, 0, 15, 0};
vector<double> vector10 = {6, 0, 0, 0};
vector<double> vector11 = {1, 1, 1, 1, 1, 1, 1, 1, 1};
bool boolean;

TEST_CASE("Wrong value to constructor"){
    CHECK_THROWS(Matrix(vector1, 2, 3));
    CHECK_THROWS(Matrix(vector2, 6, 3));
    CHECK_THROWS(Matrix(vector3, -1, 3));
    CHECK_THROWS(Matrix(vector4, 0, 3));
    CHECK_THROWS(Matrix(vector5, 2, 1));
}
TEST_CASE("Wrong value +"){
    Matrix mat1{vector1, 3, 3};
    Matrix mat2{vector2, 2, 2};
    CHECK_THROWS(mat1+mat2);
    CHECK_THROWS(mat2+mat1);
}
TEST_CASE("good inputs +") {
    Matrix mat1{vector1, 3, 3};
    Matrix mat3{vector3, 3, 3};
    Matrix mat4{vector4, 3, 3};
    Matrix mat5{vector5, 3, 3};
    Matrix mat6{vector6, 3, 3};
    CHECK_NOTHROW(mat1+mat3);
    CHECK_NOTHROW(mat3+mat4);
    CHECK((mat1+mat3 == mat6) == true);
    CHECK((mat3+mat1 == mat6) == true);
    CHECK((mat3+mat4 == mat5) == true);
    CHECK((mat4+mat3 == mat5) == true);

}
TEST_CASE("Wrong value +="){
    Matrix mat1{vector1, 3, 3};
    Matrix mat2{vector2, 2, 2};
    CHECK_THROWS(mat1+=mat2);
    CHECK_THROWS(mat2+=mat1);
}
TEST_CASE("good inputs +=") {
    Matrix mat1{vector1, 3, 3};
    Matrix mat3{vector3, 3, 3};
    Matrix mat4{vector4, 3, 3};
    Matrix mat5{vector5, 3, 3};
    Matrix mat6{vector6, 3, 3};
    CHECK_NOTHROW(mat1+=mat3);
    CHECK_NOTHROW(mat3+=mat4);
    CHECK(((mat1+=mat3)== mat6) == true);
    CHECK(((mat3+=mat1) == mat6) == true);
    CHECK(((mat3+=mat4) == mat5) == true);
    CHECK(((mat4+=mat3) == mat5) == true);

}
TEST_CASE("good inputs + Unry") {
    Matrix mat1{vector1, 3, 3};
    Matrix mat2{vector2, 2, 2};
    Matrix mat3{vector3, 3, 3};
    Matrix mat4{vector4, 3, 3};
    Matrix mat5{vector5, 3, 3};
    Matrix mat6{vector6, 3, 3};
    Matrix mat7{vector7, 3, 3};
    CHECK_NOTHROW(+mat3);
    CHECK_NOTHROW(+mat4);
    CHECK(((+mat1)== mat1) == true);
    CHECK(((+mat2)== mat2) == true);
    CHECK(((+mat3)== mat3) == true);
    CHECK(((+mat4)== mat4) == true);
    CHECK(((+mat5)== mat5) == true);
    CHECK(((+mat6)== mat6) == true);
    CHECK(((+mat7)== mat7) == true);


}
TEST_CASE("Wrong value -"){
    Matrix mat1{vector1, 3, 3};
    Matrix mat2{vector2, 2, 2};
    CHECK_THROWS(mat1-mat2);
    CHECK_THROWS(mat2-mat1);
}
TEST_CASE("good inputs -") {
    Matrix mat1{vector1, 3, 3};
    Matrix mat3{vector3, 3, 3};
    Matrix mat4{vector4, 3, 3};
    Matrix mat5{vector5, 3, 3};
    Matrix mat6{vector6, 3, 3};
    CHECK_NOTHROW(mat1-mat3);
    CHECK_NOTHROW(mat3-mat4);
    CHECK((mat3-mat3 == mat5) == true);
    CHECK((mat6-mat1 == mat3) == true);
    CHECK((mat5-mat4 == mat3) == true);

}

TEST_CASE("Wrong value -="){
    Matrix mat1{vector1, 3, 3};
    Matrix mat2{vector2, 2, 2};
    CHECK_THROWS(mat1-=mat2);
    CHECK_THROWS(mat2-=mat1);
}
TEST_CASE("good inputs -=") {
    Matrix mat1{vector1, 3, 3};
    Matrix mat3{vector3, 3, 3};
    Matrix mat4{vector4, 3, 3};
    Matrix mat5{vector5, 3, 3};
    Matrix mat6{vector6, 3, 3};
    CHECK_NOTHROW(mat1-=mat3);
    CHECK_NOTHROW(mat3-=mat4);
    CHECK(((mat3-=mat3) == mat5)== true);
    CHECK(((mat6-=mat1) == mat3)== true);
    CHECK(((mat5-=mat4) == mat3)== true);

}

TEST_CASE("good inputs - Unry") {
    Matrix mat1{vector1, 3, 3};
    Matrix mat2{vector2, 2, 2};
    Matrix mat3{vector3, 3, 3};
    Matrix mat4{vector4, 3, 3};
    Matrix mat5{vector5, 3, 3};
    Matrix mat6{vector6, 3, 3};
    Matrix mat7{vector7, 3, 3};
    CHECK_NOTHROW(-mat3);
    CHECK_NOTHROW(-mat4);
    CHECK((-mat1 == mat1*-1) == true);
    CHECK((-mat2 == mat2*-1) == true);
    CHECK((-mat3 == mat3*-1) == true);
    CHECK((-mat4 == mat4*-1) == true);
    CHECK((-mat5 == mat5*-1) == true);
    CHECK((-mat6 == mat6*-1) == true);
    CHECK((-mat7 == mat7*-1) == true);
}
TEST_CASE("Wrong value =="){
    Matrix mat1{vector1, 3, 3};
    Matrix mat2{vector2, 2, 2};
    CHECK_THROWS(boolean=mat1==mat2);
    CHECK_THROWS(boolean=mat2==mat1);
}
TEST_CASE("good inputs ==") {
    Matrix mat1{vector1, 3, 3};
    Matrix mat2{vector2, 2, 2};
    Matrix mat3{vector3, 3, 3};
    Matrix mat4{vector4, 3, 3};
    Matrix mat5{vector5, 3, 3};
    Matrix mat6{vector6, 3, 3};
    CHECK_NOTHROW(boolean=mat1==mat3);
    CHECK_NOTHROW(boolean=mat3==mat4);
    CHECK((mat2 == mat2)== true);
    CHECK((mat3 == mat3)== true);
    CHECK((mat5== mat5)== true);
    CHECK((mat3-mat3 == mat5)== true);
    CHECK((mat6-mat1 == mat3)== true);
    CHECK((mat5-mat4 == mat3)== true);
    CHECK((mat5-mat4 == mat3)== true);
    CHECK((mat5 == mat4)== false);
    CHECK((mat1 == mat6)== false);

}
TEST_CASE("Wrong value <="){
    Matrix mat1{vector1, 3, 3};
    Matrix mat2{vector2, 2, 2};
    CHECK_THROWS(boolean=mat1<=mat2);
    CHECK_THROWS(boolean=mat2<=mat1);
}
TEST_CASE("good inputs <=") {
    Matrix mat1{vector1, 3, 3};
    Matrix mat2{vector2, 2, 2};
    Matrix mat3{vector3, 3, 3};
    Matrix mat4{vector4, 3, 3};
    Matrix mat5{vector5, 3, 3};
    Matrix mat6{vector6, 3, 3};
    //==
    CHECK_NOTHROW(boolean=mat1==mat3);
    CHECK_NOTHROW(boolean=mat3==mat4);
    CHECK((mat1 <= mat1)== true);
    CHECK((mat2 <= mat2)== true);
    CHECK((mat3-mat3 <= mat5)== true);
    CHECK((mat6-mat1 <= mat3)== true);
    //<
    CHECK_NOTHROW(boolean=mat4 <= mat1);
    CHECK_NOTHROW(boolean=mat1<= mat3);
    CHECK((mat4 <= mat1)== true);
    CHECK((mat1 <= mat3)== true);
    CHECK((mat1 <= mat6)== true);
    CHECK((mat3 <= mat6)== true);
    CHECK((mat4+mat4 <= mat4)== true);
    CHECK((mat6 <= mat3)== false);
    CHECK((mat4 <= mat4+mat4)== false);


}
TEST_CASE("Wrong value <"){
    Matrix mat1{vector1, 3, 3};
    Matrix mat2{vector2, 2, 2};
    CHECK_THROWS(boolean=mat1<mat2);
    CHECK_THROWS(boolean=mat2<mat1);
}


TEST_CASE("good inputs <") {
    Matrix mat1{vector1, 3, 3};
    Matrix mat3{vector3, 3, 3};
    Matrix mat4{vector4, 3, 3};
    Matrix mat6{vector6, 3, 3};
    CHECK_NOTHROW(boolean=mat4 < mat1);
    CHECK_NOTHROW(boolean=mat1< mat3);
    CHECK((mat4 < mat1)== true);
    CHECK((mat1 < mat3)== true);
    CHECK((mat1 < mat6)== true);
    CHECK((mat3 < mat6)== true);
    CHECK((mat4+mat4 < mat4)== true);
    CHECK((mat6 < mat3)== false);
    CHECK((mat4 < mat4+mat4)== false);

}
TEST_CASE("Wrong value >="){
    Matrix mat1{vector1, 3, 3};
    Matrix mat2{vector2, 2, 2};
    CHECK_THROWS(boolean=mat1>=mat2);
    CHECK_THROWS(boolean=mat2>=mat1);
}
TEST_CASE("good inputs >=") {
    Matrix mat1{vector1, 3, 3};
    Matrix mat2{vector2, 2, 2};
    Matrix mat3{vector3, 3, 3};
    Matrix mat4{vector4, 3, 3};
    Matrix mat5{vector5, 3, 3};
    Matrix mat6{vector6, 3, 3};

    //==
    CHECK_NOTHROW(boolean=mat3>=mat1);
    CHECK_NOTHROW(boolean=mat4>=mat3);
    CHECK((mat1>=mat1)== true);
    CHECK((mat2 >= mat2)== true);
    CHECK((mat3-mat3 >= mat5)== true);
    CHECK((mat6-mat1 >= mat3)== true);
    //>
    CHECK_NOTHROW(boolean= mat1>= mat4);
    CHECK_NOTHROW(boolean=mat3>=mat1 );
    CHECK((mat1 >= mat4)== true);
    CHECK((mat3 >=  mat1)== true);
    CHECK((mat6 >=  mat1)== true);
    CHECK((mat6 >=  mat3)== true);
    CHECK((mat4 >= mat4+mat4)== true);
    CHECK((mat3 >=  mat6)== false);
    CHECK((mat4+mat4 >= mat4)== false);

}
TEST_CASE("Wrong value >"){
    Matrix mat1{vector1, 3, 3};
    Matrix mat2{vector2, 2, 2};
    CHECK_THROWS(boolean=mat1>mat1);
    CHECK_THROWS(boolean=mat2>mat1);
}
TEST_CASE("good inputs >") {
    Matrix mat1{vector1, 3, 3};
    Matrix mat3{vector3, 3, 3};
    Matrix mat4{vector4, 3, 3};
    Matrix mat6{vector6, 3, 3};
    CHECK_NOTHROW(boolean= mat1>= mat4);
    CHECK_NOTHROW(boolean=mat3>=mat1 );
    CHECK((mat1 > mat4)== true);
    CHECK((mat3 >  mat1)== true);
    CHECK((mat6 >  mat1)== true);
    CHECK((mat6 >  mat3)== true);
    CHECK((mat4 > mat4+mat4)== true);
    CHECK((mat3 >  mat6)== false);
    CHECK((mat4+mat4 > mat4)== false);
}
TEST_CASE("Wrong value !="){
    Matrix mat1{vector1, 3, 3};
    Matrix mat2{vector2, 2, 2};
    CHECK_THROWS(boolean=mat1!=mat2);
    CHECK_THROWS(boolean=mat2!=mat1);
}
TEST_CASE("good inputs !=") {
    Matrix mat1{vector1, 3, 3};
    Matrix mat3{vector3, 3, 3};
    Matrix mat4{vector4, 3, 3};
    Matrix mat6{vector6, 3, 3};
    CHECK_NOTHROW(boolean= mat1!= mat4);
    CHECK_NOTHROW(boolean=mat3!=mat1);
    CHECK((mat1 != mat4)== true);
    CHECK((mat3 !=  mat1)== true);
    CHECK((mat6 !=  mat1)== true);
    CHECK((mat6 !=  mat3)== true);
    CHECK((mat6 != mat4+mat4)== true);

}
TEST_CASE("good inputs * number") {
    Matrix mat1{vector1, 3, 3};
    Matrix mat2{vector2, 2, 2};
    Matrix mat3{vector3, 3, 3};
    Matrix mat5{vector5, 3, 3};
    Matrix mat10{vector10, 2, 2};
    CHECK_NOTHROW(mat3*2);
    CHECK_NOTHROW(mat2*3);
    CHECK((mat3*1 == mat3)== true);
    CHECK((mat1*0 == mat5)== true);
    CHECK((mat1*0 == mat5)== true);
    CHECK((mat2*0 == mat5)== true);
    CHECK((mat3*0 == mat5)== true);
    CHECK((0*mat5 == mat5)== true);
    CHECK((2*mat2 == mat10)== true);
}
TEST_CASE("good inputs *= number") {
    Matrix mat1{vector1, 3, 3};
    Matrix mat2{vector2, 2, 2};
    Matrix mat3{vector3, 3, 3};
    Matrix mat5{vector5, 3, 3};
    Matrix mat10{vector10, 2, 2};
    CHECK_NOTHROW(mat3*2);
    CHECK_NOTHROW(mat2*3);
    CHECK(((mat3*=1) == mat3)== true);
    CHECK(((mat1*=0) == mat5)== true);
    CHECK(((mat1*=0) == mat5)== true);
    CHECK(((mat2*=0) == mat5)== true);
    CHECK(((mat3*=0) == mat5)== true);
    CHECK(((mat5*=0) == mat5)== true);
    CHECK(((mat2*=2) == mat10)== true);
}

TEST_CASE("Wrong value * matrix"){
    Matrix mat1{vector1, 3, 3};
    Matrix mat2{vector2, 2, 2};
    CHECK_THROWS(mat1*mat2);
    CHECK_THROWS(mat2*mat1);
}
TEST_CASE("good inputs * matrix") {
    Matrix mat2{vector2, 2, 2};
    Matrix mat3{vector3, 3, 3};
    Matrix mat4{vector4, 3, 3};
    Matrix mat7{vector7, 3, 3};
    Matrix mat8{vector8, 3, 2};
    Matrix mat9{vector9, 3, 2};
    CHECK_NOTHROW(mat3*mat4);
    CHECK_NOTHROW(mat2*mat8);
    CHECK((mat3*mat4 == mat7)== true);
    CHECK((mat2*mat8 == mat9)== true);
}

TEST_CASE("Wrong value *= matrix"){
    Matrix mat1{vector1, 3, 3};
    Matrix mat2{vector2, 2, 2};
    CHECK_THROWS(mat1*=mat2);
    CHECK_THROWS(mat2*=mat1);
}
TEST_CASE("good inputs *= matrix") {
    Matrix mat2{vector2, 2, 2};
    Matrix mat3{vector3, 3, 3};
    Matrix mat4{vector4, 3, 3};
    Matrix mat7{vector7, 3, 3};
    Matrix mat8{vector8, 3, 2};
    Matrix mat9{vector9, 3, 2};
    CHECK_NOTHROW(mat3*=mat4);
    CHECK_NOTHROW(mat2*=mat8);
    CHECK(((mat3*=mat4) == mat7)== true);
    CHECK(((mat2*=mat8) == mat9)== true);
}

TEST_CASE("good inputs ++i") {
    Matrix mat1{vector1, 3, 3};
    Matrix mat2{vector2, 2, 2};
    Matrix mat3{vector3, 3, 3};
    Matrix mat5{vector5, 3, 3};
    Matrix mat6{vector6, 3, 3};
    Matrix mat7{vector7, 3, 3};
    Matrix mat11{vector11, 3, 3};
    CHECK_NOTHROW(++mat3);
    CHECK_NOTHROW(++mat2);
    CHECK((++mat1 == mat1+mat11)== true);
    CHECK((++mat5 == mat5+mat11)== true);
    CHECK((++mat7 == mat7+mat11)== true);
    CHECK((++mat6 == mat6+mat11)== true);
}
TEST_CASE("good inputs i++") {
    Matrix mat1{vector1, 3, 3};
    Matrix mat2{vector2, 2, 2};
    Matrix mat3{vector3, 3, 3};
    Matrix mat5{vector5, 3, 3};
    Matrix mat11(vector11,3,3);
    CHECK_NOTHROW(mat3++);
    CHECK_NOTHROW(mat2++);
    Matrix m1 = mat1+mat11;
    CHECK((mat1++ == mat1)== true);
    mat1++;
    CHECK((mat1 == m1)== true);
    Matrix m2 = mat5+mat11;
    mat5++;
    CHECK((mat5 == m2)== true);

}
TEST_CASE("good inputs --i") {
    Matrix mat1{vector1, 3, 3};
    Matrix mat2{vector2, 2, 2};
    Matrix mat3{vector3, 3, 3};
    Matrix mat5{vector5, 3, 3};
    Matrix mat6{vector6, 3, 3};
    Matrix mat7{vector7, 3, 3};
    Matrix mat11{vector11, 3, 3};
    CHECK_NOTHROW(--mat3);
    CHECK_NOTHROW(--mat2);
    CHECK((--mat1 == mat1-mat11)== true);
    CHECK((--mat5 == mat5-mat11)== true);
    CHECK((--mat7 == mat7-mat11)== true);
    CHECK((--mat6 == mat6-mat11)== true);
}
TEST_CASE("good inputs i--") {
    Matrix mat1{vector1, 3, 3};
    Matrix mat2{vector2, 2, 2};
    Matrix mat3{vector3, 3, 3};
    Matrix mat5{vector5, 3, 3};
    Matrix mat11{vector11, 3, 3};
    CHECK_NOTHROW(mat3--);
    CHECK_NOTHROW(mat2--);
    Matrix m1 = mat1-mat11;
    CHECK((mat1-- == mat1)== true);
    mat1--;
    CHECK((mat1 == m1)== true);
    Matrix m2 = mat5-mat11;
    mat5--;
    CHECK((mat5 == m2)== true);
}
TEST_CASE("check <<") {
    Matrix mat1{vector1, 3, 3};
    Matrix mat2{vector2, 2, 2};
    Matrix mat3{vector3, 3, 3};
    Matrix mat4{vector4, 3, 3};
    CHECK_NOTHROW(cout<<mat1);
    CHECK_NOTHROW(cout<<mat2);
    CHECK_NOTHROW(cout<<mat3);
    CHECK_NOTHROW(cout<<mat4);
}
TEST_CASE("check >>") {

    Matrix m1;
    Matrix m2;
    Matrix m3;
    Matrix m4;
    CHECK_NOTHROW(cin>>m1);
    CHECK_NOTHROW(cin>>m2);
    CHECK_NOTHROW(cin>>m3);
    CHECK_NOTHROW(cin>>m4);
}






