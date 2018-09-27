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
    neuronet(matrix& xMat, wMatrix& wMat, distortedSignal& dSignal); // конструктор перепишет внутрь себя полученные данные и освободит память.
    /**
     Запуск работы нейросети.
     */
    void ranNV(); // выполнить восстановление
    /**
     метод пишет получившееся изображение на диск

     @param dirPath путь к папке с результатами
     */
    void exportresult(std::string dirPath);
    /**
     выводит матрицу W до зададнных границ

     @param i Количество выводимых строк
     @param j Количество выводимых столбцов
     */
    void outWM(int i, int j);
private:
    matrix xm; // x матрица
    wMatrix wm; // w Матрица
    distortedSignal ds; // искажённый сигнал.
    std::vector<int> resultVector; // результирующий вектор.
    void prod(std::vector<int>& y_prev, std::vector<double>& y_t);
    int ToObtainThePercentageOfMatches(std::vector<int>& y_prev, std::vector<int>& y_t);
    void activation(std::vector<double>& vec, std::vector<int>& outVec);
    void copyLToR(std::vector<int>& v1, std::vector<int>& v2);
};

#endif /* neuronet_hpp */
