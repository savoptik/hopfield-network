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
    mHaid =  rows;
    mWits = cols;
    mSize = mHaid * mWits;
    matrixInLine.resize(mSize);
}

matrix::~matrix() { 
    matrixInLine.~vector();
}

