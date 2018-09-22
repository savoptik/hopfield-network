//
//  neuronet.cpp
//  hopfield network
//
//  Created by Артём Семёнов on 22/09/2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#include "neuronet.hpp"

neuronet::neuronet(matrix &xMat, wMatrix &wMat, distortedSignal &dSignal) { 
    xm = xMat;
    xMat.~matrix();
    wm = wMat;
    wMat.~wMatrix();
    ds = dSignal;
    dSignal.~distortedSignal();
}
