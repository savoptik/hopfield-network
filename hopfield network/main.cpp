//
//  main.cpp
//  hopfield network
//
//  Created by Артём Семёнов on 21/09/2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#include <iostream>
#include "neuronet//neuronet.hpp"

int main(int argc, const char * argv[]) {

    dataSet ds(argv[1]);
    imageDataSet ids(argv[1], ds);
    std::cout << "загружено " << ids.getImageSet().size() << " изображений" << std::endl;
    ids.generaitInLineForm();
    std::cout << "Получена матрица размером " << ids.getInlineMatrix().rows() << ":" << ids.getInlineMatrix().cols() << " содержащая " << ids.getInlineMatrix().size() << " элементов" << std::endl;
    wMatrix wm(ids.getInlineMatrix());
    wm.generaitWMatrix();
    std::cout << "получена матрица размером" << wm.rows() << ":" << wm.cols() << " содержащая " << wm.size() << " элементов" << std::endl;
    distortedSignal dSignal(argv[2]);
    dSignal.toDistortTheSignal();
    matrix xm = ids.getInlineMatrix();
    neuronet nt(xm, wm, dSignal);
     nt.ranNV();
    return 0;
}
