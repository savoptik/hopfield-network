//
//  neuronet.cpp
//  hopfield network
//
//  Created by Артём Семёнов on 22/09/2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#include "neuronet.hpp"

neuronet::neuronet(matrix xMat, wMatrix wMat, distortedSignal dSignal) { 
    xm = xMat;
    wm = wMat;
    ds = dSignal;
}

std::vector<double> neuronet::activation(std::vector<double> y_prev) { 
    std::vector<double> y_t;
    y_t.resize(y_prev.size());
    for (int i = 0; i < wm.rows(); i++) {
        for (int j = 0; j < wm.cols(); j++) {
                y_t[i] += wm.at(i, j) * y_prev[j];
        }
    }
    return y_t;
}

int neuronet::ToObtainThePercentageOfMatches(std::vector<double> y_prev, std::vector<double> y_t) { 
    int coincidences = 0;
    std::vector<int> v1 = convertToBiPolarVector(y_prev);
    std::vector<int> v2 = convertToBiPolarVector(y_t);
    for (int i = 0; i < y_prev.size(); i++) {
        coincidences = v1[i] == v2[i]? coincidences++: coincidences;
    }
    return coincidences * 100 / y_t.size();
}

std::vector<int> neuronet::convertToBiPolarVector(std::vector<double> vec) { 
    std::vector<int> res;
    res.resize(vec.size());
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] > 0) {
            res[i] = 1;
        } else if (vec[i] < 0) {
            res[i] = -1;
        } else res[i] = 0;
    }
    return res;
}

void neuronet::ranNV() { 
    std::vector<double> y_t;
    y_t.resize(ds.data().size());
    std::vector<double> y_prev;
    y_prev.resize(y_t.size());
    for (int i = 0; i < y_prev.size(); i++) {
        y_prev[i] = ds.data()[i];
    }
    while (ToObtainThePercentageOfMatches(y_prev, y_t) <= 90) {
        y_t = activation(y_prev);
    }
}




