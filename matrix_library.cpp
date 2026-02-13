#include <iostream>
#include <cmath>
#include "matrix_library.h"

using namespace std;

bool matrixAdd(double mat1[][MAX_SIZE], int rows1, int cols1,
               double mat2[][MAX_SIZE], int rows2, int cols2,
               double result[][MAX_SIZE]) {
    if (rows1 != rows2 || cols1 != cols2) {
        cout << "ERROR: Matrix dimensions do not match for addition!" << endl;
        cout << "Matrix 1: " << rows1 << "x" << cols1 << endl;
        cout << "Matrix 2: " << rows2 << "x" << cols2 << endl;
        return false;
    }

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }

    return true;
}

bool matrixSubtract(double mat1[][MAX_SIZE], int rows1, int cols1,
                   double mat2[][MAX_SIZE], int rows2, int cols2,
                   double result[][MAX_SIZE]) {
    if (rows1 != rows2 || cols1 != cols2) {
        cout << "ERROR: Matrix dimensions do not match for subtraction!" << endl;
        cout << "Matrix 1: " << rows1 << "x" << cols1 << endl;
        cout << "Matrix 2: " << rows2 << "x" << cols2 << endl;
        return false;
    }

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }

    return true;
}

bool matrixMultiply(double mat1[][MAX_SIZE], int rows1, int cols1,
                   double mat2[][MAX_SIZE], int rows2, int cols2,
                   double result[][MAX_SIZE], int &resultRows, int &resultCols) {
    if (cols1 != rows2) {
        cout << "ERROR: Invalid dimensions for matrix multiplication!" << endl;
        cout << "Matrix 1: " << rows1 << "x" << cols1 << endl;
        cout << "Matrix 2: " << rows2 << "x" << cols2 << endl;
        cout << "Columns of first matrix must equal rows of second matrix!" << endl;
        return false;
    }

    resultRows = rows1;
    resultCols = cols2;

    for (int i = 0; i < resultRows; i++) {
        for (int j = 0; j < resultCols; j++) {
            result[i][j] = 0.0;
        }
    }

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            for (int k = 0; k < cols1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    return true;
}

void matrixScalarMultiply(double mat[][MAX_SIZE], int rows, int cols,
                         double scalar, double result[][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat[i][j] * scalar;
        }
    }
}

void matrixTranspose(double mat[][MAX_SIZE], int rows, int cols,
                    double result[][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = mat[i][j];
        }
    }
}

void getMinorMatrix(double mat[][MAX_SIZE], int size, int row, int col,
                    double minor[][MAX_SIZE]) {
    int minorRow = 0;
    for (int i = 0; i < size; i++) {
        if (i == row) continue;

        int minorCol = 0;
        for (int j = 0; j < size; j++) {
            if (j == col) continue;

            minor[minorRow][minorCol] = mat[i][j];
            minorCol++;
        }
        minorRow++;
    }
}

double calculateDeterminantRecursive(double mat[][MAX_SIZE], int size) {
    if (size == 1) {
        return mat[0][0];
    }
    if (size == 2) {
        return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
    }
    double det = 0.0;
    double minor[MAX_SIZE][MAX_SIZE];

    for (int col = 0; col < size; col++) {
        getMinorMatrix(mat, size, 0, col, minor);

        double cofactor = mat[0][col] * calculateDeterminantRecursive(minor, size - 1);

        if (col % 2 == 0) {
            det += cofactor;
        } else {
            det -= cofactor;
        }
    }

    return det;
}

bool matrixDeterminant(double mat[][MAX_SIZE], int size, double &det) {
    if (size <= 0 || size > MAX_SIZE) {
        cout << "ERROR: Invalid matrix size!" << endl;
        cout << "Size must be between 1 and " << MAX_SIZE << endl;
        return false;
    }

    det = calculateDeterminantRecursive(mat, size);

    return true;
}

bool matrixInverse(double mat[][MAX_SIZE], int size, double result[][MAX_SIZE]) {
    if (size != 2) {
        cout << "ERROR: Matrix inverse only supported for 2x2 matrices!" << endl;
        cout << "Matrix size: " << size << "x" << size << endl;
        return false;
    }

    double det = mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];

    if (fabs(det) == 0) {
        cout << "ERROR: Matrix is singular (determinant = 0)! Cannot find inverse." << endl;
        return false;
    }

    result[0][0] =  mat[1][1] / det;
    result[0][1] = -mat[0][1] / det;
    result[1][0] = -mat[1][0] / det;
    result[1][1] =  mat[0][0] / det;

    return true;
}

bool vectorAdd(double vec1[], int size1, double vec2[], int size2,
              double result[], int &resultSize) {
    if (size1 != size2) {
        cout << "ERROR: Vector sizes do not match for addition!" << endl;
        cout << "Vector 1 size: " << size1 << endl;
        cout << "Vector 2 size: " << size2 << endl;
        return false;
    }

    resultSize = size1;

    for (int i = 0; i < size1; i++) {
        result[i] = vec1[i] + vec2[i];
    }

    return true;
}

bool vectorSubtract(double vec1[], int size1, double vec2[], int size2,
                   double result[], int &resultSize) {
    if (size1 != size2) {
        cout << "ERROR: Vector sizes do not match for subtraction!" << endl;
        cout << "Vector 1 size: " << size1 << endl;
        cout << "Vector 2 size: " << size2 << endl;
        return false;
    }

    resultSize = size1;

    for (int i = 0; i < size1; i++) {
        result[i] = vec1[i] - vec2[i];
    }

    return true;
}

void vectorScalarMultiply(double vec[], int size, double scalar,
                         double result[]) {
    for (int i = 0; i < size; i++) {
        result[i] = vec[i] * scalar;
    }
}

bool vectorDotProduct(double vec1[], int size1, double vec2[], int size2,
                     double &result) {
    if (size1 != size2) {
        cout << "ERROR: Vector sizes do not match for dot product!" << endl;
        cout << "Vector 1 size: " << size1 << endl;
        cout << "Vector 2 size: " << size2 << endl;
        return false;
    }

    result = 0.0;

    for (int i = 0; i < size1; i++) {
        result += vec1[i] * vec2[i];
    }

    return true;
}

bool vectorCrossProduct(double vec1[], double vec2[], double result[]) {
    result[0] = vec1[1] * vec2[2] - vec1[2] * vec2[1];
    result[1] = vec1[2] * vec2[0] - vec1[0] * vec2[2];
    result[2] = vec1[0] * vec2[1] - vec1[1] * vec2[0];

    return true;
}

double vectorMagnitude(double vec[], int size) {
    double sum = 0.0;

    for (int i = 0; i < size; i++) {
        sum += vec[i] * vec[i];
    }

    return sqrt(sum);
}

bool vectorNormalize(double vec[], int size, double result[]) {
    double mag = vectorMagnitude(vec, size);

    if (fabs(mag) == 0) {
        cout << "ERROR: Cannot normalize zero vector!" << endl;
        return false;
    }

    for (int i = 0; i < size; i++) {
        result[i] = vec[i] / mag;
    }

    return true;
}

void printMatrix(double mat[][MAX_SIZE], int rows, int cols, const char* name) {
    cout << "\n" << name << " (" << rows << "x" << cols << "):" << endl;
    for (int i = 0; i < rows; i++) {
        cout << "[";
        for (int j = 0; j < cols; j++) {
            cout << mat[i][j];
            if (j < cols - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
}

void printVector(double vec[], int size, const char* name) {
    cout << "\n" << name << " (size " << size << "): [";
    for (int i = 0; i < size; i++) {
        cout << vec[i];
        if (i < size - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}
