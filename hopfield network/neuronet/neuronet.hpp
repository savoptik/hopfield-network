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
    neuronet(matrix xMat, wMatrix wMat, distortedSignal dSignal); // конструктор перепишет внутрь себя полученные данные и освободит память.
    /**
     Запуск работы нейросети.
     */
    void ranNV(); // выполнить восстановление
    /**
     метод пишет получившееся изображение на диск

     @param dirPath путь к папке с результатами
     */
    void exportresult(std::string dirPath);
private:
    matrix xm; // x матрица
    wMatrix wm; // w Матрица
    distortedSignal ds; // искажённый сигнал.
    std::vector<int> resultVector; // результирующий вектор.
    /**
     функция активации выполняет поиск yt

     @param y_prev y_t-1
     @return y_t
     */
    std::vector<double> activation(std::vector<double> y_prev);
    /**
     Метод получает два вектора и вычисляет процент совпадений.

     @param y_prev значение y на предыдущей итерации
     @param y_t значение y на текущей итерации
     @return процент совпадений.
     */
    int ToObtainThePercentageOfMatches(std::vector<double> y_prev, std::vector<double> y_t);
    /**
     метод превращае вектор даблов в вектор с биполярными значениями.

     @param vec вектор даблов
     @return биполярный вектор.
     */
    std::vector<int> convertToBiPolarVector(std::vector<double> vec);
};

#endif /* neuronet_hpp */
