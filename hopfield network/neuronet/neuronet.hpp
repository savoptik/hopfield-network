//
//  neuronet.hpp
//  hopfield network
//
//  Created by Артём Семёнов on 22/09/2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#ifndef neuronet_hpp
#define neuronet_hpp

#include <stdio.h>
#include "../dataSet/dataSet.hpp"
#include "../dataSet/imageDataSet/imageDataSet.hpp"
#include "../matrix/w_matrix/wMatrix.hpp"
#include "../distorted_signal/distortedSignal.hpp"

class neuronet {
public:
    neuronet() {}
    neuronet(matrix &xMat, wMatrix &wMat, distortedSignal &dSignal);
private:
    matrix xm;
    wMatrix wm;
    distortedSignal ds;
    std::vector<int> resultVector;
};

#endif /* neuronet_hpp */