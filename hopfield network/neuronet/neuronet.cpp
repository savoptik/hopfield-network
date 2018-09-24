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

std::vector<double> neuronet::activation(std::vector<int> y_prev) {
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

int neuronet::ToObtainThePercentageOfMatches(std::vector<int> y_prev, std::vector<int> y_t) {
    int coincidences = 0;
    for (int i = 0; i < y_prev.size(); i++) { // проходим вдоль векторов
        coincidences = y_t[i] == y_prev[i]? coincidences+1: coincidences; // считаем совпадения
    }
    int res = coincidences * 100 / y_t.size();
    std::cout << "Процент совпадений " << res << std::endl;
    return res; // возвращаем в процентах
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
    std::vector<int> y_t;
    y_t.resize(ds.data().size());
    std::vector<int> y_prev = ds.data();
    int nI = 0;
    while (ToObtainThePercentageOfMatches(y_prev, y_t) <= 90) { // пока количество совпадений не дойдёт до 90
        y_prev = y_t; // записываем предыдущее состояние.
        y_t = convertToBiPolarVector(activation(y_prev)); // перезапускаем функцию активации
        nI++;
    }
    std::cout << "Количество итераций: " << nI << std::endl;
    resultVector = y_t;
}

void neuronet::exportresult(std::string dirPath) { 
    cv::Mat img(10, 10, CV_8UC1);
    // заполняем матрицу изображения
    for (int i = 0; i < img.rows * img.cols; i++) {
        if (xm.data()[i] > 0) {
            img.at<uchar>(i) = 1;
        } else if (xm.data()[i] < 0) {
            img.at<uchar>(i) = 255;
        } else {
            img.at<uchar>(i) = 128;
        }
    }
    dirPath = dirPath + "result.jpg"; // дополняем полученный путь именем файла
    cv::imwrite(dirPath, img); // пишем файл на диск
}

void neuronet::outWM(int i, int j) { 
    for (int r = 0; r < i; r++) {
        for (int c = 0; c < j; c++) {
            std::cout << wm.at(r, c) << " ";
        }
        std::cout << std::endl;
    }
    
}

