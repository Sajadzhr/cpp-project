#include <iostream>
#include <iomanip>
#include "matrix_library.h"

using namespace std;

void displayMenu() {
    cout << "\n========================================" << endl;
    cout << "MATRIX AND VECTOR OPERATIONS" << endl;
    cout << "========================================" << endl;
    cout << "MATRIX OPERATIONS:" << endl;
    cout << "  1. Matrix Addition" << endl;
    cout << "  2. Matrix Subtraction" << endl;
    cout << "  3. Matrix Multiplication" << endl;
    cout << "  4. Scalar Multiplication of Matrix" << endl;
    cout << "  5. Matrix Transpose" << endl;
    cout << "  6. Matrix Determinant" << endl;
    cout << "  7. Matrix Inverse" << endl;
    cout << "\nVECTOR OPERATIONS:" << endl;
    cout << "  8. Vector Addition" << endl;
    cout << "  9. Vector Subtraction" << endl;
    cout << " 10. Scalar Multiplication of Vector" << endl;
    cout << " 11. Dot Product" << endl;
    cout << " 12. Cross Product (3D only)" << endl;
    cout << " 13. Vector Magnitude" << endl;
    cout << " 14. Vector Normalization" << endl;
    cout << "\n  0. Exit" << endl;
    cout << "========================================" << endl;
    cout << "Enter your choice: ";
}

void inputMatrix(double mat[][MAX_SIZE], int &rows, int &cols, const char* name) {
    cout << "\nEnter dimensions for " << name << endl;
    cout << "Number of rows (1-" << MAX_SIZE << "): ";
    cin >> rows;
    cout << "Number of columns (1-" << MAX_SIZE << "): ";
    cin >> cols;

    if (rows < 1 || rows > MAX_SIZE || cols < 1 || cols > MAX_SIZE) {
        cout << "ERROR: Invalid dimensions!" << endl;
        rows = 0;
        cols = 0;
        return;
    }

    cout << "\nEnter elements of " << name << " (row by row):" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Element [" << i+1 << "][" << j+1 << "]: ";
            cin >> mat[i][j];
        }
    }
}

void inputVector(double vec[], int &size, const char* name) {
    cout << "\nEnter size for " << name << " (1-" << MAX_SIZE << "): ";
    cin >> size;

    if (size < 1 || size > MAX_SIZE) {
        cout << "ERROR: Invalid size!" << endl;
        size = 0;
        return;
    }

    cout << "Enter elements of " << name << ":" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Element [" << i+1 << "]: ";
        cin >> vec[i];
    }
}

void matrixAdditionOp() {
    double mat1[MAX_SIZE][MAX_SIZE], mat2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rows1, cols1, rows2, cols2;

    cout << "\n=== MATRIX ADDITION ===" << endl;

    inputMatrix(mat1, rows1, cols1, "Matrix A");
    if (rows1 == 0) return;

    inputMatrix(mat2, rows2, cols2, "Matrix B");
    if (rows2 == 0) return;

    printMatrix(mat1, rows1, cols1, "Matrix A");
    printMatrix(mat2, rows2, cols2, "Matrix B");

    cout << "\nOperation: A + B" << endl;

    if (matrixAdd(mat1, rows1, cols1, mat2, rows2, cols2, result)) {
        printMatrix(result, rows1, cols1, "Result");
    }
}

void matrixSubtractionOp() {
    double mat1[MAX_SIZE][MAX_SIZE], mat2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rows1, cols1, rows2, cols2;

    cout << "\n=== MATRIX SUBTRACTION ===" << endl;

    inputMatrix(mat1, rows1, cols1, "Matrix A");
    if (rows1 == 0) return;

    inputMatrix(mat2, rows2, cols2, "Matrix B");
    if (rows2 == 0) return;

    printMatrix(mat1, rows1, cols1, "Matrix A");
    printMatrix(mat2, rows2, cols2, "Matrix B");

    cout << "\nOperation: A - B" << endl;

    if (matrixSubtract(mat1, rows1, cols1, mat2, rows2, cols2, result)) {
        printMatrix(result, rows1, cols1, "Result");
    }
}

void matrixMultiplicationOp() {
    double mat1[MAX_SIZE][MAX_SIZE], mat2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rows1, cols1, rows2, cols2, resultRows, resultCols;

    cout << "\n=== MATRIX MULTIPLICATION ===" << endl;

    inputMatrix(mat1, rows1, cols1, "Matrix A");
    if (rows1 == 0) return;

    inputMatrix(mat2, rows2, cols2, "Matrix B");
    if (rows2 == 0) return;

    printMatrix(mat1, rows1, cols1, "Matrix A");
    printMatrix(mat2, rows2, cols2, "Matrix B");

    cout << "\nOperation: A * B" << endl;

    if (matrixMultiply(mat1, rows1, cols1, mat2, rows2, cols2, result, resultRows, resultCols)) {
        printMatrix(result, resultRows, resultCols, "Result");
    }
}

void scalarMatrixMultiplicationOp() {
    double mat[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rows, cols;
    double scalar;

    cout << "\n=== SCALAR MULTIPLICATION OF MATRIX ===" << endl;

    inputMatrix(mat, rows, cols, "Matrix A");
    if (rows == 0) return;

    cout << "\nEnter scalar value: ";
    cin >> scalar;

    printMatrix(mat, rows, cols, "Matrix A");
    cout << "\nScalar: " << scalar << endl;
    cout << "Operation: " << scalar << " * A" << endl;

    matrixScalarMultiply(mat, rows, cols, scalar, result);
    printMatrix(result, rows, cols, "Result");
}

void matrixTransposeOp() {
    double mat[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rows, cols;

    cout << "\n=== MATRIX TRANSPOSE ===" << endl;

    inputMatrix(mat, rows, cols, "Matrix A");
    if (rows == 0) return;

    printMatrix(mat, rows, cols, "Matrix A");
    cout << "\nOperation: Transpose(A)" << endl;

    matrixTranspose(mat, rows, cols, result);
    printMatrix(result, cols, rows, "Result (Transposed)");
}

void matrixDeterminantOp() {
    double mat[MAX_SIZE][MAX_SIZE];
    int size;
    double det;

    cout << "\n=== MATRIX DETERMINANT ===" << endl;
    cout << "Note: Determinant is only calculated for square matrices (1x1, 2x2, 3x3)" << endl;

    cout << "\nEnter size of square matrix (1-3): ";
    cin >> size;

    if (size < 1 || size > 3) {
        cout << "ERROR: Size must be between 1 and 3!" << endl;
        return;
    }

    cout << "\nEnter elements of " << size << "x" << size << " matrix (row by row):" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << "Element [" << i+1 << "][" << j+1 << "]: ";
            cin >> mat[i][j];
        }
    }

    printMatrix(mat, size, size, "Matrix A");
    cout << "\nOperation: det(A)" << endl;

    if (matrixDeterminant(mat, size, det)) {
        cout << "\nDeterminant = " << det << endl;
    }
}

void matrixInverseOp() {
    double mat[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int size;

    cout << "\n=== MATRIX INVERSE ===" << endl;
    cout << "Note: Inverse is only calculated for 2x2 matrices" << endl;

    cout << "\nEnter elements of 2x2 matrix (row by row):" << endl;
    size = 2;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << "Element [" << i+1 << "][" << j+1 << "]: ";
            cin >> mat[i][j];
        }
    }

    printMatrix(mat, size, size, "Matrix A");
    cout << "\nOperation: A^(-1)" << endl;

    if (matrixInverse(mat, size, result)) {
        printMatrix(result, size, size, "Result (Inverse)");

        // Verify by multiplying A * A^(-1)
        double identity[MAX_SIZE][MAX_SIZE];
        int idRows, idCols;
        matrixMultiply(mat, size, size, result, size, size, identity, idRows, idCols);
        cout << "\nVerification: A * A^(-1) should equal Identity Matrix" << endl;
        printMatrix(identity, idRows, idCols, "A * A^(-1)");
    }
}

void vectorAdditionOp() {
    double vec1[MAX_SIZE], vec2[MAX_SIZE], result[MAX_SIZE];
    int size1, size2, resultSize;

    cout << "\n=== VECTOR ADDITION ===" << endl;

    inputVector(vec1, size1, "Vector u");
    if (size1 == 0) return;

    inputVector(vec2, size2, "Vector v");
    if (size2 == 0) return;

    printVector(vec1, size1, "Vector u");
    printVector(vec2, size2, "Vector v");

    cout << "\nOperation: u + v" << endl;

    if (vectorAdd(vec1, size1, vec2, size2, result, resultSize)) {
        printVector(result, resultSize, "Result");
    }
}

void vectorSubtractionOp() {
    double vec1[MAX_SIZE], vec2[MAX_SIZE], result[MAX_SIZE];
    int size1, size2, resultSize;

    cout << "\n=== VECTOR SUBTRACTION ===" << endl;

    inputVector(vec1, size1, "Vector u");
    if (size1 == 0) return;

    inputVector(vec2, size2, "Vector v");
    if (size2 == 0) return;

    printVector(vec1, size1, "Vector u");
    printVector(vec2, size2, "Vector v");

    cout << "\nOperation: u - v" << endl;

    if (vectorSubtract(vec1, size1, vec2, size2, result, resultSize)) {
        printVector(result, resultSize, "Result");
    }
}

void scalarVectorMultiplicationOp() {
    double vec[MAX_SIZE], result[MAX_SIZE];
    int size;
    double scalar;

    cout << "\n=== SCALAR MULTIPLICATION OF VECTOR ===" << endl;

    inputVector(vec, size, "Vector u");
    if (size == 0) return;

    cout << "\nEnter scalar value: ";
    cin >> scalar;

    printVector(vec, size, "Vector u");
    cout << "\nScalar: " << scalar << endl;
    cout << "Operation: " << scalar << " * u" << endl;

    vectorScalarMultiply(vec, size, scalar, result);
    printVector(result, size, "Result");
}

void dotProductOp() {
    double vec1[MAX_SIZE], vec2[MAX_SIZE];
    int size1, size2;
    double result;

    cout << "\n=== DOT PRODUCT (INNER PRODUCT) ===" << endl;

    inputVector(vec1, size1, "Vector u");
    if (size1 == 0) return;

    inputVector(vec2, size2, "Vector v");
    if (size2 == 0) return;

    printVector(vec1, size1, "Vector u");
    printVector(vec2, size2, "Vector v");

    cout << "\nOperation: u · v" << endl;

    if (vectorDotProduct(vec1, size1, vec2, size2, result)) {
        cout << "\nDot Product = " << result << endl;
    }
}

void crossProductOp() {
    double vec1[3], vec2[3], result[3];

    cout << "\n=== CROSS PRODUCT (OUTER PRODUCT - 3D ONLY) ===" << endl;
    cout << "Note: Cross product only works for 3D vectors" << endl;

    cout << "\nEnter elements of Vector u (3D):" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Element [" << i+1 << "]: ";
        cin >> vec1[i];
    }

    cout << "\nEnter elements of Vector v (3D):" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Element [" << i+1 << "]: ";
        cin >> vec2[i];
    }

    printVector(vec1, 3, "Vector u");
    printVector(vec2, 3, "Vector v");

    cout << "\nOperation: u × v" << endl;

    if (vectorCrossProduct(vec1, vec2, result)) {
        printVector(result, 3, "Result (Cross Product)");
    }
}

void vectorMagnitudeOp() {
    double vec[MAX_SIZE];
    int size;

    cout << "\n=== VECTOR MAGNITUDE ===" << endl;

    inputVector(vec, size, "Vector u");
    if (size == 0) return;

    printVector(vec, size, "Vector u");

    cout << "\nOperation: |u| (magnitude)" << endl;

    double mag = vectorMagnitude(vec, size);
    cout << "\nMagnitude = " << mag << endl;
}

void vectorNormalizationOp() {
    double vec[MAX_SIZE], result[MAX_SIZE];
    int size;

    cout << "\n=== VECTOR NORMALIZATION ===" << endl;

    inputVector(vec, size, "Vector u");
    if (size == 0) return;

    printVector(vec, size, "Vector u");

    cout << "\nOperation: normalize(u)" << endl;

    if (vectorNormalize(vec, size, result)) {
        printVector(result, size, "Result (Normalized - Unit Vector)");
        double mag = vectorMagnitude(result, size);
        cout << "\nMagnitude of normalized vector = " << mag << " (should be 1)" << endl;
    }
}

int main() {
    int choice;

    cout << "=========================================" << endl;
    cout << " MATRIX AND VECTOR OPERATIONS LIBRARY" << endl;
    cout << "=========================================" << endl;
    cout << "Student: Mohammadreza Zohouri" << endl;
    cout << "Student ID: 1404010121038" << endl;
    cout << "=========================================" << endl;

    while (true) {
        displayMenu();
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\nERROR: Invalid input! Please enter a number." << endl;
            continue;
        }

        switch (choice) {
            case 0:
                cout << "\nThank you for using the Matrix and Vector Operations Library!" << endl;
                cout << "Goodbye!" << endl;
                return 0;

            case 1:
                matrixAdditionOp();
                break;

            case 2:
                matrixSubtractionOp();
                break;

            case 3:
                matrixMultiplicationOp();
                break;

            case 4:
                scalarMatrixMultiplicationOp();
                break;

            case 5:
                matrixTransposeOp();
                break;

            case 6:
                matrixDeterminantOp();
                break;

            case 7:
                matrixInverseOp();
                break;

            case 8:
                vectorAdditionOp();
                break;

            case 9:
                vectorSubtractionOp();
                break;

            case 10:
                scalarVectorMultiplicationOp();
                break;

            case 11:
                dotProductOp();
                break;

            case 12:
                crossProductOp();
                break;

            case 13:
                vectorMagnitudeOp();
                break;

            case 14:
                vectorNormalizationOp();
                break;

            default:
                cout << "\nERROR: Invalid choice! Please select 0-14." << endl;
                break;
        }

        cout << "\nPress Enter to continue...";
        cin.ignore(10000, '\n');
        cin.get();
    }

    return 0;
}
