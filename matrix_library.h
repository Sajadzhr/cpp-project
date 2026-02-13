#ifndef MATRIX_LIBRARY_H
#define MATRIX_LIBRARY_H

const int MAX_SIZE = 100;

bool matrixAdd(double mat1[][MAX_SIZE], int rows1, int cols1,
               double mat2[][MAX_SIZE], int rows2, int cols2,
               double result[][MAX_SIZE]);

bool matrixSubtract(double mat1[][MAX_SIZE], int rows1, int cols1,
                   double mat2[][MAX_SIZE], int rows2, int cols2,
                   double result[][MAX_SIZE]);

bool matrixMultiply(double mat1[][MAX_SIZE], int rows1, int cols1,
                   double mat2[][MAX_SIZE], int rows2, int cols2,
                   double result[][MAX_SIZE], int &resultRows, int &resultCols);

void matrixScalarMultiply(double mat[][MAX_SIZE], int rows, int cols,
                         double scalar, double result[][MAX_SIZE]);

void matrixTranspose(double mat[][MAX_SIZE], int rows, int cols,
                    double result[][MAX_SIZE]);

bool matrixDeterminant(double mat[][MAX_SIZE], int size, double &det);

bool matrixInverse(double mat[][MAX_SIZE], int size, double result[][MAX_SIZE]);

bool vectorAdd(double vec1[], int size1, double vec2[], int size2,
              double result[], int &resultSize);

bool vectorSubtract(double vec1[], int size1, double vec2[], int size2,
                   double result[], int &resultSize);

void vectorScalarMultiply(double vec[], int size, double scalar,
                         double result[]);

bool vectorDotProduct(double vec1[], int size1, double vec2[], int size2,
                     double &result);

bool vectorCrossProduct(double vec1[], double vec2[], double result[]);

double vectorMagnitude(double vec[], int size);

bool vectorNormalize(double vec[], int size, double result[]);

void printMatrix(double mat[][MAX_SIZE], int rows, int cols, const char* name);

void printVector(double vec[], int size, const char* name);

#endif
