//
//  neuronet.cpp
//  hopfield network
//
//  Created by Артём Семёнов on 22/09/2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#include "neuronet.hpp"

neuronet::neuronet(matrix xMat, wMatrix wMat, distortedSignal dSignal) {
    // затаскиваем в себя значения
    xm = xMat;
    wm = wMat;
    ds = dSignal;
}

std::vector<double> neuronet::activation(std::vector<double> y_prev) {
    // вектор, который будет возвращён
    std::vector<double> y_t;
    // выделяем память
    y_t.resize(y_prev.size());
    // обходим матрицу
    for (int i = 0; i < wm.rows(); i++) {
        for (int j = 0; j < wm.cols(); j++) {
                y_t[i] += wm.at(i, j) * y_prev[j]; // вычисляем значения вектора
        }
    }
    return y_t;
}

int neuronet::ToObtainThePercentageOfMatches(std::vector<double> y_prev, std::vector<double> y_t) {
    // переводим векторы double в биполярные векторы
    int coincidences = 0;
    std::vector<int> v1 = convertToBiPolarVector(y_prev);
    std::vector<int> v2 = convertToBiPolarVector(y_t);
    for (int i = 0; i < y_prev.size(); i++) { // проходим вдоль векторов
        coincidences = v1[i] == v2[i]? coincidences++: coincidences; // считаем совпадения
    }
    return coincidences * 100 / y_t.size(); // возвращаем в процентах
}

std::vector<int> neuronet::convertToBiPolarVector(std::vector<double> vec) {
    std::vector<int> res;
    res.resize(vec.size());
    for (int i = 0; i < vec.size(); i++) { // обходим вектор
        if (vec[i] > 0) { // если значение положительно?
            res[i] = 1; // записываем единицу
        } else if (vec[i] < 0) { // если отрицательное
            res[i] = -1; // записываем -1
        } else res[i] = 0; // иначе ноль
    }
    return res;
}

void neuronet::ranNV() {
    // объявляем вектора
    std::vector<double> y_t;
    y_t.resize(ds.data().size());
    std::vector<double> y_prev;
    y_prev.resize(y_t.size());
    // поскольку искажённое изображение прибывает в int грубо переписываем его в double
    for (int i = 0; i < y_prev.size(); i++) {
        y_prev[i] = ds.data()[i];
    }
    while (ToObtainThePercentageOfMatches(y_prev, y_t) <= 90) { // пока количество совпадений не дойдёт до 90
        y_prev = y_t; // записываем предыдущее состояние.
        y_t = activation(y_prev); // перезапускаем функцию активации
    }
    resultVector = convertToBiPolarVector(y_t);
}

void neuronet::exportresult(std::string dirPath) { 
    cv::Mat img(xm.rows(), xm.cols(), CV_8UC1);
    // заполняем матрицу изображения
    for (int i = 0; i < img.rows * img.cols; i++) {
        if (xm.data()[i] > 0) {
            img.at<uchar>(i) = 255;
        } else if (xm.data()[i] < 0) {
            img.at<uchar>(i) = 0;
        } else {
            img.at<uchar>(i) = 128;
        }
    }
    dirPath = dirPath + "result.jpg"; // дополняем полученный путь именем файла
    cv::imwrite(dirPath, img); // пишем файл на диск
}
