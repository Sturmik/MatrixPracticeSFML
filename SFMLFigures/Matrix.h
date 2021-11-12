#pragma once

#include <corecrt_math.h>

namespace matrix
{ 
struct Matrix3x3;

// Identity matrix
void Identity(Matrix3x3& mat);
// Translate matrix
void Translate(Matrix3x3& mat, float ox, float oy);
// Rotate matrix
void Rotate(Matrix3x3& mat, float fTheta);
// Rotate matrix
void Scale(Matrix3x3& mat, float sx, float sy);
// Shear matrix
void Shear(Matrix3x3& mat, float sx, float sy);
// Matrix addition
void MatrixAddition(Matrix3x3& mathResult, Matrix3x3& matA, Matrix3x3& matB);
// Matrix subtraction
void MatrixSubtraction(Matrix3x3& mathResult, Matrix3x3& matA, Matrix3x3& matB);
// Matrix multiply
void MatrixMultiply(Matrix3x3& mathResult, Matrix3x3& matA, Matrix3x3& matB);
// Apply calculations to coordinates
void Forward(Matrix3x3& mat, float int_x, float int_y, float& out_x, float& out_y);

// Matrix struct
//   | x x x |
//   | x x x | 
//   | x x x |
struct Matrix3x3
{
    // Matrix [row][column]
    float m[3][3];

    Matrix3x3()
    {
        Identity(*this);
    }
};
}