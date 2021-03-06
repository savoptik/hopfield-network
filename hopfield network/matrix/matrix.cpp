//
//  matrix.cpp
//  hopfield network
//
//  Created by Артём Семёнов on 21/09/2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#include "matrix.hpp"

std::vector<int> &matrix::data() { 
    return matrixInLine;
}

int &matrix::at(int i, int j) {
    int index = i * mWits + j; // вычисление линейного индекса по координатам.
    return matrixInLine[index];
}

int matrix::rows() { 
    return mHaid;
}

int matrix::cols() { 
    return mWits;
}

int matrix::size() { 
    return mSize;
}

matrix::matrix(int rows, int cols) {
    // записываем все измерения матрицы
    mHaid =  rows;
    mWits = cols;
    mSize = mHaid * mWits;
    // выделяем память
    matrixInLine.resize(mSize);
}


void matrix::generaitInMatrixForm() {
    if (matrixInLine.size() == 0) {
        return;
    }
    matrixInMatrixForm.resize(rows());
    for (int i = 0; i < matrixInMatrixForm.size(); i++) {
        for (int j = 0; j < cols(); j++) {
            matrixInMatrixForm[i].resize(cols());
            matrixInMatrixForm[i][j] = at(i, j);
        }
    }
}

std::vector<std::vector<int> > &matrix::getMatrixInMatrixForm() { 
    return matrixInMatrixForm;
}

