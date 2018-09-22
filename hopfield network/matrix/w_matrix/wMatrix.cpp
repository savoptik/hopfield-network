//
//  wMatrix.cpp
//  hopfield network
//
//  Created by Артём Семёнов on 22/09/2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#include "wMatrix.hpp"
#include <iostream>

wMatrix::wMatrix(matrix &xMatrix) { 
    mHaid = xMatrix.cols();
    mWits = xMatrix.cols();
    mSize = mHaid * mWits;
    matrixInLine.resize(mSize);
    xMat = matrix(xMatrix.rows(), xMatrix.cols());
    xMat.data() = xMatrix.data();
}

void wMatrix::generaitWMatrix() { 
    for (int i = 0; i < rows(); i++) {
        for (int j = 0; j < cols(); j++) {
            if (i == j) {
                at(i, j) = 0;
            } else {
                for (int k = 0; k < xMat.rows(); k++) {
                    at(i, j) += xMat.at(k, i) * xMat.at(k, j);
                }
                at(i, j) = at(i, j)/rows();
             }
        }
    }
}

std::vector<double> &wMatrix::data() { 
     return matrixInLine;
}

double &wMatrix::at(int i, int j) { 
    int index = i* mWits + j;
    return matrixInLine[index];
}

