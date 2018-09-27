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
    // запускаем поиск в папке
    dataSet ds(argv[1]);
    // загружаем все изображения из папки
    imageDataSet ids(argv[1], ds);
    std::cout << "загружено " << ids.getImageSet().size() << " изображений" << std::endl;
    // генерируем матрицу
    ids.generaitInLineForm();
    std::cout << "Получена матрица размером " << ids.getInlineMatrix().rows() << ":" << ids.getInlineMatrix().cols() << " содержащая " << ids.getInlineMatrix().size() << " элементов" << std::endl;
    // готовим w матрицу
    wMatrix wm(ids.getInlineMatrix());
    // создаём w матрицу
    wm.generaitWMatrix();
    std::cout << "получена матрица размером" << wm.rows() << ":" << wm.cols() << " содержащая " << wm.size() << " элементов" << std::endl;
    // готовим зашумленный сигнал
    distortedSignal dSignal(argv[2]);
    // зашумляем сигнал
    dSignal.toDistortTheSignal();
    // измлекаем матрицу для удобства
    matrix xm = ids.getInlineMatrix();
    // создаём объект сети передаём туда всё необходимое
    neuronet nt(xm, wm, dSignal);
    // запускаем матрицу в работу
     nt.ranNV();
    nt.exportresult(argv[3]);
    int index = nt.ToDetermineTheNumberOfClassImage();
    if (index >= 0) {
        std::cout << "Искомое изображение " << ds.getFileList()[index] << std::endl;
    }
    return 0;
}
