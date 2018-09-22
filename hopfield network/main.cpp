//
//  main.cpp
//  hopfield network
//
//  Created by Артём Семёнов on 21/09/2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#include <iostream>
#include "dataSet/dataSet.hpp"
#include "dataSet/imageDataSet/imageDataSet.hpp"
#include "matrix/w_matrix/wMatrix.hpp"

int main(int argc, const char * argv[]) {

    dataSet ds(argv[1]);
    imageDataSet ids(argv[1], ds);
    std::cout << "загружено " << ids.getImageSet().size() << " изображений" << std::endl;
    ids.generaitInLineForm();
    std::cout << "Получена матрица размером " << ids.getInlineMatrix().rows() << ":" << ids.getInlineMatrix().cols() << " содержащая " << ids.getInlineMatrix().size() << " элементов" << std::endl;
    wMatrix wm(ids.getInlineMatrix());
    wm.generaitWMatrix();
    std::cout << "получена матрица размером" << wm.rows() << ":" << wm.cols() << " содержащая " << wm.size() << " элементов" << std::endl;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 200; j++) {
            std::cout << wm.at(i, j) << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
