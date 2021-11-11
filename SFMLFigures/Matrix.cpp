#include "Matrix.h"

// Identity matrix
void matrix::Identity(Matrix3x3& mat)
{
    mat.m[0][0] = 1.0f; mat.m[0][1] = 0.0f; mat.m[0][2] = 0.0f;
    mat.m[1][0] = 0.0f; mat.m[1][1] = 1.0f; mat.m[1][2] = 0.0f;
    mat.m[2][0] = 0.0f; mat.m[2][1] = 0.0f; mat.m[2][2] = 1.0f;
}

// Translate matrix
void matrix::Translate(Matrix3x3& mat, float ox, float oy)
{
    mat.m[0][0] = 1.0f; mat.m[0][1] = 0.0f; mat.m[0][2] = ox;
    mat.m[1][0] = 0.0f; mat.m[1][1] = 1.0f; mat.m[1][2] = oy;
    mat.m[2][0] = 0.0f; mat.m[2][1] = 0.0f; mat.m[2][2] = 1.0f;
}

// Rotate matrix
void matrix::Rotate(Matrix3x3& mat, float fTheta)
{
    mat.m[0][0] = cosf(fTheta); mat.m[0][1] = sinf(fTheta); mat.m[0][2] = 0.0f;
    mat.m[1][0] = -sinf(fTheta); mat.m[1][1] = cosf(fTheta); mat.m[1][2] = 0.0f;
    mat.m[2][0] = 0.0f; mat.m[2][1] = 0.0f; mat.m[2][2] = 1.0f;
}

// Rotate matrix
void matrix::Scale(Matrix3x3& mat, float sx, float sy)
{
    mat.m[0][0] = sx; mat.m[0][1] = 0.0f; mat.m[0][2] = 0.0f;
    mat.m[1][0] = 0.0f; mat.m[1][1] = sy; mat.m[1][2] = 0.0f;
    mat.m[2][0] = 0.0f; mat.m[2][1] = 0.0f; mat.m[2][2] = 1.0f;
}

void matrix::Shear(Matrix3x3& mat, float sx, float sy)
{
    mat.m[0][0] = 1.0f; mat.m[0][1] = sx; mat.m[0][2] = 0.0f;
    mat.m[1][0] = sy;   mat.m[1][1] = 1.0f; mat.m[1][2] = 0.0f;
    mat.m[2][0] = 0.0f; mat.m[2][1] = 0.0f; mat.m[2][2] = 1.0f;
}

void matrix::MatrixAddition(Matrix3x3& mathResult, Matrix3x3& matA, Matrix3x3& matB)
{
    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            mathResult.m[r][c] = matA.m[r][c] + matB.m[r][c];
        }
    }
}

void matrix::MatrixSubtraction(Matrix3x3& mathResult, Matrix3x3& matA, Matrix3x3& matB)
{
    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            mathResult.m[r][c] = matA.m[r][c] - matB.m[r][c];
        }
    }
}

// Matrix multiply
void matrix::MatrixMultiply(Matrix3x3& mathResult, Matrix3x3& matA, Matrix3x3& matB)
{
    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            mathResult.m[r][c] = matA.m[r][0] * matB.m[0][c] +
                matA.m[r][1] * matB.m[1][c] +
                matA.m[r][2] * matB.m[2][c];
        }
    }
}

// Apply calculations to coordinates
void matrix::Forward(Matrix3x3& mat, float int_x, float int_y, float& out_x, float& out_y)
{
    out_x = int_x * mat.m[0][0] + int_y * mat.m[0][1] + mat.m[0][2];
    out_y = int_x * mat.m[1][0] + int_y * mat.m[1][1] + mat.m[1][2];
}