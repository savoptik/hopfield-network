//
//  matrix.hpp
//  hopfield network
//
//  Created by Артём Семёнов on 21/09/2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#ifndef matrix_hpp
#define matrix_hpp

#include <stdio.h>
#include <vector>

class matrix {
public:
    matrix() {}
    matrix(int rows, int cols);
    std::vector<int>& data();
    int& at(int i, int j);
    int rows();
    int cols();
    int size();
protected:
    std::vector<int> matrixInLine;
    int mHaid, mWits, mSize;
};

#endif /* matrix_hpp */
