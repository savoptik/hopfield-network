//
//  wMatrix.hpp
//  hopfield network
//
//  Created by Артём Семёнов on 22/09/2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#ifndef wMatrix_hpp
#define wMatrix_hpp

#include <stdio.h>
#include "../matrix.hpp"

class wMatrix: public matrix {
public:
    wMatrix(matrix &xMatrix); // принимает матрицу x, создаёт по нему квадратную матрицу.
    /**
     метод создаёт w матрицу.
     */
    void generaitWMatrix();
    double& at( int i, int j);
    std::vector<double>& data();
private:
    std::vector<double> matrixInLine;
    matrix xMat;
};

#endif /* wMatrix_hpp */
